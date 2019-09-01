# 可变参数宏解析
```
/*32bit system*/
typedef s32 acpi_native_int;

/* Storage alignment properties */
#define  _AUPBND                (sizeof (acpi_native_int) - 1)
#define  _ADNBND                (sizeof (acpi_native_int) - 1)

/* Variable argument list macro definitions */
#define _bnd(X, bnd)            (((sizeof (X)) + (bnd)) & (~(bnd)))
#define va_arg(ap, T)           (*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND))))
#define va_end(ap)              (ap = (va_list) NULL)
#define va_start(ap, A)         (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))))
```
- 该宏位于stdarg.h中，定义了可变参数的地址；
- 可变参数是充分利用在函数传参时，会将参数依次压入堆栈，然后根据堆栈的特点，访问可变参数；
- 以32位系统为例，\_AUPBND和_ADNBND表示系统的对齐方式，在32位系统中为**3**；
- _bnd(X, bnd)是要求出X在堆栈中占的内存大小，注意是内存对齐以后的大小；
- va_arg(ap, T)有两个作用，第一：返回当前可变参数的地址；第二：将ap指针向后移动到指向第二个可变参数；
- va_end(ap)表示将ap赋空，防止出现野指针；
- va_start(ap, A)表示将ap指向第一个可变参数；
- 在看这几个宏的时候，尤其有点不理解va_arg，觉得将ap先加一个值，再减去一个相等的值，不是没变化吗？可是在实际写了个小函数测试时才发现“+=”符号的妙用，第一次赋值是移动指针ap的位置，第二次减去相同的值时并未改变指针ap的指向，返回的值表示的时表达式的值，还是原来ap的指向。

# errno全局变量使用说明
- C语言中为防止和正常的返回值混淆，系统调用一般并不直接返回错误码，而是将错误码（一个整数值，不同的值代表不同的涵义）存入一个名为errno的全局变量中，errno不同数值所代表的错误消息定义在<errno.h>中。如果一个系统调用或库函数调用失败，可以通过errno的值来判断出错的原因，便于定位问题。
- 配合perror和strerror函数，可以很方便查看出错详细信息：
	- perror在<stdio.h>中定义，用于错误码及其消息描述；
	- strerror在<string.h>中定义，用于获取错误码及其对应消息描述；
- 注意：并不是所有的库函数调用都会使用errno全局变量标识错误；
- 在Linux中将errno声明为 static int errno，所以在使用之前要先清零；
- 例子：
```
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fileId;
	fileId = open("a.txt", O_RDONLY);
	printf("errno: %d, 错误信息：%s\n", errno, strerror(errno));
	
	return 0;
}

/*运行输出*/
yanjy@ubuntu:/mnt/hgfs/ubuntu_share/examples$ ./a.out 
errno: 2, 错误信息：No such file or directory
yanjy@ubuntu:/mnt/hgfs/ubuntu_share/examples$ 
```

# 系统调用/库函数
- 2019/6/2
- 无论何时，只要执行了系统调用或者库函数，检查调用的返回状态以确定调用是否成功，这是一条编程铁律。
- 系统调用
	- 系统调用是受控的内核入口，借助与这一机制，进程可以请求以自己的名义去执行某些动作。以应用程序编程接口（API）的形式，内核提供一系列服务供程序访问。包括创建新进程、执行I/O，以及为进程间通信创建管道等。
	- 系统调用将处理器从用户态切换到内核态，以便CPU访问受到保护的内核内存。
	- 系统调用的组成是固定的，每个系统调用都由唯一的数字来标识。（用户程序通过名称来标识系统调用，对这一编号方案往往一无所知。）
	- 每个系统调用可传递参数，对用户空间和内核空间传递的信息加以规范。
	- 系统调用过程：
		- 应用程序首先调用C语言中的函数库中的外壳（wrapper）函数发起系统调用；
		- 对系统调用中断处理例程来说，外壳函数必须保证所有的系统调用参数可用，用户程序通过堆栈将参数传给外壳函数，外壳函数将这些参数复制到特定寄存器；
		- 由于所有系统调用进入内核方式相同，内核要区分每个系统调用。所以外壳函数会将该系统调用的编号复制到一个特殊的寄存器（%eax)中；
		- 外壳函数执行一条中断机器指令（int 0x80，新的硬件平台能实现sysenter指令，较int 0x80进入内核速度更快），引发处理器从用户态切换到内核态；
		- 内核会执行system_call()函数响应中断0x80，该函数执行过程和普通中断执行过程类似。先保存现场，审核系统调用编号的有效性，执行系统调用中断服务函数（该函数检查参数，返回执行结果），恢复现场，返回外壳函数（即由内核态返回到用户态）；
		- 外壳函数检查返回值，若返回错误，外壳函数会设置errno的值，最后将返回值返回给用户。
- 库函数
	- 许多库函数不会使用任何系统调用；
	- 一些库函数是构建在系统调用基础之上；
	- 设计库函数是为了提供比底层系统调用更为方便的调用接口，并增加一些额外的工作。比如print()函数可提供格式化输出和缓存功能，而write()系统调用只能输出字节块。
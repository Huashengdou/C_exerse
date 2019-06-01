
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
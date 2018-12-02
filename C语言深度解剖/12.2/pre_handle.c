#include <stdio.h>
#define N 1
int main(int argc, char const *argv[])
{
	int a = 3;
	//不能在预处理的后面使用变量表达式,也不能是sizeof
	#if(a)
		printf("Hello world!\n");
	#endif
	#pragma message("hello hahha\n")
	#if(N)
		printf("Hello git!\n");
	#endif
	return 0;
}
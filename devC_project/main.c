/*堆栈练习题*/
/*在不传递参数的情况下，在print函数中打印出main函数中数组的元素*/
#include <stdio.h>
#include "print.h"
void printt()
{
	unsigned int _ebp;

	/*__asm(
		"mov _ebp,ebp"
	);*/
	__asm__ __volatile__ ("movl %%ebp, %0":"=a"(_ebp));
	int *p = NULL;
	p = (int *)(*(int *)_ebp-4-4-4-7*4-8);
	int i;
	for (i = 0; i<7; i++)
	{
		printf("%d\t", p[i]);
	}
	return;
}
int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 2;
	char c = 'c';
	int arr[] = {11,12,13,14,15,16,17};

	printt();
	print();
//	printf("sizeof(int)%d\n",sizeof(long long));
	return 0;
}

/*堆栈练习题*/
/*在不传递参数的情况下，在print函数中打印出main函数中数组的元素*/
#include <stdio.h>

void print()
{
	 int _ebp = 0;
	int i;
	__asm(
		"movl %ebp,_ebp"
	);
	int *p = NULL;
	p = (int *)((void *)_ebp-4-4-4-7*4);
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

	print();
	return 0;
}
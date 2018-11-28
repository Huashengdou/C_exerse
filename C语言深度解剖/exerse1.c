#include <stdio.h>

static int j;
int b[100];
void fun1(void)
{
	static int i = 0;
	i++;
}
void fun2(void)
{
	j = 0;
	j++;
}
void fun3(int b[])
{
	printf("---------%d\n", sizeof(b));
}
int main(int argc, char const *argv[])
{
	int m = 9;
	int * p = NULL;
	p = &m;
	printf("%d, %d\n", m, *p);

	int i = 0;
	for ( i = 0; i < 10; ++i)
	{
		fun1();

		fun2();
	}
	fun3(b);
	printf("%d\n", j);
	int a[100];
	printf("int: %u\n", sizeof(a));
	printf("short:%d\n", sizeof(short));
	printf("long:%d\n", sizeof(long));
	printf("char:%d\n", sizeof(char));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
	
	return 0;
}
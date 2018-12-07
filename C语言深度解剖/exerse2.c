#include <stdio.h>
#include <string.h>
int n = 9;
int main(int argc, char const *argv[])
{
	char a[1000] = "hello";
	int i;
	int b[n];
	n = 10;

	printf("b[9] = %d\n", b[11]);
	printf("%d\n",strlen(a));
	for ( i = 0; i < 1000; ++i)
	{
		a[i] = -1-i;
	}
	printf("%d\n", strlen(a));
	return 0;
}
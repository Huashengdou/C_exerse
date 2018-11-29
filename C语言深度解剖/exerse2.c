#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char a[1000] = "hello";
	int i;
	printf("%d\n",strlen(a));
	for ( i = 0; i < 1000; ++i)
	{
		a[i] = -1-i;
	}
	printf("%d\n", strlen(a));
	return 0;
}
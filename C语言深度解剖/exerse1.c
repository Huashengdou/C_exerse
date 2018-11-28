#include <stdio.h>

int main(int argc, char const *argv[])
{
	register int i = 9;
	int * p = NULL;
	p = &i;
	printf("%d, %d\n", i, *p);
	return 0;
}
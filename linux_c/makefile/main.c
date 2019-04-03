#include <stdio.h>
#include "add_num.h"

int main(void)
{
	int i = 1, j = 2;
	int a = add_num(i,j);
	printf("result = %d\n",a);
	return 0;
}

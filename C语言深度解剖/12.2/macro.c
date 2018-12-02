#include <stdio.h>

#define return_exam(p) if(!(p))\
			{\
				printf("error: "#p" file_name:%s\t function_name:%s\tline:%d.\n",\
						__FILE__,__func__,__LINE__ );\
				return 0;\
			}

int print()
{
	return_exam(0)
}
int main(int argc, char const *argv[])
{
	print();
	printf("hello\n");
	return 0;
}
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int arr[4][4] = {
						1,2,3,4,
						5,6,7,8,
						9,10,11,12,
						13,14,15,16
					};
	/*数组指针*/
	int (*p1)[4];
	/*指针数组*/
	int *p2[4];
	int i,j,k;
	/*将二维数组的地址赋给指向四个元素的数组指针*/
	p1 = arr;
	printf("使用数组指针的方式访问二维数组arr\n");
	
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			printf("arr[%d][%d] = %d\t\n", i, j, *(*(p1+i)+j));
		}
		printf("\n");
	}

	printf("\n使用指针数组方式访问二维数组arr:\n");
	for (i=0; i<4; ++i)
	{
		p2[i] = arr[i];
	}
	for (k=0; k<4; ++k)
	{
		for (j=0; j<4; ++j)
		{
			printf("arr[%d][%d] = %d\t\n", i, j, *(p2[k]+j));
		}
		printf("\n");
	}
	return 0;
}

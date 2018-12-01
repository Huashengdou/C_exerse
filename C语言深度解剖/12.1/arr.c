#include <stdio.h>
int main()
{
	int i = 0;
	int arr[][4] = {
                    0,1,2,3,
                    4,5,6,7,
                    8,9,10,11,
                    12,13,14,15
                };
    for(i=0; i<4; i++)
    {
        printf("i = %d:\n",i);
        printf("arr+%d = %x\n",i,arr+i);
        printf("arr[%d] = %x\n",i, arr[i]);
        printf("*(arr+%d)=%x\n",i,*(arr+i));
        printf("*arr+%d=%x\n",i,*arr+i);
        printf("&arr[%d]=%x\n",i, &arr[i]);
        printf("\n");
    }
	return 0;
}

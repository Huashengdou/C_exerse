#include <stdio.h>
#include <sys/time.h>

int main(int argc, char const *argv[])
{
	struct timeval start, end;
	//程序起始时间
	gettimeofday(&start, NULL);
	double timeuse;
	double sum;
	int i,k;
	for (i = 0; i < 1000000000; ++i)
	{
		for (k=0; k<10; k++)
		{
			sum += 1.0;
		}
	}
	gettimeofday(&end, NULL);
	timeuse = 1000000*(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	timeuse /= 1000000;
	printf("运行时间为：%f\n", timeuse);
	return 0;
}
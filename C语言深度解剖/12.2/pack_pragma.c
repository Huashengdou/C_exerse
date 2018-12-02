#include <stdio.h>

int main(int argc, char const *argv[])
{
	#pragma pack(push)
	#pragma pack(2)
	struct _stu1
	{
		char name[20];
		char num[10];
		int score;
		char sex;
	}stu1;
	printf("sizeof(stu1) = %d\n",sizeof(stu1));

	#pragma pack(pop)
	struct _stu2
	{
		char name[20];
		char num[10];
		int score;
		char sex;
	}stu2;
	printf("sizeof(stu2) = %d\n",sizeof(stu2));
	return 0;
}
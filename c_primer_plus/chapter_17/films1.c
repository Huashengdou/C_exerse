/*使用一个结构数组保存电影名称和评级*/

#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);
/*影片名字长度*/
#define TESIZE	45
/*影片的最大数量*/
#define FMAX	5

/*用于保存电影信息的结构*/
struct film
{
	char title[TESIZE];
	int rating;
};

int main(int argc, char const *argv[])
{
	struct film movies[FMAX];
	int i = 0;

	/*puts()函数是将字符串放到标准输出流-stdout，并在最后增加换行符*/
	puts("Enter first film name:");
	while(i<FMAX && s_gets(movies[i].title, TESIZE) != NULL && movies[i].title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &movies[i++].rating);
		while(getchar() != '\n')
			continue;
		puts("Enter next movies title (empty line to stop):");
	}

	if (0 == i)
	{
		printf("No data enter!\n");
	}
	else
	{
		printf("Here are the movies list:\n");
	}

	for (int j = 0; j < FMAX; ++j)
	{
		printf("movies title is %s, rating is %d\n", movies[j].title, movies[j].rating );
	}
	printf("Bye\n");
	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');//查找换行符
		if (find)			   //地址不为空，即找到换行符的位置
		{
			*find = '\0';		//将换行符的位置替换为空字符，字符串结尾
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
}
/*使用一个链表结构保存电影名称和评级*/

#include <stdio.h>
#include <stdlib.h>//提供malloc()函数原型
#include <string.h>

char *s_gets(char *st, int n);
/*影片名字长度*/
#define TESIZE	45

/*用于保存电影信息的结构*/
struct film
{
	char title[TESIZE];
	int rating;
	struct film *next;
};

int main(int argc, char const *argv[])
{
	struct film *head = NULL;
	struct film *prev, *current;
	char input[TESIZE];

	puts("Enter first film name:");
	while( s_gets(input, TESIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (!current)
		{
			printf("There is no space!\n");
			return -1;
		}
		if ( NULL == head )
		{
			head = current;
		}
		else
		{
			prev->next = current;//未添加之前，将前一个结点的next赋值为新申请的值
		}

		current->next = NULL;

		strcpy( current->title, input );
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter next movies title (empty line to stop):");
		prev = current;//这个prev永远指向最后一个节点
	}

	if (NULL == head)
	{
		printf("No data enter!\n");
	}
	else
	{
		printf("Here are the movies list:\n");
	}
	/*打印链表*/
	current = head;
	while( current != NULL )
	{
		printf("movies title is %s, rating is %d\n", current->title, current->rating );
		current = current->next;
	}
	/*释放链表*/
	current = head;
	/*书中为判断current是否为空，因为执行第一次的时候已经将current释放，再次判断current的时候，current将指向非法地址*
	*程序报错*/
	//while(current != NULL)
	while(head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}

	printf("Bye!!\n");
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
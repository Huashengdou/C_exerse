#include <stdio.h>
#include <getopt.h>

/*
*struct option
{
	//选项的长名称
	const char *name;
	//该选项是否具有附加参数，0：无；1：有；2：可选
	int has_arg;
	//指向整数，用于保存val值，设为0
	int *flag;
	//选项的短名称
	int val;
}
*
*/
static void usage(void)
{
	fprintf(stdout,
		"  -v, --vrid vrid           Virtual router identifier\n"
		"  -i, --interface iface     Interface\n"
		"  -p, --priority prio       Priority of VRRP Instance, (0-255, default 100)\n"
	);
	
}

int main(int argc, char const *argv[])
{
	
	int optc;
	unsigned long opt;	/* strtoul */

	static struct option const opts[] = {
		{"vrid", 1, NULL, 'v'},
		{"interface", 1, NULL, 'i'},
		{"priority", 0, NULL, 'p'},
		{NULL, 0, NULL, 0}
	};
/*返回参数的短选项名称，不存在时返回-1
* 处理附加参数时，optarg传递其地址*/
	while ((optc =
		getopt_long(argc, argv,"v:i:p", opts, NULL)) != -1) 
	{
		switch (optc) 
		{
			case 'v':
				printf("第一个参数'短v'或者'长vrid',全局变量：%s\n", optarg);
				break;

			case 'i':
				printf("第二个参数'短i'或者'长interface',全局变量：%s\n", optarg);
				break;

			case 'p':
			/*因为p未生命为带参数，所以optarg一直为NULL*/
				printf("第三个参数'短p'或者'长priority',全局变量：%s\n", optarg);
				break;

			default:
				printf("optc is %c\n", optc);
				usage();
				return -1;
				break;
		}
	}

	return 0;
}


#if 0
int main(int argc, char *const argv[])
{
	int ch;
	while((ch = getopt(argc, argv,"a:bcde")) != -1)
	{
		switch(ch)
		{
			case 'a':
				printf("option a: %s\n", optarg );
			break;
			case 'b':
				printf("option b:\n");
			break;

			case 'c':
				printf("option C\n");
			break;

			default:
				printf("other option %c\n", ch);
		}
		printf("opt +%c\n", ch);
	}
	return 0;
}
#endif
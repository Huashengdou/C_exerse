#include <stdio.h>
#include <getopt.h>

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
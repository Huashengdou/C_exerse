#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handing(char *message);

int main(int argc, char const *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;

	if (3 != argc)
	{
		printf("Usage : %s <IP><port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == sock)
	{
		error_handing("sock() error");
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		error_handing("connect() error!");
	}

	str_len = read(sock, message, sizeof(message) - 1);
	if (-1 == str_len)
	{
		error_handing("read() error!");
	}
	printf("message from server : %s\n", message );
	close(sock);
	return 0;
}

void error_handing(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
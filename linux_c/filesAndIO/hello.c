#include <unistd.h>

char msg[14] = "Hello world!\n";
#define LEN 14

int main(void)
{
	write(1, msg, LEN);
	_exit(0);
}

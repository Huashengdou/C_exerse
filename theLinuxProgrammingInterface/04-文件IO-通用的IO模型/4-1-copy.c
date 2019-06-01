
/*
** 实现将源文件内容复制到新文件中
** ./4-1-copy oldfile newfile
** 将oldfile内容复制到newfile中
*/

/*获取有关文件状态的函数*/
#include <sys/stat.h>
/*包含文件操作的函数*/
#include <fcntl.h>
/*包含书中提供的头文件（该同文件包含一些标准操作）*/
#include "../lib/tlpi_hdr.h"

/*定义缓存区大小*/
#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char const *argv[])
{
	int inputFd, outputFd, openFlags;//文件描述符，文件描述符，打开文件标志
	mode_t filePerms;//文件权限，创建文件时使用；底层为unsigned int类型
	ssize_t numRead;//读取文件长度
	char buf[BUF_SIZE];//缓存

	if (argc != 3 || strcmp(argv[1], "--help") == 0)
	{
		usageErr("%s old-file new-file\n", argv[0]);
	}

	/*打开源文件*/
	inputFd = open(argv[1], O_RDONLY);
	if (-1 == inputFd)
	{
		errExit("opening file %s", argv[1]);
	}

	/*打开文件的主标志：O_RDONLY只读；O_RDWR可读可写；O_WRONLY只写*/
	/*打开文件的副标志：O_APPEND，读写文件从文件尾部开始移动，所写入的数据追加到文件尾部*/
	/*O_TRUNC，若文件存在并且以可写方式打开时，此标志会将文件长度清0，原有数据消失*/
	/*O_CREAT，若路径中的文件不存在则自动建立该文件*/
	/*O_EXCL，如果与O_CREAT同时设置，此标志会是能检查文件是否存在，文件不存在则建立文件
	**否则将导致打开文件错误。若同时设置打开的时文件为符号链接文件，则将导致打开文件失败*/
	/*主标志之间是互斥的，可配合使用副标志*/
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	/*文件权限标志：S_IRUSR，所有者拥有读权限；
	*S_IWUSR，所有者拥有写权限；
	*S_IXUSR，所有者拥有执行权限；
	*S_IRGRP，群组拥有读权限；
	*S_IWGRP，群组拥有写权限；
	*S_IXGRP，群组拥有执行权限；
	*S_IROTH，其他用户拥有读权限；
	*S_IWOTH，其他用户拥有写权限；
	*S_IXOTH，其他用户拥有执行权限；
	*正好就是Linux中指定的文件权限
	*/
	/*文件权限：rw-rw-rw-*/
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |\
				S_IROTH | S_IWOTH;

	/*打开或创建要写入的文件*/
	outputFd = open(argv[2], openFlags, filePerms);
	if (-1 == outputFd)
	{
		errExit("opening file %s", argv[2]);
	}

	/*将源文件的内容读到缓存，然后写入目标文件*/
	while((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
	{
		if (write(outputFd, buf, numRead) != numRead)
		{
			fatal("could't write whole buffer");
		}
	}

	if (numRead == -1)
	{
		errExit("read");
	}

	if (close(inputFd) == -1)
	{
		errExit("close input");
	}
	if (close(outputFd) == -1)
	{
		errExit("close output");
	}

	exit(EXIT_SUCCESS);
	//return 0;
}

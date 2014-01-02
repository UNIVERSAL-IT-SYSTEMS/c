#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
/*
1.两个进程之间，文件描述符号指向的是同一个文件内存对象
2.进程的数据交换，基于两种方式：
	内存：有序(消息队列)/无序(共享内存)：mmap
	文件：有序(管道文件socket文件)/无序(普通文件) open("",O_RDWR);
*/

main()
{

	if(fork())
	{

	}
	else
	{
	
	}
}
/*
1.dup dup2 拷贝文件描述符合
  dup拷贝文件符号，返回系统指定的整数
  dup2拷贝文件描述符号，返回用户指定的整数
2.fcntl对文件描述的属性的修改
	2.1拷贝文件描述符号
	2.2修改判定文件的描述标记
	2.3修改判定文件的状态标记
		不可改变
		O_RDONLY O_WRONLY O_RDWR O_CREAT O_EXCL
		可改变
		O_APPEND O_ASYN
		
	2.4设置强制锁(重新编译内核)
	2.5设置建议锁(默认),加了锁别人也能访问，别人只是能判定
	2.6设置的信号
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	if(fork())
	{
		struct flock lk;
		int fd=open("a.txt",O_RDWR);	
		if(fd==-1)printf("open error:%m\n"),exit(-1);
		
	}
	else
	{
	}	
}

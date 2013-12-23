#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
main()
{
	printf("caller's pid:%d\n",getpid());
	FILE *f=popen("./callee","r");
	int fd=fileno(f);//转换为文件描述符；
	printf("fd:%d\n",fd);
	char buf[1025];
	int r=0;
	while((r=read(fd,buf,1024))>0)
	{
		buf[r]=0;
		printf("%s",buf);
	}
	close(fd);
	pclose(f);
}

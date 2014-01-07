#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
int fd;
void end(int s)
{
	close(fd);
	printf("sdsdf");
	// unlink("/tmp/my.pipe");
	exit(1);
	
}
main()
{
	int i;
	signal(SIGPIPE,end);
	// mkfifo("/tmp/my.pipe",0666);
	fd=open("/tmp/my.pipe",O_WRONLY);
	if(fd==-1)printf("open error:%m"),exit(-1);
	while(1)
	{
		sleep(1);
		int r =write(fd,&i,4);
		printf("r:%d\n",r);
		i++;
	}
	while(1);
	
}
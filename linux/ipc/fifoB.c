#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
int fd;
void end(int s)
{
	close(fd);
	exit(1);
}
main()
{
	int i=0;
	signal(SIGINT,end);
	fd=open("/tmp/my.pipe",O_RDONLY);
	if(fd==-1)printf("open error:%m"),exit(-1);
	while(1)
	{
		read(fd,&i,4);
		printf("%d\n",i);
	}

}
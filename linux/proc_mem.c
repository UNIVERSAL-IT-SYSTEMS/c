#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int a=9999;
main()
{
	char str[100]={0};
	int data=888;
	sprintf(str,"/proc/%d/mem",getpid());
	int fd=open(str,O_RDWR);
	if(fd==-1)printf("open error:%m\n"),exit(-1);
	//pread(fd,&data,4,(off_t)&a);
	// lseek(fd,(off_t)&a,SEEK_SET);
	// write(fd,&data,4);
	pwrite(fd,&data,4,(off_t)&a);
	printf("%d\n",a);
	//printf("%d\n",data);
	
	
	close(fd);
	
}
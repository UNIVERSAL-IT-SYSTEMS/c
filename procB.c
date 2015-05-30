#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
main()
{
	//int *p;
	int fd;	
	fd=open("/tmp/t",O_RDWR);	
	//p=mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	int a;
	while(1)
	{
		sleep(1);
		pread(fd,&a,sizeof(int),0);
		printf("%d\n",a);
	}
	close(fd);
}

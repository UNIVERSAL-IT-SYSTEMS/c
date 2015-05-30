#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
main()
{
	char *p;
	int fd;
	fd=open("/tmp/t",O_RDWR|O_CREAT,0666);
	printf("%m");
	ftruncate(fd,1024);
	printf("%m");
	p=mmap(0,1024,PROT_READ|PROT_WRITE,
			MAP_SHARED,fd,0);		
	printf("%m");
	scanf("%s",p);
	munmap(p,1);
	close(fd);
}

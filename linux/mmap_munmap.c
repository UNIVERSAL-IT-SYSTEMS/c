#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
/*
void *mmap(void *addr, size_t length, 
			int prot, int flags,
            int fd, off_t offset);
void *mmap64(void *addr, size_t length, 
				int prot, int flags,
                int fd, off64_t offset);
int munmap(void *addr, size_t length);
*/
main()
{
	int *p=mmap(
		NULL,
		getpagesize(),
		PROT_READ|PROT_WRITE,
		MAP_ANONYMOUS|MAP_SHARED,
		0,0);
	*p=20;
	*(p+1)=30;
	*(p+2)=40;
	printf("%d\n",p[2]);
	munmap(p,4096);
}
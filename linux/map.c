#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
int main()
{
	int *p=mmap(NULL,
	getpagesize(),
	PROT_WRITE|PROT_READ,
	MAP_ANONYMOUS|MAP_SHARED,
	0,0);
	*p=20;
	*(p+1)=30;
	*(p+2)=40;
	printf("%d\n",p[2]);
	return 0;
}

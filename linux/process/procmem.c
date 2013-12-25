#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/mman.h>
main()
{
	
	int *a=mmap(0,4,PROT_READ|PROT_WRITE,
			MAP_ANONYMOUS|MAP_SHARED,0,0);
			
	//int *a=sbrk(4);		
	*a=40;	
	if(fork())
	{
		printf("parent:%d\n",*a);
		*a=90;
	}
	else
	{
		printf("child:%d\n",*a);
		sleep(3);
		printf("child:%d",*a);		
	}
	
}

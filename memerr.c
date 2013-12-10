#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	void *p=sbrk(1000000000000000L);
	if(p==(void*)-1)
	{
		perror("Hello:");
		printf("Memory:%m\n");
		printf("::%s\n",strerror(errno));
	}
}

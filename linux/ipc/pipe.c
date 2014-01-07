#include <stdio.h>
#include <unistd.h>

main()
{
	int fd[2];
	int r;
	char buf[20];
	r=pipe(fd);
	write(fd[1],"hello",5);
	write(fd[1],"world",5);
	r=read(fd[0],buf,20);
	buf[r]=0;
	printf("%s\n",buf);
}
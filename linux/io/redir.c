#include <stdio.h>
#include <fcntl.h>
/*isatty*/
main()
{
	int fd;
	printf("HEllo\n");
	fflush(stdout);
	write(1,"world\n",6);
	fd=open("/dev/tty",O_WRONLY);//防止重定向
	if(isatty(1))//判断输出是否被重定向
	{
		write(1,"not redir\n",10);
	}
	else
	{
		write(1,"redir\n",6);
	}
	write(fd,"killer\n",7);
}
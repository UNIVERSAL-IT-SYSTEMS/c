#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

main()
{
	int r=execl("ls","-l",NULL);
	printf("结束：%d\n",r);
}

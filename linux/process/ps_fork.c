#include <unistd.h>
#include <stdio.h>
main()
{
	pid_t pid;
	printf("创建进程前：%d\n",getpid());
	pid=fork();
	if(pid==0)
	{
		while(1)
		{
			printf("<<<<<<<<<<<<");
			printf("子进程：%d ",getpid());
			printf("子进程的父进程：%d\n",getppid());
			sleep(1);
		}
	}
	else
	{
		while(1)
		{
			printf(">>>>>>>>>>>>>>>>>>>>>");
			printf("父进程：%d ",getpid());
			printf("父进程的子进程：%d ",pid);
			printf("父进程的父进程：%d\n",getppid());
			sleep(1);
		}
	}
}

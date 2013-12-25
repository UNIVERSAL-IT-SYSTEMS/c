#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/*
1.父子两个进程独立。
2.通过fd文件发现共享同一个终端。
3.通过pstree看出两个进程挂在进程树上的情况。
4.父进程先结束，子进程挂到根进程（init），称为孤儿进程。
5.子进程先结束，子进程依然挂在父进程节点但会称为僵尸进程Z(defunct)。
6.僵尸进程不占用资源，但在进程任务管理树上占用一个节点，会造成进程名额的浪费。
7.子进程结束时会发出信号。用wait回收僵尸进程。<sys/wait.h> pid_t wait(int *status);

*/
main()
{
	if(fork()==0)
	{
		printf("child!\n");
		sleep(20);
		exit(88);
	}
	else
	{	int retstatus;
		printf("parent!\n");
		pid_t id =wait(&retstatus);
		
		printf("回收完毕!子进程：%d 退出码：%d",id,WEXITSTATUS(retstatus));
		sleep(200);
	}
}
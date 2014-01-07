#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/shm.h>
int *p;
void handle(int s)
{
	// 4卸载共享内存shmdt
	shmdt(p);
	exit(1);
}
main()
{
	signal(SIGINT,handle);
	// 1创建共享内存shmget
	key_t key=ftok(".",255);
	if(key==-1)printf("ftok error:%m\n"),exit(-1);
	int shmid=shmget(key,4,0);
	if(shmid==-1)printf("shget error:%m\n"),exit(-1);
	// 2挂载共享内存到虚拟内存shmat
	int *p=(int *)shmat(shmid,0,0);
	if(p==(int*)-1) printf("shmat error:%m"),exit(-1);
	// 3访问共享内存
	while(1)
	{
		sleep(1);
		printf("%d\n",*p);
	}
	// 4卸载共享内存shmdt
	shmdt(p);
}
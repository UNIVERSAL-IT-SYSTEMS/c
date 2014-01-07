#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/shm.h>
int shmid;
int *p;
void handle(int s)
{
	// 4卸载共享内存shmdt
	shmdt(p);
	// 5删除共享内存shctl
	shmctl(shmid,IPC_RMID,NULL);
	exit(1);
}
main()
{
	signal(SIGINT,handle);
	// 1创建共享内存shmget
	key_t key=ftok(".",255);
	if(key==-1)printf("ftok error:%m\n"),exit(-1);
	shmid=shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
	if(shmid==-1)printf("shget error:%m\n"),exit(-1);
	// 2挂载共享内存到虚拟内存shmat
	p=(int *)shmat(shmid,0,0);
	if(p==(int*)-1) printf("shmat error:%m"),exit(-1);
	// 3访问共享内存
	int i=0;
	while(1)
	{
		*p=i++;
		sleep(1);
	}

}
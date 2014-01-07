#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct msgbuf
{
	long type;
	char data[32];
};
main()
{
	key_t key;
	int msgid;
	key=ftok(".",200);
	if(key==-1)printf("ftok err:%m\n"),exit(-1);
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(msgid==-1)printf("msgid err:%m\n"),exit(-1);
	int i;
	struct msgbuf msg;
	for(i=0; i<10; i++)
	{
		bzero(msg.data,sizeof(msg.data));
		msg.type=1;
		sprintf(msg.data,"Message:%d",i);
		msgsnd(msgid,&msg,sizeof(msg.data),0);
	}
	for(i=0; i<10; i++)
	{
		bzero(msg.data,sizeof(msg.data));
		msg.type=2;
		sprintf(msg.data,"Message:%d",i);
		msgsnd(msgid,&msg,sizeof(msg.data),0);
	}
}
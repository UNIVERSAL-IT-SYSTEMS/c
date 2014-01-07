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
	msgid=msgget(key,0);
	if(msgid==-1)printf("msgid err:%m\n"),exit(-1);
	struct msgbuf msg;
	int i;
	for(i=0;i<10;i++)
	{
		bzero(msg.data,sizeof(msg.data));
		// msg.type=1;
		msgrcv(msgid,&msg,sizeof(msg.data),1,0);
		printf("%s\n",msg.data);
	}
	for(i=0;i<10;i++)
	{
		bzero(msg.data,sizeof(msg.data));		
		// msg.type=2;
		msgrcv(msgid,&msg,sizeof(msg.data),2,0);
		printf("%s\n",msg.data);
	}
	msgctl(msgid,IPC_RMID,0);
}
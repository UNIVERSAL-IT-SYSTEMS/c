#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("tag\n");//puts无缓冲，不用fflush
	fflush(stdout);
	//int r=execl("/bin/ls","arg0","-l",NULL);
	int r=execlp("ls","lss","-l",(char*)NULL);
	//printf("return:%d\n",r);
	return 0;
}


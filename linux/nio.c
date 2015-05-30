#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <time.h>
char buf[100];
void handle(int s)
{
   int r=read(0,buf,99);
   printf("%s/n",buf);
}
main()
{
    fd_set fds;
    int r;
    FD_ZERO(&fds);
    FD_SET(0,&fds);
    while(1)
    {
        r=select(1,&fds,0,0,0);
        if (r)
        {
           signal(SIGUSR1,handle);
        }
        printf("do other thing!\n");
        sleep(1);
    }
}
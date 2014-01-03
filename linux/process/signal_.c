/*
1.信号的作用
	背景：进程之间通信比较麻烦，但进程之间又必须通信，比如父子之间
	机制：由OS接收到信号后通知其他进程响应(软中断)
	信号处理：接收到信号的进程马上停止。信号处理函数被调用
	信号处理函数：
		默认处理函数：打印信号信息->退出进程
		用户处理函数：
2.信号发送与安装
3.信号的应用
4.信号的可靠与不可靠以及信号的含义
5.信号的操作
6.信号与进程间数据传递
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle(int s)
{
	printf("%d\n",s);
	
	sleep(10);
}
main()
{
	signal(SIGINT,handle);
	while(1)
	{
		printf("running\n");
		sleep(1);
	}
}
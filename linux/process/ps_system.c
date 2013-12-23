/*
D不可中断的睡眠状态
R运行状态
S可中断睡眠状态
T stopped
W换页状态
X死亡状态
Z僵尸状态


<高优先级
N低优先级
L多线程
s会话头，进程组，下面有子进程
+前台


ps 查看进程
top查看系统进程执行状态
pstree(在unix中为ptree) 进程树
kill 向进程发送信号
	kill -s 信号 进程id
	kill -l 显示进程能接受的所有信号
	
创建进程：
1.代码是什么，加载到内存？分配时间片？
代码有独立的程序存在
2.进程有关的创建函数	
a.int system(const char *filename)
	建立独立进程，拥有独立的代码空间，内存空间
	等待新进程执行完毕，system函数才返回（阻塞）
	任何进程的返回值：不要超过255。一个字节。
	system的返回值中8-15位(第二个字节)存放返回码 =》//r=system("ls -l ");
										//printf("%d\n",r>>8&255);
										//#include <sys/wait.h> printf("%d\n",WEXITSTATUS(r));

b.FILE *popen(const char *command, 
				const char *type//"r" or "w"
			 );
  int pclose(FILE *stream);



c.execl系列函数:替换当前进程的代码空间中的代码数据,函数本身不创建新的进程。
int execl(
const char *path, //替换的程序,
const char *arg, 命令行,命令行格式：命令名  选项参数,命令行结尾必须空字符串结尾
...
);
								
int execlp(const char *file, const char *arg, ...)
d.fork
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
main(int argc, char *argv[])
{
	char buf[100];
	sprintf(buf,"ls -l %s",argv[1]);
	int r=system(buf);
	printf("ls' return is %d\n",WEXITSTATUS(r));

}




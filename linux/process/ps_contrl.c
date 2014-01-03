/*
exit(状态吗)返回状态码的意义：
	a.被系统得到。记录日志
	b.system\wait。程序根据返回状态码进行对应处理。
	状态吗的第二个字节才是exit()的返回值或者main函数中的return状态码。
一、进程的基本控制
	1.进程的常见控制函数
		1.1为什么需要控制进程
		1.2pause/sleep/usleep
		1.3 int atexit(void (*function)(void));
			int on_exit(void (*function)(int, void *), void *arg);
	2.进程与文件锁
		在多进程下文件读写时共享的
		问题：
			怎么知道一个文件正在被另一个进程读写？
		解决方案：
			文件锁。（受到内核参数的影响，一般是建议锁，要改成强制锁的话需要重新编译内核）
			int //0加锁成功，-1加锁失败
			fcntl(int fd, 
				int cmd, //锁的操作方式：F_SETLK(加锁，若已经加上锁，马上异常返回),F_GETLK(),F_SETLKW(加锁，若已经加锁，阻塞等待)
				struct flock *lk;//锁的描述
				);
			struct struct flock {
               ...
               short l_type;    // Type of lock: F_RDLCK, F_WRLCK, F_UNLCK 
               short l_whence;  // How to interpret l_start: SEEK_SET, SEEK_CUR, SEEK_END 
               off_t l_start;   // Starting offset for lock 
               off_t l_len;     // Number of bytes to lock 
               pid_t l_pid;     //PID of process blocking our lock (F_GETLK only) 
               ...
           };
	锁也是一个进程可以共享的信息
*/

#include <stdio.h>
#include <stdlib.h>
void fun()
{
	printf("over\n");
}
main()
{
	atexit(fun);
	printf("Processed\n");
}
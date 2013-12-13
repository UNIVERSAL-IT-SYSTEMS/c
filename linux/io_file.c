#include <stdio.h>
#include <unistd.h>

int main()
{
	char command[100];
	sprintf(command,"ls -l /proc/%d/fd",getpid());
	system(command);
	// lrwx------. 1 root root 64 Dec 13 16:18 0 -> /dev/pts/0  输入
	// lrwx------. 1 root root 64 Dec 13 16:18 1 -> /dev/pts/0  输出
	// lrwx------. 1 root root 64 Dec 13 16:18 2 -> /dev/pts/0  错误

	return 0;
}
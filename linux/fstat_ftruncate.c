#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
main()
{
	struct stat st;
	int fd=open("stu.dat",O_RDONLY);
	if(fd==-1) printf("err:%m\n"),exit(-1);
	fstat(fd,&st);
	printf("%d,%o\n",st.st_size,st.st_mode);
	
	
	//int ftruncate(int fd,off_t length)改变文件大小为length
	close(fd);
}
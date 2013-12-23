#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
/*
off_t//返回当前读取指针在文件中的绝对位置
lseek(
	int fd,//文件描述符
	off_t off,//偏移量
	int whence,//偏移参照点
)
*/
main()
{
	//char buf[getpagesize()];
	float score;
	int fd=open("stu.dat",O_RDONLY);
	if(fd==-1) printf("open error:%m"),exit(-1);
	int i;
	int r;
	for(i=0;i<3;i++)
	{
		r=lseek(fd,i*28+24,SEEK_SET);
		printf("%d\n",r);
		r=read(fd,&score,sizeof(float));
		printf("%.2f\n",score);
	}
	
	r=lseek(fd,2000,SEEK_SET);
//打开方式为O_RDONLY或O_WRONLY时r为2000,即在文件中定位只要不是负数，就不会出错，文件大小也不会改变，但下面调用write时，文件大小会发生变化。

//lseek+read=ssize_t pread(int fd,void *buf,size_t count,off_t offset);

//lseek+write=ssize_t pwrite(int fd,const void *buf,size_t count,off_t offset);
for(i=0;i<3;i++)
{
	pread(fd,&score,sizeof(float),i*28+24);
	printf("%.2f\n",score);
}

	close(fd);
	
}
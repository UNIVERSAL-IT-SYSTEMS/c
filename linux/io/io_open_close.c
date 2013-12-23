#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
/*
remove,unlik,rmdir
mode_t umask(mode_t mask)


int open(const char *filename, 
int flag //open的打开方式[创建/打开]
)
open的方式:
	必选方式：O_RDONLY,OWRONLY,ORDWR
	创建/打开：O_CREATE
	可选方式：
			对打开可选方式：O_APPEND O_TRUNC
			对创建可选方式：O_EXCL
int open (const char *filename, int flag, 
mode_t mode//权限只有创建的时候有效
)
返回：>=0内核文件描述符号
	  =-1打开/创建失败
*/
void open_write_test();
void open_read_test();
int main()
{

	//open_wirte_test();
	open_read_test();
	return 0;

}
void open_write_test()
{
	char command[100];
	sprintf(command,"ls -l /proc/%d/fd",getpid());
	system(command);
	// lrwx------. 1 root root 64 Dec 13 16:18 0 -> /dev/pts/0  输入
	// lrwx------. 1 root root 64 Dec 13 16:18 1 -> /dev/pts/0  输出
	// lrwx------. 1 root root 64 Dec 13 16:18 2 -> /dev/pts/0  错误
	//printf("%o\n",umask(0));
	//printf("%o\n",umask(0));
	

	int fd=open("/tmp/test.dat", O_RDWR|O_CREAT|O_EXCL, 0666);
	if(fd==-1)
	{
		printf("open error %m\n");
		exit(-1);
	}
	char name[20]={0};
	short age=20;
	float score=99.99;
	char sex;
	//写第一条
	memcpy(name,"tom",strlen("tom")+1);
	age=20;
	score=99.99;
	sex='F';
	
	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(sex));
	
	//写第二条
	memcpy(name,"Bush",strlen("Bush")+1);
	age=70;
	score=65.00;
	sex='M';
	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(sex));
	
	//写第三条
	
	memcpy(name,"达内",strlen("达内")+1);
	age=10;
	score=99.00;
	sex='F';
	write(fd,name,sizeof(name));
	write(fd,&age,sizeof age);
	write(fd,&score,sizeof(float));
	write(fd,&sex,sizeof(sex));
	system("ls -l /tmp/test.dat");
	system("cat /tmp/test.dat");
	close(fd);	
	
	int r =unlink("/tmp/test.dat");
	if(r==-1) printf("rmove error:%m\n");//exit(-1);
}

void open_read_test()
{
	char name[20];
	short age;
	float score;
	char sex;
	int  fd;
	int r;
	fd=open("/tmp/test.dat", O_RDONLY);
	if(fd==-1)printf("open error:%m\n"),exit(-1);
	while(1)
	{
		r=read(fd,name,sizeof(name));
		if(r==0)break;
		r=read(fd,&age,sizeof(short));
		r=read(fd,&score,sizeof(float));
		r=read(fd,&sex,sizeof(sex));
		printf("%s,\t%4hd,\t%.2f,\t%1c\n",name,age,score,sex);
	}
	close(fd);
}
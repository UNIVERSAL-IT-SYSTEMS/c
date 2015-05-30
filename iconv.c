#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
void main()
{
	char name[20];
	int age;
	char gender;
	float score;
	int fd=open("test.dat",O_CREAT|O_WRONLY,00666);
	if(fd==-1)printf("open error:%m"),exit(errno);
	memcpy(name,"tom",strlen("tom")+1);
	age=20;
	gender='M';
	score=87.5;
    ssize_t s=write(fd,name,sizeof name);
	if(s==-1)printf("write name error:%m"),exit(errno);
	s=write(fd,&age,sizeof age);
	if(s==-1)printf("write age error:%m"),exit(errno);
	s=write(fd,&gender,sizeof gender);
	if(s==-1)printf("write gender error:%m"),exit(errno);
	s=write(fd,&score,sizeof score);
	if(s==-1)printf("write score error:%m"),exit(errno);
	close(fd);
}

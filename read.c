#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
main()
{
	int fd=open("test.dat",O_RDONLY);
	if(fd==-1)printf("open error:%m"),exit(errno);
	char name[20];
	int age;
	char gender;
	float score;
	
	while(1)
	{
		ssize_t s=read(fd,name,sizeof name);
		if(s==0)break;
		s=read(fd,&age,sizeof age);
		s=read(fd,&gender,sizeof gender);
		s=read(fd,&score,sizeof score);
		printf("%s,\t%4hd,\t%1c,\t%0.2f\n",name,age,gender,score);		
		
	}	
	close(fd);
}

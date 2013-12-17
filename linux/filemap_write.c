#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
struct stu
{
	char name[20];
	int age;
	float score;
};

main()
{
	// 打开文件
	int fd = open("newstu.dat",O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd==-1) 
	{
		fd=open("newstu.dat",O_RDWR|O_APPEND);
		if(fd==-1)  printf("::%m\n"),exit(-1);
	}
	//得到文件大小，记录条数
	struct stat st;
	fstat(fd,&st);
	int size=st.st_size;//文件大小
	int count=size/sizeof(struct stu);//记录条数
	//改变文件大小，只要在munmap之前调用都有效
	ftruncate(fd,size+sizeof(struct stu));
	// 映射到一个虚拟地址，映射之后可以通过s操作文件，即通过内存操作文件
	struct stu *s=mmap(0,size+sizeof(struct stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//返回文件在虚拟内存的映射首地址
	// 把数据写入虚拟地址
	printf("输入姓名：");
	scanf("%s",s[count].name);
	printf("输入年龄：");
	scanf("%d",&(s[count].age));
	printf("输入成绩：");
	scanf("%f",&(s[count].score));
	// 卸载虚拟地址
	munmap(s,sizeof(struct stu)+size);
	close(fd);
}
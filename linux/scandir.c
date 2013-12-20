/*
int //返回目录个数 =-1目录查找失败
scandir(
const char *dirp, //目录名
struct dirent ***namelist,//目录列表
int (*filter)(const struct dirent *),//返回0表示不要，返回非零要
int (*compar)(const struct dirent **, const struct dirent **));
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
int mysort(const struct dirent **d1,const struct dirent **d2)
{
	return -alphasort(d1,d2);
}
int myfilter(const struct dirent *d)
{
	if(memcmp(d->d_name,".",1)==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
main(int argc, char *argv[])
{
	struct dirent **d;
	int r=scandir(argv[1],&d,myfilter,mysort);
	printf("子目录个数：%d\n",r);
	int i;
	for(i=0; i<r; i++)
	{
		printf("%s\n",d[i]->d_name);
	}

}

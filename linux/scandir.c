/*
int //返回目录个数 =-1目录查找失败
scandir(
const char *dirp, //目录名
struct dirent ***namelist,//目录列表
int (*filter)(const struct dirent *),//返回0
int (*compar)(const struct dirent **, const struct dirent **));
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
main(int argc, char *argv[])
{
	struct dirent **d;
	int r=scandir(argv[1],&d,0,0);
	printf("子目录个数：%d\n",r);
	int i;
	for(i=0; i<r; i++)
	{
		printf("%s\n",d[i]->d_name);
	}
	struct dirent **p=d;
	while(*p++)
	{
		printf("%s\n",d[i]->d_name);
	}
}

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
/*
int //返回目录个数 =-1目录查找失败
scandir(
const char *dirp, //目录名
struct dirent ***namelist,//目录列表
int (*filter)(const struct dirent *),
int (*compar)(const struct dirent **, const struct dirent **));
*/
main(int argc,char *argv[])
{
	DIR *d=opendir(argv[1]);
	struct dirent *de;
	if(d==NULL)
	{
		printf("opendir error:%m\n");
		exit(-1);
	}
	while(de=readdir(d))
	{
		printf("%25s,\t%d\n",de->d_name,de->d_type);
	}
	closedir(d);
}
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
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
		printf("%025s,\t%d\n",de->d_name,de->d_type);
	}
	closedir(d);
}
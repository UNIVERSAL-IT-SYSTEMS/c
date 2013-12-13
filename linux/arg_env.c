#include <stdio.h>
#include <stdlib.h>
extern char **environ;//unistd.h
int main(int argc, char* argv[], char *arge[])
{
	// char **p=arge;
	// for(;*p!=NULL;p++)
	// {
		// puts(*p);
	// }
	char ** p=environ;
	while(*p)
	{
		puts(*p++);
	}
	puts("======================");
	
	puts(getenv("PATH"));
	setenv("HELLO","Jim",0);
	puts(getenv("HELLO"));
	unsetenv("HELLO");
	char *hello=getenv("HELLO");
	//printf("%s\n",hello);//Segmentation fault (core dumped),hello==NULL
	if(hello==NULL)
		puts("hello not exist");
	else
		puts(hello);
	//puts(NULL);//Segmentation fault (core dumped)
	return 0;
}
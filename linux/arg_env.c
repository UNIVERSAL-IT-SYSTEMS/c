#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[], char *arge[])
{
	char **p=arge;
	for(;*p!=NULL;p++)
	{
		puts(*p);
	}
	puts("======================");
	puts(getenv("PATH"));
	setenv("HELLO","Jim",0);
	puts(getenv("HELLO"));
	unsetenv("HELLO");
	char *hello=getenv("HELLO");
	if(hello==NULL)
		puts("hello not exist");
	else
		puts(hello);
	//puts(NULL);//Segmentation fault (core dumped)
	return 0;
}
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int n=0;
	char str[100];
	char* e=malloc(100);
	strcpy(e,strerror(-1));
	const char* c=NULL;
	do{
		c=strerror(n);
		sprintf(str,"%d:%s",n,c);
		puts(str);
		n++;
	}while(strcmp(c,e)!=0);

	free(e);
	//assert(1);
	return 0;
}
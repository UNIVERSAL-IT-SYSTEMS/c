#include <stdio.h>

int main(int argc, char* argv[])
{
	int i=1;
	int j=2;
	int a[2];
	printf("&a=%p\n",&a);
	printf("&a[0]=%p\n",&a[0]);
	printf("&a[1]=%p\n",&a[1]);
	printf("===============\n");
	printf("&i=%p\n",&i);
	printf("&j=%p\n",&j);
	printf("(char*)&i=%p\n",(char*)&i);
	printf("(char*)&i+1=%p\n",((char*)&i)+1);
	return 0;
}
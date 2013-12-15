#include<stdio.h>

extern char a[];
void show(int *a,int n);
int main()
{
	int b[5]={1,2,3,4,5};
	show(b,5);
    printf("the a[0]'s address is : %p\n",&a[0]);
	while(1);    
    printf("the a[0]'s value is : %c\n",a[0]);
    printf("the a[3]'s address is : %x\n",&a[3]);
    printf("the a[3]'s value is : %c\n",a[3]);
    
}


void show(int *a,int n)
{

	printf("the a[0]'s address is : %x\n",&a[0]);
    printf("the a[0]'s value is : %d\n",a[0]);
    printf("the a[3]'s address is : %x\n",&a[3]);
    printf("the a[3]'s value is : %d\n",a[3]);
	for(int *p=a;p<a+n;p++)
	{
		printf("%d ",*p);
	}
}
#include <stdio.h>
#include <unistd.h>
int is_susu(int a)
{

	if(a==1)return 0;
	if(a==2)return 1;
	int c=1;
	while(++c<a)
	{
		if(a%c==0)
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	int c=0;
	for(n=1;n<100;n+=2)
	{
		if(is_susu(n))
		{

			*((int*)sbrk(4))=n;
			c++;
		}
	}
	int i;
	for(i=c;i>0;i--)
	printf("%d\n",*((int*)sbrk(0)-i));
	brk(sbrk(0)-c*4);
	return 0;

}

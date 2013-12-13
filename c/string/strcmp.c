#include <stdio.h>
size_t strlen(const char *str);
char *strstr1(const char *s1, const char *s2)
{	
	int len1=strlen(s1);
	printf("[%s]'s length:%d\n",s1,len1);
	int len2=strlen(s2);
	printf("[%s]'s length:%d\n",s2,len2);

	
	for(int n=0;len1-->=len2;n++)
	{
		printf("for each:%d\n",n);
		const char *p1=s1+n;
		const char *p2=s2;
		int count=0;
		while(*p1++==*p2++&&count<len2)
		{
			count++;
		}
		if(count==len2) return (char*)(s1+n);
	}
	puts("end while(len1-->=len2)");
	return NULL;
}
int main()
{
	printf("[%s]",strstr1("werqerqasd","as"));
	return 0;
}


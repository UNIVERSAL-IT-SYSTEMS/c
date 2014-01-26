#include <stdlib.h>
#include <stdio.h>
main()
{

	long *p1=malloc(sizeof(long));
	printf("p1  's value is %p\n",p1);
	// printf("p1  's value is %p\n",p1+1);
	long *p2=malloc(sizeof(long));
	printf("p2  's value is %p\n",*p2);
	printf("p2  's value is %p\n",*(p2+1));
	printf("p2  's value is %p\n",*(p2+2));
	printf("p2  's value is %p\n",*(p2+3));
	*(p2+4)=21;
	long *p3=malloc(sizeof(long));
	printf("p3  's value is %p\n",p3);
	long *p4=malloc(sizeof(long));
	printf("p4  's value is %p\n",p4);
}

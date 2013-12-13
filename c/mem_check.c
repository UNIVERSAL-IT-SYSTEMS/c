#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main(void)
{
	unsigned int addr=341234;
	int i,n;
	BYTE *ptr;
	printf("Address of main function: %x\n", (unsigned int)main);
	printf("Address of addr variable: %x\n", (unsigned int)&addr);
	printf("\nEnter a (hex) address:");
	scanf("%x",&addr);
	printf("Enter number of bytes to view:");
	scanf("%d",&n);
	
	printf("\n");
	printf("Address        Bytes        Characters\n");
	printf("-------  --------------- ----------\n");
	ptr=(BYTE*)addr;
	for(; n>0; n-=1){
		printf("%8X ",(unsigned int)ptr);
		for(i=0; i<1&&i<n; i++)
			printf("%.2X", *(ptr+i));
		for(; i<1; i++)
			printf("  ");
		printf("  ");
		for(i=0; i<1&&i<n; i++){
			BYTE ch=*(ptr+i);
			if(!isprint(ch))
				ch='.';
			printf("%c",ch);
		}
		printf("\n");
		ptr+=1;
	}
	return 0;
}


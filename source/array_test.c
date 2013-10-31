#include <stdio.h>

int read_line(char str[], int n)
{
	int ch, i=0;
	while((ch=getchar())!='\n')
		if(i<n)
			str[i++]=ch;
	str[i]='\0';
	return i;
}
int main(void)
{
	char* str="Hello";
	char str2[500];
	printf("%10s\n",&"Hel%dlo"[1]);
	scanf("%5s",str2);//抛弃前面的空白字符，将遇到一个空白字符退出，该空白字符暴力在缓冲区
	gets(str2);
	printf("%s",str2);
	return 0;
}

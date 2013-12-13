//ssize_t write(int fd, void *buf, size_t size);
// ssize>0实际写入的数据数
// ssize=-1写入错误
//ssize_t read(int fd, void *buf, size_t size);
// ssize>0:实际读入数据数
// ssize=0碰到文件结束符合EOF(ctrl+d)
// ssize=-1读取错误
#include <assert.h>
void reversal(char a[],int len)
{
	int n;
	for(n=0;n<len/2;n++)
	{
		char tmp=a[n];
		a[n]=a[len-n-1];
		a[len-n-1]=tmp;
	}
}

void i_to_str(int i,char *buf, int *len)
{
	int n;
	for(n=0;;n++)
	{	
		if(i<10)
		{
			buf[n]=i+48;
			*len=n+1;
			break;
		}
		int cur=i%10;
		buf[n]=cur+48;
		i/=10;
		
	}
	reversal(buf,*len);
	
}
int my_strlen(const char *str)
{
	assert(str);
	if(str==0)
	{
		return 0;
	}
	const char *p=str;
	while(*p++);
	return p-str-1;
}
main()
{
	char buf[1000];
	const char *str="asdfghsasdfasdfasfasdffgfdddddd";
	int s = write(0,str,my_strlen(str));
	int len;
	i_to_str(s,buf,&len);
	str="\nwrite out char number: ";
	write(0,str,my_strlen(str));
	write(0,buf,len);
	write(0,"\n",1);
	read(0,buf,5);
	puts(buf);
}
#include <stdio.h>
#include<malloc.h>
struct word
{
	char c;
	struct word *next;
};
int main()
{
	struct word * open(char *filename);
	int help();
	int find(char *,FILE* result,struct word*);
	struct word* replace(char *,char*,FILE* result,struct word*);
	struct word* todelete(char *,FILE* result,struct word*);
	int save(char*, struct word* );
	char a[20];
	char filename[100];
	char string[100];
	char string2[100];
	char m[100];
	a=m;
	struct word* savep;//建立savep用来便于save；
	FILE* result;
	result=fopen("1253026_result.txt","w+");
	printf("");
	for(;;)//用for循环用来读入多条指令；
	{
		scanf("%s",a);
		switch(*a)
		{
		case'-o':scanf("%s",filename);savep=open(filename);break;
		case'-h':help();break;
		case'-f':scanf("%s",string);find(string,result,savep=open(filename));break;
		case'-r':scanf("%s%s",string,string2); savep=replace(string,string2,result,open(filename));break;
		case'-d':scanf("%s",string);savep=todelete(string,result,open(filename));break;
		case'-q':return 1;break;
		case'-s':scanf("%s",filename);save(filename,savep);break; }
	}
	return 0;
}
struct word * open(char *filename)
{
	struct word *head,*p1,*p2;
	p1=p2=(struct word*)malloc(sizeof(struct word));
	head=p1;
	FILE * fp;
	fp=fopen("filename","r+");
	while((p1->c=(fgetc(fp))!=EOF))//构建链表 将读入的数据放入链表并且在命令行上输出；
	{
		printf("%c",p1->c);
		p2=p1->next;
		p1=p2=(struct word*)malloc(sizeof(struct word));
	}
	p2->next=NULL;
	printf("the file has been opened");
	return head;
}
int find(char* string,FILE* result,struct word* p)
{
	int i=0,j;
	for(;p->next!=NULL;)
	{
		for(j=0;string[j]!=0;j++)
		{
			if(string[j]==p->c)//将字符串中的字符一一与读入的数据即链表中的数比较 如果相同则下一个 不同 退出该循环 再次比较
				p=p->next;
			else break;
		}
		if(string[j]==0)i++;//判断是否找到了一个完整的相同的字符串；
	}
	printf("the numeber of the string you have found in the file is %d",i);
	fprintf(result,"%d",i);
	return 0;
} 
int help()
{
	printf("-o filename 打开文件\n");
	printf("–h 帮助信息，提示各个参数的格式和含义\n");
	printf("–s filename 保存文件到filename指定的路径和文件名\n");
	printf("–f stringtofind 查找stringtofind字符串，并将查到的字符串的个数在屏幕上显示，并将个数写到文件 学号_result.txt中\n");
	printf("–r sourcestring targetstring 替换字符串，将文件中的sourcestring替换成targetstring,将替换多少处显示在屏幕上，并将替换的个数和替换后的文本都写道 学号_result.txt中\n");
	printf("–d stringtodelete 删除字符串，将文件中的stringtodelete删除,将删除多少处显示在屏幕上，并将删除的个数和删除后的文本都写到 学号_result.txt中\n–q 退出程序\n");
	return 0;
} 
struct word* replace(char*string,char* string2 ,FILE* result,struct word* p)
{
	int i=0,j,k,num=0;
	struct word *p1,*head,*head2;
	head2=head=p;//保留一个头指针，方便将替换后的数据写入result文件；
	for(;p->next!=NULL;)
	{
		for(j=0;string[j]!=0;j++)//在读取的数据中找有没有要替换的字符串；
		{
			if( string[j]==p->c)
				p=p->next;
			else break;
			i++;//用来记录指针现在的位置；
		}
		if(string[j]==0)//如果找到；
		{
			k=i-j;//把指针移到字符串的开始；
			p1=p[k].next;
			for(j=0;string2[j]!=0;j++)//进行替换；
			{
				p1->c=string2[j];
				p1=p1->next;
			}
			p[i-1].next=p1;//将替换后的字符串的尾部连到string的尾部 等同于把string抛弃；
			num++; 
		} 
	}
	fprintf(result,"%d",num);//将替换的个数写进result文件；
	printf("the number we have replaced is %d",num);
	for(;head->next!=NULL;)// 将替换后的数据写入result文件；
	{
		fputc(head->c,result);
		head=head->next;
	}
	return head2;//返回头指针便于save；
} 
struct word* todelete(char*string,FILE* result,struct word* p)
{
	int num=0,i,j,k;
	struct word* head,*head2;
	head2=head=p;//记录头指针，方便将删除后的数据输入result文件；
	for(;p->next!=NULL;)
	{
		for(j=0;string[j]!=0;j++)
		{
			if(string[j]==p->c)//将字符串中的字符一一与读入的数据即链表中的数比较 如果相同则下一个 不同 退出该循环 再次比较
				p=p->next;
			else break;
			i++;//用来记录指针现在位置；
		}
		if(string[j]==0)
		{
			num++;
			k=i-j;
			p[i-1].next=p[k].next;
			;//判断是否找到了一个完整的相同的字符串；
		}

	}
	printf("the number we have deleted is %d",num);
	fprintf(result,"%d",num);
	for(;head->next!=NULL;)// 将替换后的数据写入result文件；
	{
		fputc(head->c,result);
		head=head->next;
	}
	return head2 ;//返回头指针便于save；
} 
int save(char*filename,struct word* savep)
{
	FILE * put;
	put=fopen("filename","w");
	while(savep->next!=0)
	{
		fputc(savep->c,put);
		savep=savep->next;
	}
	return 0;
}


#include <stdio.h>

int find_int(const char* filename)
{
	FILE *fp=fopen(filename,"r");
	int n;
	if(fp==NULL)
	{
		return -1;
	}
	while(fscanf(fp,"%d",&n)!=1)
	{
		if(ferror(fp))
		{
			fclose(fp);
			return -2;
		}
		if(feof(fp))
		{
			fclose(fp);
			return -3;
		}
		fscanf(fp,"%*[^\n]");
	}
	fclose(fp);
	return n;
}
int main(void)
{
	printf("%d\n",find_int("test.txt"));
	return 0;
}












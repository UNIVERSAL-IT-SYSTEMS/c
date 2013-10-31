#include <stdio.h>
#define ROW 5
#define COL 4
int main()
{
	int a[ROW][COL];
	for(int i=0;i<ROW; i++)
	{
		for(int j=0; j<COL; j++)
		{
			printf("a[%d][%d]等于%d\n",i,j, a[i][j]);
		}
	}
	for(int* p=&a[0][0]; p<&a[ROW-1][COL-1]; p++)
	{	
		printf("等于%d\n", *p);
	}
	return 0;
}


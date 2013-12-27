#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int
main(void)
{
	// int i;
	// for(i=0;i<1;i++)
	// {
		// fork();
		// printf("-");
	// }
	
	// fork();
	// printf("-");
	// fflush(stdout);
	// fork();
	// printf("-");
	
	
	
	
	if(fork())
	{
		printf("-");
		// fflush(stdout);
		if(fork())
		{
			printf("-");
			// fflush(stdout);
		}else{
			printf("-");
			// fflush(stdout);
		}
	}else
	{
		printf("-");
		// fflush(stdout);
		if(fork())
		{
			printf("-");
			// fflush(stdout);
		}else{
			printf("-");
			// fflush(stdout);
		}
	}
	//system("pstree |grep a.out");
	return 0;
}

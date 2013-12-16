#include <stdio.h>
/*isatty*/
main()
{
	printf("HEllo\n");
	write(1,"world\n",6);
	if(isatty(1))
	{
		write(1,"redir\n",6);
	}
	else
	{
		write(1,"notr redir\n",10);
	}
}
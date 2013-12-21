#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
void print_current_loc()
{
	char* locname = setlocale(LC_ALL, NULL);
	printf("Current locale is: %s\n", locname);
}
int main()
{
	struct lconv *lp =localeconv();
	puts(lp->int_curr_symbol);
	print_current_loc();
	setlocale(LC_ALL, "zh_CN.UTF8" );
	lp =localeconv();
	puts(lp->int_curr_symbol);
	puts(lp->currency_symbol);
	print_current_loc();
	mblen(NULL,MB_CUR_MAX);
	print_current_loc();
	printf("%d\n",mblen("ÊÇ",MB_CUR_MAX));
	printf("%d\n",strlen("ÊÇ"));
	printf("%d\n",sizeof("ÊÇ"));
	return 0;
}

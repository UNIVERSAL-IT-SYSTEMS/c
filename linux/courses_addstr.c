#include <curses.h>
#include <locale.h>
int main()
{

	char* locname =setlocale(LC_ALL, "zh_CN.utf8" );

	// char* locname =setlocale(LC_ALL, "" );
	char name[9];
	int r;
	initscr();
	mvaddstr(4,10,"用户：[        ]");
	r=mvgetnstr(4,17,name,8);
	mvprintw(7,10,"你输入的是：%s",name);
	refresh();
	getch();
	endwin();
	return 0;
}

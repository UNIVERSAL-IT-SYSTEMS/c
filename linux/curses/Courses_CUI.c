/*
IO与Curses
Curses: CUI
UI:User Interface.
	CUI:字符界面
	GUI:图形界面
1.编程模型
	初始化终端initscr
	操作终端(输入/输出/定位/刷新....)
	释放终端endwin
2.显示
	2.1图形输出
		border
		box
		hline
		vline
		属性字符：chtype =属性字节 + 字符字节
3.字符属性与颜色
4.输入
5.窗口
使用一套封装库：
老版本：/usr/lib/libcurses.so 
新版本：/user/lib/libncurses.so

编译时只有指定 -lcurses 或 -lncurses
如果头文件 curses.h 不存在 ，请尝试使用ncurse.h
为防止printf重定向到终端破坏UI，严禁在curses中使用标准IO

man attron
*/
#include <curses.h>
int main()
{
	WINDOW *win=initscr();
	//border(0,0,0,0,0,0,0,0);
	//border('a','b','c','d','e','f','g','h');
	//box(win,'a','b');
	box(stdscr,0,0);
	mvhline(2,10,'=',20);
	mvvline(2,10,'|',10);
	refresh();
	wrefresh(stdscr);
	
	getch();
	endwin();
	return 0;
}
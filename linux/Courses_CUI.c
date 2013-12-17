/*
IO与Curses
Curses: CUI
UI:User Interface.
	CUI:字符界面
	GUI:图形界面
1.编程模型
	初始化终端initscr
	
2.显示
3.字符属性与颜色
4.输入
5.窗口
使用一套封装库：
老版本：/usr/lib/libcurses.so 
新版本：/user/lib/libncurses.so

编译时只有指定 -lcurses 或 -lncurses
如果头文件 curses.h 不存在 ，请尝试使用ncurse.h
*/
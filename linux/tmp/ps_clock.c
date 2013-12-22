#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
WINDOW *wtime,*wnumb;
main()
{
	setlocale(LC_ALL, "" );
	initscr();
	wtime=derwin(stdscr,3,27,0,(COLS-27));
	wnumb=derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	box(wtime,0,0);
	box(wnumb,0,0);
	refresh();
	wrefresh(wtime);
	wrefresh(wnumb);
	if(fork())
	{
		time_t tt;
		struct tm *t;
		while(1)
		{
			time(&tt);//获取时间，以秒计，从1970年1月一日起算，存于tt
			t=localtime(&tt);//转为当地时间，tm 时间结构
			mvwprintw(wtime,1,1,"%4d-%02d-%02d 星期%d %02d:%02d:%02d",1900+t->tm_year,1+t->tm_mon,t->tm_mday,t->tm_wday,t->tm_hour,t->tm_min,t->tm_sec);
			refresh();	
			wrefresh(wtime);
			wrefresh(wnumb);
			sleep(1);
		}
	}
	else
	{
		int num=0;
		int i;
		while(1)
		{
			num=0;
			for(i=0;i<7;i++)
			{
				num=num*10+rand()%10;
			}
			mvwprintw(wnumb,1,2,"%07d",num);
			refresh();	
			wrefresh(wtime);
			wrefresh(wnumb);
			usleep(10000);
		}
	}
	endwin();
}
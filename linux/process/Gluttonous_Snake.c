#include <curses.h>
#include <locale.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h> 
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#define MAIN_COLS  COLS-22
#define MAIN_LINES LINES
struct Coordinate{
	int x;
	int y;
};
enum Food_Type
{
	T1=35,T2=42
};
struct Food{
	struct Coordinate c;
	enum Food_Type ft;
};
struct Snake_Node{
	struct Coordinate c;
	chtype fur;
	struct Snake_Node *next;
};
enum Direction{	//方向
	LEFT,
	RIGHT,
	UP,
	DOWN
};
struct Snake{
	struct Snake_Node *head;
	struct Snake_Node *tail;
	int length;			//长度
	enum Direction dir;	//方向
};
struct Food *food;
struct Snake *snake;
int *stop;
int *pause_game;
int *speed;
int cid;
WINDOW *debugwin;
WINDOW *boderwin;
WINDOW *mainwin;
void init_screen();
void draw(struct Coordinate co, chtype c);
void draw_Snake_Node(struct Snake_Node *sn);
void draw_snake();
void eat();
void init_snake();
void init_food();
void debug();
void snake_move();
void keybordhit();
void redraw();
void recycle();
void sigroutine(int s);
void eat();
void trans_tail_to_head();
void general_food();
void general_food()
{
	debug("general_food");
	static int i=1;
	if(i){
		srand((unsigned)time(NULL));
		i=0;
	}
	food->c.x=rand()%(MAIN_COLS-2)+1;
	food->c.y=rand()%(MAIN_LINES-3)+2;
}


void trans_tail_to_head()
{
	debug("trans_tail_to_head");
	snake->head->next=snake->tail;	
	snake->tail=snake->tail->next;
	snake->head=snake->head->next;
	snake->head->next=NULL;
	snake->head->fur='*';
}
void eat()
{
	debug("eat");
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	sn->c.x=food->c.x;
	sn->c.y=food->c.y;
	sn->fur='@';
	sn->next=NULL;
	
	snake->head->next=sn;
	snake->head=sn;
	snake->length++;
	general_food();
}
//ctrl+c退出父进程时产生SIGINT信号，子进程也会退出不会挂到init
void sigroutine(int s) 
{
	int status;
	switch(s)
	{
		case SIGCHLD: //子进程退出或被kill时触发，父进程回收僵尸进程
			wait(&status);
			// printf("回收完毕:%d!\n",WEXITSTATUS(status));
			break;
		case SIGINT:
			//do nothing
			break;
	}
} 
void recycle()
{
	debug("recycle");
	kill(cid, SIGKILL);
	free(food);
	// struct Snake_Node *p;
	// for(p=snake->tail;p!=NULL;p=p->next)
	// {
		// free(p);
	// }
	munmap((void *)snake,sizeof(struct Snake)+sizeof(int)*3);
	endwin();
	exit(0);
}
void debug(const char *s)
{	
	
	#ifdef DEBUG
		usleep(100000);
		static int f=1;
		static int i=0;
		if(f)
		{
			boderwin=derwin(stdscr,30,20,1,(COLS-21));
			debugwin=derwin(boderwin,28,18,1,1);
			f=0;
		}
		box(boderwin,0,0);
		// box(debugwin,0,0);
		if(DEBUG==1){
			if(i<27)
			{
				mvwaddstr(debugwin,i++,0,s);
			}else
			{
				wmove(debugwin,0,0);
				wdeleteln(debugwin);
				mvwaddstr(debugwin,27,0,s);
			}
		}else{
			//mvwaddstr(debugwin,0,1,s);
		}
		wrefresh(mainwin);
		wrefresh(boderwin);
		wrefresh(debugwin);
	#endif
}
void init_screen()
{
	setlocale(LC_ALL, "zh_CN.utf8");
	initscr();
	mainwin=derwin(stdscr,MAIN_LINES,MAIN_COLS,0,0);
	// keypad(stdscr,FALSE);
	// keypad(mainwin,FALSE);
	curs_set(0);//隐藏光标
	// box(stdscr,0,'_');//边框
	wborder(mainwin,0,0,'$','$','$','$','$','$');
	noecho();//不显示输入的字符
	debug("init_screen");
	init_food();
	init_snake();
}
void draw(struct Coordinate co,chtype c)
{
	// debug("draw");
	mvwaddch(mainwin,co.y,co.x,c);//在指定位置显示字符
}
void draw_Snake_Node(struct Snake_Node *sn)
{
	// debug("draw_Snake_Node");
	draw(sn->c,sn->fur);
}
void draw_snake()
{
	debug("draw_snake");
	mvwprintw(mainwin,1,1,"score is %d, speed is %d",snake->length,*speed);
	wrefresh(mainwin);
	struct Snake_Node *p;
	for(p=snake->tail;p!=NULL;p=p->next)
	{
		draw_Snake_Node(p);
	}
}
void init_food()
{
	debug("init_food");
	//food=malloc(sizeof(struct Food));
	// food=mmap(0,sizeof(struct Food),PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED,0,0);
	food=malloc(sizeof(struct Food));
	food->c.x=20;
	food->c.y=20;
	food->ft=T1;
	draw(food->c,food->ft);
}
void init_snake()
{
	debug("init_snake");
	//snake=malloc(sizeof(struct Snake));
	snake=mmap(0,sizeof(struct Snake),PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,0,0);
	stop=mmap(snake,sizeof(int),PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,0,0);
	pause_game=mmap(stop,sizeof(int),PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,0,0);
	speed=mmap(pause_game,sizeof(int),PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,0,0);
	
	*stop=0;
	*pause_game=0;
	*speed=1;
	//struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	// struct Snake_Node *sn=mmap((char *)snake+sizeof(struct Snake),sizeof(struct Snake_Node),PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,0,0);
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	sn->c.x=10;
	sn->c.y=10;
	sn->fur='*';
	sn->next=NULL;
	snake->head=sn;
	
	snake->tail=sn;
	snake->length=1;
	snake->dir=RIGHT;
	draw_snake();
}
void keybordhit()		//监控键盘
{
	debug("keybordhit");
	while(1)
	{
		char ch=getch();
		switch(ch)
		{
			case 'W':
			case 'w':
				if(snake->dir!=DOWN)	//如果本来方向是下,而按相反方向无效
					snake->dir=UP;
				break;
			case 'A':
			case 'a':
				if(snake->dir!=RIGHT)	//如果本来方向是右,而按相反方向无效
					snake->dir=LEFT;
				break;
			case 'S':
			case 's':
				if(snake->dir!=UP)	//如果本来方向是上,而按相反方向无效
					snake->dir=DOWN;
				break;
			case 'D':
			case 'd':
				if(snake->dir!=LEFT)	//如果本来方向是左,而按相反方向无效
					snake->dir=RIGHT;
				break;
			case 'q':
				*pause_game=2;
				while(*pause_game!=3)
				{
					usleep(100);//可换成信号方式
				}
				char c =getch();
				if(c=='y'){
					recycle();
				}else
				{
					*pause_game=0;
				}
				break;
			case 'p':
				*pause_game=1;
				while(*pause_game!=4)
				{
					usleep(100);//可换成信号方式
				}
				getch();
				*pause_game=0;
				break;
			case 't':
				*stop=1;
				break;
			case 'l':
				
				*speed=*speed+1>10?10:*speed+1;
				break;
			case 'k':
				*speed=*speed-1<=0?1:*speed-1;
				break;
			default:break;
		}
	}
}
void snake_move()
{
	debug("snake_move");
	struct Coordinate c=snake->head->c;
	struct Coordinate fc=food->c;
	switch(snake->dir){
		case LEFT:
			if(fc.x==c.x-1&&fc.y==c.y){
				eat();
			}
			else if(c.x>1)
			{
				snake->tail->c.x=c.x-1;
				snake->tail->c.y=c.y;
				trans_tail_to_head();
			}
			break;
		case RIGHT:
			if(fc.x==c.x+1&&fc.y==c.y){
				eat();	
			}
			else if(c.x<MAIN_COLS-2)
			{
				snake->tail->c.x=c.x+1;
				snake->tail->c.y=c.y;
				trans_tail_to_head();
			}
			break;
		case UP:
			if(fc.x==c.x&&fc.y==c.y-1){
				eat();
			}
			else if(c.y>1)
			{
				snake->tail->c.x=c.x;
				snake->tail->c.y=c.y-1;				
				trans_tail_to_head();
			}
			break;
		case DOWN:
			if(fc.x==c.x&&fc.y==c.y+1){
				eat();
			}
			else if(c.y<MAIN_LINES-2)
			{
				snake->tail->c.x=c.x;
				snake->tail->c.y=c.y+1;
				trans_tail_to_head();
			}
			break;
		default:
			assert(0);
	}
}
void redraw()
{
	debug("redraw");
	// clear();
	wclear(mainwin);
	wborder(mainwin,0,0,'$','$','$','$','$','$');
	draw_snake();
	draw(food->c,food->ft);
	wrefresh(mainwin);
}


int main()
{
	signal(SIGCHLD,sigroutine);
	signal(SIGINT,sigroutine);
	init_screen();
	if(cid=fork())
	{
		keybordhit();
	}
	else
	{
		while(!*stop){
			if(*pause_game==1||*pause_game==2||*pause_game==3||*pause_game==4)
			{
				if(*pause_game==2||*pause_game==3)
				{
					*pause_game=3;
					mvwprintw(mainwin,8,10,"Are you sure?[y or n]:");
				}else{
					*pause_game=4;
					mvwprintw(mainwin,8,10,"pause!");
				}
				wrefresh(mainwin);
				continue;
			}
			snake_move();
			redraw();
			usleep(100000-*speed*5000>0?100000-*speed*5000:10000);
		}		
	}
	return 0;
}

















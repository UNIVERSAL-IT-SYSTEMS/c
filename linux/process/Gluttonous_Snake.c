#include <curses.h>
#include <locale.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h> 
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
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
int cid;
int i=0;
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
void eat(){
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	sn->c.x=food->c.x;
	sn->c.y=food->c.y;
	sn->fur='@';
	
	struct Snake_Node *p=snake->head;
	snake->head=sn;
	sn->next=p;
	snake->length++;
}
//ctrl+c退出父进程时产生SIGINT信号，子进程也会退出不会挂到init
void sigroutine(int s) {
	int status;
	switch(s)
	{
		case SIGCHLD: //子进程退出或被kill时触发，父进程回收僵尸进程
			
			wait(&status);
			// printf("回收完毕:%d!\n",WEXITSTATUS(status));
			break;
	}
} 
void recycle()
{
	munmap(snake,sizeof(struct Snake));
	endwin();
	kill(cid, SIGKILL);
	exit(0);
}
void debug(const char *s)
{
	//mvprintw(i++,1,"%d,%d",LINES,COLS);
	#ifdef DEBUG
		//sleep(1);
		if(DEBUG==1){
			mvaddstr(i++,1,s);
		}else{
			mvaddstr(0,1,s);
		}
		refresh();
	#endif
}
void init_screen()
{
	
	setlocale(LC_ALL, "zh_CN.utf8");
	initscr();
	curs_set(0);//隐藏光标
	box(stdscr,0,'_');//边框
	noecho();//不显示输入的字符
	debug("init_screen");
	init_food();
	init_snake();
}

void draw(struct Coordinate co,chtype c)
{
	debug("draw");
	mvaddch(co.y,co.x,c);//在指定位置显示字符
}
void draw_Snake_Node(struct Snake_Node *sn)
{
	debug("draw_Snake_Node");
	draw(sn->c,sn->fur);
}
void draw_snake()
{
	debug("draw_snake");
	mvprintw(0,0,"snake %d",snake->length);
	refresh();
	struct Snake_Node *p;
	for(p=snake->head;p!=NULL;p=p->next)
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
	snake=mmap(0,sizeof(struct Snake),PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED,0,0);
	//struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	// struct Snake_Node *sn=mmap((char *)snake+sizeof(struct Snake),sizeof(struct Snake_Node),PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,0,0);
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	sn->c.x=10;
	sn->c.y=10;
	sn->fur='@';
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
				recycle();
			default:break;
		}
	}
}
void snake_move()
{
	debug("snake_move");
	struct Snake_Node *p=snake->head;
	switch(snake->dir){
		case LEFT:
			if(food->c.x==p->c.x-1&&food->c.y==p->c.y){
				eat();
				food->c.x=13;
				food->c.y=16;
			}
			else if(p->c.x>1)
			{
				p->c.x--;
				while(p->next)
				{
					p->next->c=p->c;
					p=p->next;
				}
			}
			break;
		case RIGHT:
			if(food->c.x==p->c.x+1&&food->c.y==p->c.y){
				eat();
				food->c.x=17;
				food->c.y=18;	
			}
			else if(p->c.x<COLS-2)
			{
				p->c.x++;
				while(p->next)
				{
					p->next->c=p->c;
					p=p->next;
				}
			}
			break;
		case UP:
			if(food->c.x==p->c.x&&food->c.y==p->c.y-1){
				eat();
				food->c.x=19;
				food->c.y=10;
			}
			else if(p->c.y>1)
			{
				p->c.y--;
				while(p->next)
				{
					p->next->c=p->c;
					p=p->next;
				}
			}
			break;
		case DOWN:
			if(food->c.x==p->c.x&&food->c.y==p->c.y+1){
				eat();
				food->c.x=11;
				food->c.y=12;
			}
			else if(p->c.y<LINES-2)
			{
				p->c.y++;
				while(p->next)
				{
					p->next->c=p->c;
					p=p->next;
				}
			}
			break;
		default:
			assert(0);
	}
}
void redraw()
{
	clear();
	border(0,0,'$','$','$','$','$','$');
	draw_snake();
	draw(food->c,food->ft);
	refresh();
}


int main()
{
	signal(SIGCHLD,sigroutine);
	init_screen();
	if(cid=fork())
	{
		keybordhit();
	}
	else
	{
		while(1){
			snake_move();
			redraw();
			usleep(200000);
		}		
	}
	
	return 0;
}

















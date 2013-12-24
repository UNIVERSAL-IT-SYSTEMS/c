#include <curses.h>
#include <locale.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
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


WINDOW *win;
struct Food *f;
struct Snake *snake;
void init_screen();
void draw(struct Coordinate co, chtype c);
void draw_Snake_Node(struct Snake_Node *sn);
void draw_snake();
void eat();
void init_snake();

void init_screen()
{
	puts("init_screen\n");
	setlocale(LC_ALL, "zh_CN.utf8");
	win=initscr();
	curs_set(0);//隐藏光标
	box(win,0,0);//边框
	init_snake();
}

void draw(struct Coordinate co,chtype c)
{
	puts("draw\n");
	mvaddch(co.y,co.x,c);//在指定位置显示字符
}
void draw_Snake_Node(struct Snake_Node *sn)
{
	puts("draw_Snake_Node\n");
	draw(sn->c,sn->fur);
}
void draw_snake()
{
	puts("draw_snake\n");
	int i;
	for(i=0;i<snake->length;i++)
	{
		draw_Snake_Node(snake->head+i);
	}
}

void eat()
{
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
}
void init_snake()
{
	struct Snake_Node *sn=malloc(sizeof(struct Snake_Node));
	sn->c=f->c;
	sn->next=NULL;
	snake->head=sn;
	snake->tail=sn;
	snake->length=1;
	snake->dir=RIGHT;
	draw_snake();
}

int main()
{
	/*int *a=mmap(0,4,PROT_READ|PROT_WRITE,
			MAP_ANONYMOUS|MAP_SHARED,0,0);
			*/

	init_screen();

/*	if(fork())
	{
		while(1);
	}
	else
	{
		while(1);
	}*/
	getch();
	endwin();
	return 0;
}

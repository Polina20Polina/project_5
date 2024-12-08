#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <iostream.h>
void scroll( char l_crow, char l_col, char r_row, char r_col, char attr)
{
	union REGS r;
		r.h.al = 1;
		r.h.ah = 8;
		r.h.ch = l_crow;
		r.h.cl = l_col;
		r.h.dh = r_row;
		r.h.dl = r_col;
		r.h.bh = attr;
		int86(0x10,&r,&r);
}
void color(int i)
{
	switch(i)
	{
		case BLACK:
	    cputs("0");
			break;
		case BLUE:
			cputs("1");
			break;
		case GREEN:
			cputs("2");
			break;
		case CYAN:
			cputs("3");
			break;
		case RED:
			cputs("4");
			break;
		case MAGENTA:
			cputs("5");
			break;
		case BROWN:
			cputs("6");
			break;
		case LIGHTGRAY:
			cputs("7");
			break;
		case DARKGRAY:
			cputs("8");
			break;
		case LIGHTBLUE:
			cputs("9");
			break;
		case LIGHTGREEN:
			cputs("10");
			break;
		case LIGHTCYAN:
			cputs("11");
			break;
		case LIGHTRED:
			cputs("12");
			break;
		case LIGHTMAGENTA:
			cputs("13");
			break;
		case YELLOW:
			cputs("14");
			break;
		case WHITE:
			cputs("15");
			break;
		default:
			break;
	}
}

int main(){
	int x1 = 25, y1 = 10, x2 = 55, y2= 20;
	int T = 200;
	short int enter = 13;
	char exit = 0;
	int i = 0, j = 0;
	textbackground(BROWN);
	textcolor(WHITE);
	clrscr();
	window(x1, y1, x2, y2);
	for (i = 0; i < 7; i++)
	{  
		for (j = 0; j < 16; j++)
		{
			textbackground(i);
			textcolor(j);
			cputs("background:");
			color(i);
			cputs(" textcolor:");
			color(j);
			cputs("\r\n\n\n");
			delay(T);
			scroll(y1, x1 ,y2, x2, i*16 + j + 1);
			if (kbhit())
			{
				if (getch() == 13)
				{
					exit = 1;
					break;
				}
			}
		}

		if (exit == 1)
		{
			break;
		}
	}



	getch();
	return 0;
}

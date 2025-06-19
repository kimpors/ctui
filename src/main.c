#include "cmdio.h"
#include "ctui.h"

void ci_winshow(CI_Window *win)
{
	char *s = "help there on the way to you";

	for (size_t y = 0; y < win->s.row; y++)
	{
		comove(win->p.y + y, win->p.x);
		for (size_t x = 0; x < win->s.col; x++)
		{
			if ((y == 0 && x == 0) || (y == 0 && x == win->s.col - 1)) putchar('+');
			else if ((y == win->s.row - 1 && x == 0) || (y == win->s.row - 1 && x == win->s.col - 1)) putchar('+');
			else if ((y == 0 || y == win->s.row - 1) && x > 0 && x < win->s.col - 1) putchar('-');
			else if ((y > 0 && y < win->s.row - 1) && (x == 0 || x == win->s.col - 1)) putchar('|');
			else if (*s && (y > 1 && y < win->s.row - 2) && (x > 1 && x < win->s.col - 2)) putchar(*s++);
			else putchar(' ');
		}

		putchar('\n');
	}
}

int main(void)
{
	struct winsize size;
	cosize(&size);
	coclear();
	CI_Window win;
	win.s = (struct size){ 10, 20 };
	win.p = (struct position){ (size.ws_col / 2) - (win.s.col / 2), (size.ws_row / 2) - (win.s.row / 2) };
	ci_winshow(&win);
	return 0;
}

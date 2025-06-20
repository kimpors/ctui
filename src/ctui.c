#include "cmdio.h"
#include "ctui.h"

void ci_winshow(CI_Window *win)
{
	char *ps = win->text;

	for (size_t y = 0; y < win->s.row; y++)
	{
		comove(win->p.y + y, win->p.x);
		for (size_t x = 0; x < win->s.col; x++)
		{
			if ((y == 0 && x == 0) || (y == 0 && x == win->s.col - 1)) putchar('+');
			else if ((y == win->s.row - 1 && x == 0) || (y == win->s.row - 1 && x == win->s.col - 1)) putchar('+');
			else if ((y == 0 || y == win->s.row - 1) && x > 0 && x < win->s.col - 1) putchar('-');
			else if ((y > 0 && y < win->s.row - 1) && (x == 0 || x == win->s.col - 1)) putchar('|');
			else if (*ps && (y > 1 && y < win->s.row - 2) && (x > 1 && x < win->s.col - 2)) putchar(*ps++);
			else putchar(' ');
		}

		putchar('\n');
	}
}

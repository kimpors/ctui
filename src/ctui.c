#include "cmdio.h"
#include "ctui.h"

void ci_winshow(CI_Window *win)
{
	char *ps = win->text;

	size_t wy = win->p.y, wx = win->p.x;
	size_t wrow = win->s.row, wcol = win->s.col;

	for (size_t y = 0; y < wrow; y++)
	{
		if (wy != 0 && wx != 0) comove(wy + y, wx);

		for (size_t x = 0; x < wcol; x++)
		{
			if ((y == 0 && x == 0) || (y == 0 && x == wcol - 1)) putchar('+');
			else if ((y == wrow - 1 && x == 0) || (y == wrow - 1 && x == wcol - 1)) putchar('+');
			else if ((y == 0 || y == wrow - 1) && x > 0 && x < wcol - 1) putchar('-');
			else if ((y > 0 && y < wrow - 1) && (x == 0 || x == wcol - 1)) putchar('|');
			else if (*ps && (y > 1 && y < wrow - 2) && (x > 1 && x < wcol - 2)) putchar(*ps++);
			else putchar(' ');
		}

		putchar('\n');
	}
}

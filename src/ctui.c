#include "cmdio.h"
#include "ctui.h"

void ci_winshow(CI_Window *win)
{
	CI_Vec p = win->pos;
	CI_Vec s = win->size;
	char *ps = win->text.text;

	for (size_t y = 0; y < s.y; y++)
	{
		if (p.x != 0 && p.y != 0) comove(p.y + y, p.x);

		for (size_t x = 0; x < s.x; x++)
		{
			if ((y == 0 && x == 0) || (y == 0 && x == s.x - 1)) putchar('+');
			else if ((y == s.y - 1 && x == 0) || (y == s.y - 1 && x == s.x - 1)) putchar('+');
			else if ((y == 0 || y == s.y - 1) && x > 0 && x < s.x - 1) putchar('-');
			else if ((y > 0 && y < s.y - 1) && (x == 0 || x == s.x - 1)) putchar('|');
			else if (*ps && (y > 1 && y < s.y - 2) && (x > 1 && x < s.x - 2)) putchar(*ps++);
			else putchar(' ');
		}

		putchar('\n');
	}
}

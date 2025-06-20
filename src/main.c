#include "cmdio.h"
#include "ctui.h"

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

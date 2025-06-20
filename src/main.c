#include "cmdio.h"
#include "ctui.h"

int main(void)
{
	struct winsize size;
	cosize(&size);
	coclear();
	CI_Window win;
	win.s = (struct size){ 10, 25 };
	win.p = (struct pos){ (size.ws_col / 2) - (win.s.col / 2), (size.ws_row / 2) - (win.s.row / 2) };
	win.text = "hello from window";
	ci_winshow(&win);
	return 0;
}

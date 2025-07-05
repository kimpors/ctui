#include "cmdio.h"
#include "ctui.h"

int main(void)
{
	struct winsize size;
	cosize(&size);
	// coclear();
	CI_Window win;
	win.size = (CI_Vec){ 25, 10 };
	win.pos = (CI_Vec){ 0, 0 };
	// win.p = (struct pos){ (size.ws_col / 2) - (win.s.col / 2), (size.ws_row / 2) - (win.s.row / 2) };
	// win.p = (struct pos){0, 0};
	win.text = (CI_Text){"help page", (CI_Vec){ 0, 0 }};
	ci_winshow(&win);
	return 0;
}

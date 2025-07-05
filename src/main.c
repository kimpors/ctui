#include "cmdio.h"
#include "ctui.h"

int main(void)
{
	struct winsize size;
	cosize(&size);
	// coclear();
	CI_Window win;
	win.s = (CI_Size){ 25, 10 };
	win.p = (CI_Pos){ 0, 0 };
	// win.p = (struct pos){ (size.ws_col / 2) - (win.s.col / 2), (size.ws_row / 2) - (win.s.row / 2) };
	// win.p = (struct pos){0, 0};
	win.text = "help page";
	ci_winshow(&win);
	return 0;
}

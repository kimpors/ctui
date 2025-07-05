#include "ctui.h"

int main(void)
{
	CI_Win win;
	win.pos = CI_VEC(0, 0);
	win.size = CI_VEC(25, 10);
	win.text = (CI_Text){"help page"};
	ci_winshow(&win);
	return 0;
}

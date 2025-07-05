#include "ctui.h"

int main(void)
{
	CI_Win win;
	win.pos = CI_VEC(0, 0);
	win.size = CI_VEC(25, 10);
	win.text = CI_TEXT("hello", CI_VEC(2, 1));

	ci_winshow(&win);
	return 0;
}

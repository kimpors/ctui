#pragma once
#include <stdio.h>

typedef struct {
	struct size {
		size_t row;
		size_t col;
	} s;
	struct pos {
		size_t x;
		size_t y;
	} p;
	char *text;
} CI_Window;

void ci_winshow(CI_Window *win);

#pragma once
#include <stdio.h>
#define CI_VEC(x, y) (CI_Vec){ x, y }

typedef struct {
	size_t x;
	size_t y;
} CI_Vec;

typedef struct {
	char *text;
	CI_Vec margin;
	CI_Vec padding;
} CI_Text;

typedef struct {
	CI_Vec pos;
	CI_Vec size;
	CI_Text text;
} CI_Win;

void ci_winshow(CI_Win *win);

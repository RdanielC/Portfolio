#include <stdio.h>
#ifndef STRUCTS_H
	#define STRUCTS_H
	typedef struct Dimensions_Canvas_struct{
		char** canvas;
		int row;
		int col;
	}Canvas;
	typedef struct W_Args_struct{
		int s_row;
		int s_col;
		int e_row;
		int e_col;
	}W_Args;
#endif
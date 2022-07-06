#ifndef CANVAS_H
	#define CANVAS_H
	#include <stdlib.h>
	#include <stdio.h>
	#include "structs.h"
	#include "commands.h"
	char** create_canvas(Canvas* dimensions);
	void display_canvas(Canvas* canvas);
	//void _commands(Canvas* canvas_dim);  // Gotta put into a commands.h
	void free_function(Canvas* canvas);
#endif
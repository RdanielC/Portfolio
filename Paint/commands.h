#ifndef COMMANDS_H
	#define COMMANDS_H
	#include <stdio.h>
	#include "structs.h"
	#include "canvas.h"
	void _commands(Canvas* canvas_dim);
	void print_help();
	// void consume_rest_input();
	void action_commands(Canvas* canvas_dim, char command_specifier);
	void w_command(Canvas* canvas_dim);
	void e_command(Canvas* canvas_dim);
	void r_command(Canvas* canvas_dim);
	void a_command(Canvas* canvas_dim);
	void d_command(Canvas* canvas_dim);
	void s_command(Canvas* canvas_dim);
	void l_command(Canvas* canvas_dim);
#endif
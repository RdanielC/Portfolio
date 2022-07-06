#ifndef COMMAND_VAL_H
	#define COMMAND_VAL_H
	#include <stdbool.h>
	#include "structs.h"
	bool w_enough_args(int args_needed, W_Args* args);
	bool w_valid_args(W_Args* args, Canvas* canvas);
	void consume_rest_input();
	void conver_rest_input_string();
	bool e_enough_args(int args_needed, int* col, int* row);
	bool e_arg_val(int col, int row);
	bool extra_input();
	bool r_enough_args(int args_needed, int* row, int* col);
	bool a_enough_args(char* specifier, int* row_col);
	bool d_enough_args(char* specifier, int* row_col);
	bool s_file_exist(char* fileName);
	bool l_file_exist(char* fileName);
#endif
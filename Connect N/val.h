#include <stdbool.h>
#ifndef VAL_H
	#define VAL_H
	void enough_valid_args(int argsRead, char** args, int* rows, int* cols, 
							int* num_piece_row_to_win);
	bool is_valid_format(int args_read, int args_needed);
	void checking_input(int rows, int cols, int args_needed, int* col_to_play);
	bool is_legal_move(char** board, int move, int rows);
	void is_row_full(char** board, int* fake_row_to_use, int* rows_to_play, int cols_to_play, int* move, int turn, char token_to_use);
#endif

#include <stdbool.h>
#ifndef BOARD_H
	#define BOARD_H
	char** set_up_table(int rows, int cols, int num_piece_row_to_win);
	void display_board(char** board, int rows, int cols);
	void delete_board(char*** board, int row, int col);
	bool board_full(char** board, int row, int col);
#endif
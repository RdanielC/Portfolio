#include <stdio.h>
#include <stdbool.h>
#include "play_game.h"
#include "val.h"
#include "board.h"

int main(int argc, char** argvs) {
	int rows;
	int cols;
	int num_piece_row_to_win;
	
	// part of val.c
	enough_valid_args(argc, argvs, &rows, &cols, &num_piece_row_to_win); // argss read, checked and stored

	// Part of board.c
	char** board = set_up_table(rows, cols, num_piece_row_to_win); //Table set

	display_board(board, rows, cols);
	
	// play_game.c
	play_game(board, rows, cols, num_piece_row_to_win);

	// part of val.c
	delete_board(&board, rows, cols);
	return 0;
}
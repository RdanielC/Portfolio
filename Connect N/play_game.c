#include "play_game.h"
#include "val.h"
#include "board.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void play_game(char** board, int rows, int cols, int num_piece_row_to_win) {
	int move;
	int rows_to_play = rows - 1;
	int fake_row = rows - 1; // the empty row used when stacking up col plays
	char token_to_use;
	int turn_tracker = 0;
	bool legal = false;
	bool win = false;
	//bool full = false;
	do {
		checking_input(rows, cols, 1, &move);
		legal = is_legal_move(board, move, rows_to_play);
		turn(turn_tracker, &token_to_use);

		if (legal == true) {
			board[rows_to_play][move] = token_to_use;
			turn_tracker += 1;
		} else if (legal == false) {
			is_row_full(board, &fake_row, &rows_to_play, cols, &move, turn_tracker, token_to_use);
			turn_tracker += 1;
		}
		display_board(board, rows, cols);
		win = is_there_a_winner(board, rows, rows_to_play, fake_row, move, cols, num_piece_row_to_win, token_to_use);
	} while (win == false); 
}

void turn(int tracker, char* token_to_be_used) {
	if ((tracker % 2) == 0) {
		*token_to_be_used = 'X';
	} else if ((tracker % 2) == 1) {
		*token_to_be_used = 'O';
	}
}


bool is_there_a_winner(char** board, int row, int rows_being_played, int row_empty_but_used , int move, int cols, int num_piece_to_win, char curr_token){
	if (win_vertically(board, row, cols, move, num_piece_to_win, curr_token) == true || 
		win_horizontally(board, row, cols, move, num_piece_to_win, curr_token) == true ||
		win_right_diagonal(board, row, cols, move, num_piece_to_win, curr_token) == true ||
		win_left_diagonal(board, row, cols, move, num_piece_to_win, curr_token) == true )  {
			if (curr_token == 'X') {
				printf("Player 1 Won!\n");
			} else {
				printf("Player 2 Won!\n");
			}
			return true;
	} else {
		if (board_full(board, row, cols) == true) {
			printf("Tie game!\n");
			exit(0);
		}
	}
	return false;
}

bool win_horizontally(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token) {
	/* 
		* * *		* * *
		* * *	or  O O O
		x x x		x x O  */
	int encountered_times = 0;
	for (int i = 0; i < row; ++i) {
		encountered_times = 0;
		for (int j = 0; j < cols; ++j) {
			if (board[i][j] == curr_token) {
				encountered_times += 1;
			} else {
				encountered_times = 0;
			}
			if (encountered_times == num_piece_to_win) {
				return true;
			}
		}
	}
	return false;
}

bool win_vertically(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token) {
	/* 
		X * *		* * O
		X * *	or  O X O
		x * *		x x O  */
	int encontered_token_1 = 0;
	int encontered_token_2 = 0;
	for (int j = 0; j < cols; ++j) {
		for (int k = 0; k < row; k++) {
			if (board[k][j] == 'X') {
				encontered_token_1 += 1;
				encontered_token_2 -= 1;
				if (encontered_token_1 == num_piece_to_win) {
					if (board_full(board, row, cols) == true) {
						printf("Tie game!");
						exit(0);
					}
					return true;
				}
			} else if(board[k][j] == 'O') {
				encontered_token_2 += 1;
				encontered_token_1 -= 1;
				if (encontered_token_2 == num_piece_to_win) {
					if (board_full(board, row, cols) == true) {
						printf("Tie game!");
						exit(0);
					}
					return true;
				}
			}
		}
		encontered_token_1 = 0;
		encontered_token_2 = 0;
	}
	return false;
}

bool win_left_diagonal(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token) {
	/*
	You start at 0,0 and divide the board into two parts divided by the diagonal going
	from 0,0 to the botoms. Under that division you can Y. Above the line you change X
	
	*/
	int encontered_token = 0;
	// row part
	int y, x;
	for (y = 0; y < row ; ++y) {
		encontered_token = 0;
		for (int i = y, j = 0; i < row && j < cols; ++i, ++j) {
			if (board[i][j] == curr_token) {
				encontered_token += 1;
			} else {
				encontered_token = 0;
			}
			if (encontered_token == num_piece_to_win) {
				return true;
			}
		}
	}
	// col part
	for (x = 0; x < cols ; ++x) {
		encontered_token = 0;
		for (int i = 0, j = x; i < row && j < cols; ++i, ++j) {
			if (board[i][j] == curr_token) {
				encontered_token += 1;
			} else {
				encontered_token = 0;
			}
			if (encontered_token == num_piece_to_win) {
				return true;
			}
		}
	}
	return false;
}

bool win_right_diagonal(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token) {
	int encontered_token = 0;
	int y, x;
	// col part
	for (x = (cols - 1); x >= cols ; --x) {
		encontered_token = 0;
		for (int i = 0, j = x; i < row && j < cols; ++i, ++j) {
			if (board[i][j] == curr_token) {
				encontered_token += 1;
			} else {
				encontered_token = 0;
			}
			if (encontered_token == num_piece_to_win) {
				return true;
			}
		}
	}
	// row part
	for (y = 0; y < row ; ++y) {
		encontered_token = 0;
		for (int i = y, j = (cols - 1); i < row && j >= 0; ++i, --j) {
			if (board[i][j] == curr_token) {
				encontered_token += 1;
			} else {
				encontered_token = 0;
			}
			if (encontered_token == num_piece_to_win) {
				return true;
			}
		}
	}
	return false;
}
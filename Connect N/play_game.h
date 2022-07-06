#include <stdbool.h>
#ifndef PLAY_GAME_H
	#define PLAY_GAME_H
	void play_game(char** board, int rows, int cols, int num_piece_row_to_win);
	void turn(int tracker, char* token_to_be_used);
	bool is_there_a_winner(char** board, int row, int rows_being_played, int row_empty_but_used , int move, int cols, int num_piece_to_win, char curr_token);
	bool win_horizontally(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token); 
	bool win_vertically(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token);
	bool win_left_diagonal(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token);
	bool win_right_diagonal(char** board, int row, int cols, int move ,int num_piece_to_win, char curr_token);
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "val.h"
#include "play_game.h"

void enough_valid_args(int argsRead, char** args, int* rows, int* cols, 
							int* num_piece_row_to_win) {
	if (argsRead == 4) {
			sscanf(args[1], "%d", rows);
			sscanf(args[2], "%d", cols);
			sscanf(args[3], "%d", num_piece_row_to_win);
	} else if (argsRead > 4) {
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	} else if (argsRead < 4) {
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
}

void checking_input(int rows, int cols, int args_needed, int* col_to_play) {
	int args_read = 0;
	bool can_play = false;
	int play;
	do {
		printf("Enter a column between 0 and %d to play in: ", cols - 1);
		args_read = scanf("%d", &play);
		can_play = is_valid_format(args_read, args_needed);
	} while (can_play == false || !(play >= 0) || play > cols);
	*col_to_play = play;
}


bool is_valid_format(int args_read, int args_needed) {
	bool formatIsGood = args_read == args_needed;
	char character;
	do{
		scanf("%c", &character); //45  bob  \n
			if(isspace(character) == false){ //found a non whitespace character on the way to the end of the line
				formatIsGood = false;
			}
		}while(character != '\n'); //read characters until the end of the line
	return formatIsGood;
}

bool is_legal_move(char** board, int move, int rows) {
	if (board[rows][move] == '*') {
		return true;
	} else if (board[rows][move] == 'x' || board[rows][move] == 'O') {
		return false;
	} else {
		return false;
	}	
}

void is_row_full(char** board, int* fake_row_to_use, int* rows_to_play, int cols_to_play, int* move, int turn, char token_to_use) {
	int empty_tot_tok_count = 0;
	int used_space = 0;
	int fake_row = *rows_to_play;
	for (int j = 0; j < cols_to_play; ++j) {
		if (board[fake_row][j] == '*') {
			empty_tot_tok_count += 1;
		} else if (board[fake_row][j] != '*'){
			used_space += 1;
		}
	}

	if (empty_tot_tok_count > 0) {
		bool empty_above_space = false;
		while (empty_above_space == false || fake_row != 0) {
			if (board[fake_row - 1][(*move)] == '*') {
				empty_above_space = true;
				board[fake_row - 1][(*move)] = token_to_use;		
				break;
			} 
			fake_row -= 1;
		}
		*fake_row_to_use -= 1;
	} else if (used_space == cols_to_play) {
		bool empty_above_space = false;
		while (empty_above_space == false || fake_row != 0) {
			if (board[fake_row - 1][(*move)] == '*') {
				empty_above_space = true;
				board[fake_row - 1][(*move)] = token_to_use;		
				break;
			} 
			fake_row -= 1;
		}
		*fake_row_to_use -= 1;
		*rows_to_play -= 1;
	}
}
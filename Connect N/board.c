#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char** set_up_table(int rows, int cols, int num_piece_row_to_win) {
	if (rows >= cols) {
		char** board = (char**) malloc(rows * sizeof(char*));
		for (int i = 0; i < rows; ++i) {
			board[i] = (char*) malloc(cols * sizeof(char*));
			for (int j = 0; j < cols; ++j) {
				board[i][j] = '*';
			}
		}
		return board;
	} else if (rows <= cols) {
		char** board = (char**) malloc(rows * sizeof(char*));
		for (int i = 0; i < cols; ++i) {
			board[i] = (char*) malloc(cols * sizeof(char*));
			for (int j = 0; j < cols; ++j) {
				board[i][j] = '*';
			}
		}
		return board;
	}
	char** board = (char**) malloc(rows * sizeof(char*));
	return board;
	
}

void display_board(char** board, int rows, int cols) {
	int count = 0;
  	for (int i = rows - 1; i >= 0; --i) {
		printf("%d ", i);
		if(count < rows) {
			for (int j = 0; j < cols; ++j) { // Allows to print the rows & cols in board while printing the headers
				printf("%c ", board[count][j]);
			}
			count += 1;
		}
		printf("\n");
		if (i == 0) { 
		printf("  ");
    	for (int j = 0; j < cols; ++j) {
        	printf("%d ", j);
      	}
		break;
    }
  }
  printf("\n");
}

void delete_board(char*** board, int row, int col) {
	for (int i = 0; i < row; ++i) {
		free((*board)[i]);
	}
	free(*board);
	*board = NULL;
}

bool board_full(char** board, int row, int col) {
	int empty_token = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (board[i][j] == '*') {
				empty_token += 1;
			} else {
				continue;
			}
		}
	}
	if (empty_token == 0) {
		return true;
	} else {
		return false;
	}
}
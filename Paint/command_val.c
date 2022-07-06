#include <stdbool.h>
#include <stdio.h>
#include "structs.h"
#include "command_val.h"

// Command line checker

// Part of command 'w' val
bool w_enough_args(int args_needed, W_Args* args) {
	//IMPORTANT: Need to fix error when entering input such as "w 1"; Convert rest of input to a string and then 
	// use sscanf to read.
	int args_read = scanf(" %d %d %d %d", &args->s_row, &args->s_col, &args->e_row, &args->e_col);
	if (args_read == args_needed) {
		return true;
	} else {
		printf("I was here\n");
		consume_rest_input();
		return false;
	}
}

bool w_valid_args(W_Args* args, Canvas* canvas) {
	if (args->s_row > canvas->row || args->e_row > canvas->row) {
		return false;
	} else if (args->s_col > canvas->col || args->e_col > canvas->col) {
		return false;
	} else if (args->s_row < 0 || args->e_row < 0) {
		return false;
	} else if (args->s_col < 0 || args->e_col < 0) {
		return false;
	}
	return true;
}

void consume_rest_input() {
	char c;
	do {
		scanf("%c", &c);
	} while (c != '\n');
}

bool extra_input() {
	char c;
	do {
		scanf("%c", &c);
		if (c != '\n') {
			return true;
		}
	} while (c != '\n');
	return false;
}

void conver_rest_input_string() {
	printf("Need to implement\n");
	return;
}

// part of e command val
bool e_enough_args(int args_needed, int* col, int* row) {
	int args_read = scanf(" %d %d", col, row);
	if (args_read == args_needed) {
		return true;
	} else {
		return false;
	}
}

bool r_enough_args(int args_needed, int* row, int* col) {
	int args_read = scanf(" %d %d", row, col);
	if (args_read == args_needed) {
		return true;
	} else {
		return false;
	}
}

bool a_enough_args(char* specifier, int* row_col) {
    int args_read = scanf(" %c %d", specifier, row_col);
    if (args_read == 2) {
        return true;
    } else {
        return false;
    }    
}

bool d_enough_args(char* specifier, int* row_col) {
    int args_read = scanf(" %c %d", specifier, row_col);
    if (args_read == 2) {
        return true;
    } else {
        return false;
    }    
}

bool s_file_exist(char * fileName){
	fgets(fileName, 100 , stdin);
	FILE* myFile = NULL;
	myFile = fopen(fileName, "w+");
	if(myFile == NULL){
		return false;
	}
	fclose(myFile);
	return true;
}

bool l_file_exist(char * fileName){
	fgets(fileName, 100 , stdin);
	FILE* myFile = NULL;
	myFile = fopen(fileName, "r");
	if(myFile == NULL){
		return false;
	}
	fclose(myFile);
	return true;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "canvas.h"
#include "structs.h"
#include "commands.h"

void checking_command_args(char** argv, int argc, Canvas* col_row);

int main(int argc, char* argv[]) {
	Canvas Canvas_Dimmensions;
	Canvas_Dimmensions.row = 10;
	Canvas_Dimmensions.col = 10;
	checking_command_args(argv, argc, &Canvas_Dimmensions);

	Canvas_Dimmensions.canvas = create_canvas(&Canvas_Dimmensions);

	_commands(&Canvas_Dimmensions);

	// free(Canvas_Dimmensions.canvas);
	return 0;
}

void checking_command_args(char** argv, int argc, Canvas* col_row) {
	int arg_1;
	int arg_2;
	if (argc > 1) {
		arg_1 = sscanf(argv[1], "%d", &col_row->row);
		arg_2 = sscanf(argv[2], "%d", &col_row->col);
		if (arg_1 != 1) {
			printf("The number of rows is not an integer.\nMaking default board of 10 X 10.\n");
			col_row->row = 10;
			col_row->col = 10;
			return;
		} else if (arg_2 != 1) {
			printf("The number of columns is not an integer.\nMaking default board of 10 X 10.\n");
			col_row->row = 10;
			col_row->col = 10;
			return;
		} else if (col_row->row < 1) {
			printf("The number of rows is less than 1.\nMaking default board of 10 X 10.\n");
			col_row->row = 10;
			col_row->col = 10;
			return;			
		} else if (col_row->col < 1) {
			printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
			col_row->row = 10;
			col_row->col = 10;
			return;				
		} else if (argc > 3) {
			printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\n");
			printf("Making default board of 10 X 10.\n");
			col_row->row = 10;
			col_row->col = 10;
			return;		
		}
	}
} 


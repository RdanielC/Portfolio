#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "canvas.h"
#include "commands.h"
#include "command_val.h"

// Future Me; Remmeber to make functions reusable from inside the program//
void _commands(Canvas* canvas_dim) { // Need to put this into a specific h/c validation file 
	char command_specifier;
	do {
		display_canvas(canvas_dim);
		printf("Enter your command: ");
		scanf(" %c", &command_specifier);
		if (command_specifier == 'q') {
			bool extra = extra_input();
			if (extra == true) {
				printf("Unrecognized command. Type h for help.\n");
				consume_rest_input();	
				_commands(canvas_dim);
			} else {
				free_function(canvas_dim); //--> soon to be implemented
				exit(0);
				
			}
		} else if (command_specifier == 'h') {
			bool extra = extra_input();
			if (extra == true) {
				printf("Unrecognized command. Type h for help.\n");
				consume_rest_input();	
			} else {
				print_help();
			}
		} else {
			action_commands(canvas_dim, command_specifier);
		}
	} while (command_specifier != 'q');
}

void action_commands(Canvas* canvas_dim, char command_specifier) {
	switch(command_specifier) {
		case 'w':
			// printf("Writing\n");
			w_command(canvas_dim);
			return;
		case 'e':
			// printf("Erasing\n");
			e_command(canvas_dim);
			return;
		case 'r':
			r_command(canvas_dim);
			//printf("Resize\n");
			return;
		case 'a':
			a_command(canvas_dim);
			//printf("Add\n");
			return;
		case 'd':
			d_command(canvas_dim);
			//printf("Delete\n");
			return;
		case 's':
			s_command(canvas_dim);
			//printf("Save\n");
			return;
		case 'l':
			l_command(canvas_dim);
			//printf("Load\n");
			return;
		default:
			consume_rest_input();
			printf("Unrecognized command. Type h for help.\n");
			return;
	}
}

void print_help() {
	printf("Commands:\n");
  	printf("Help: h\n");
  	printf("Quit: q\n");
  	printf("Draw line: w row_start col_start row_end col_end\n");
  	printf("Resize: r num_rows num_cols\n");
  	printf("Add row or column: a [r | c] pos\n");
  	printf("Delete row or column: d [r | c] pos\n");
  	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
}

void w_command(Canvas* canvas_dim) {
	W_Args args;
	bool enough_args = w_enough_args(4, &args);
	bool val_args = w_valid_args(&args, canvas_dim);
	int s_row;
	int e_row;
	double rise_over_run = (double)(args.e_row - args.s_row) / (args.e_col - args.s_col);
	if (enough_args == false) {
		printf("Improper draw command.\n");
		return;
	} else {
		if (val_args != true) {
			printf("Improper draw command.\n");
			return;
		}
	}
	// horizontal draw
	if (args.s_row == args.e_row && args.s_col == args.e_col) {
		s_row = (canvas_dim->row - 1) - args.s_row;
		canvas_dim->canvas[s_row][args.s_col] = '-';
	} else if (args.s_row == args.e_row) { // code below can go to a function
		s_row = (canvas_dim->row - 1) - args.s_row;
		if (args.s_col > args.e_col) {
			for (int j = args.s_col; j >= args.e_col; --j) {
				if (canvas_dim->canvas[s_row][j] == '*' || canvas_dim->canvas[s_row][j] == '-') {
					canvas_dim->canvas[s_row][j] = '-';
					
				} else {
					canvas_dim->canvas[s_row][j] = '+';	
				}
				
			}
		} else if (args.s_col < args.e_col){
			for (int i = args.s_col; i <= args.e_col; ++i) {
				if (canvas_dim->canvas[s_row][i] == '*' || canvas_dim->canvas[s_row][i] == '-') {
					canvas_dim->canvas[s_row][i] = '-';
				} else {
					canvas_dim->canvas[s_row][i] = '+';
				}
			}
		}
		return;
	} else if (args.s_col == args.e_col) { // code below can go to a function
		s_row = (canvas_dim->row - 1) - args.s_row;
		e_row = (canvas_dim->row - 1) - args.e_row;
		if (args.s_row > args.e_row) {
			for (int j = s_row; j <= e_row; ++j) {
				if (canvas_dim->canvas[j][args.s_col] == '*' || canvas_dim->canvas[j][args.s_col] == '|') {
					canvas_dim->canvas[j][args.s_col] = '|';
				} else {
					canvas_dim->canvas[j][args.s_col] = '+';
				}
			}
		} else if (args.s_row < args.e_row) {
			for (int i = s_row; i >= e_row; --i) {
				if (canvas_dim->canvas[i][args.s_col] == '*' || canvas_dim->canvas[i][args.s_col] == '|') {
					canvas_dim->canvas[i][args.s_col] = '|';	
				} else {
					canvas_dim->canvas[i][args.s_col] = '+';
				}
			}		
		}
	} else if (rise_over_run != 1 && rise_over_run != -1) {
		printf("Cannot draw the line as it is not straight.\n");
		return;
	} else if (args.s_row > args.e_row && args.s_col < args.e_col) {
		s_row = (canvas_dim->row - 1) - args.s_row;
		e_row = (canvas_dim->row - 1) - args.e_row;
		for (int i = s_row, j = args.s_col; j <= args.e_col && i <= e_row ; ++i, ++j) {
			if (canvas_dim->canvas[i][j] == '*' || canvas_dim->canvas[i][j] == '\\') {
				canvas_dim->canvas[i][j] = '\\';
			} else {
				canvas_dim->canvas[i][j] = '+';
			}
		}	
	} else if (args.s_row < args.e_row && args.s_col > args.e_col) {
		s_row = (canvas_dim->row - 1) - args.s_row;
		e_row = (canvas_dim->row - 1) - args.e_row;
		for (int i = s_row, j = args.s_col; j >= args.e_col && i >= e_row ; --i, --j) {
			if (canvas_dim->canvas[i][j] == '*' || canvas_dim->canvas[i][j] == '\\') {
				canvas_dim->canvas[i][j] = '\\';
			} else {
				canvas_dim->canvas[i][j] = '+';
			}
		}	
	} else if (args.s_row < args.e_row && args.s_col < args.e_col) {
		s_row = (canvas_dim->row - 1) - args.s_row;
		e_row = (canvas_dim->row - 1) - args.e_row;
		for (int i = s_row, j = args.s_col; j <= args.e_col && i >= e_row ; --i, ++j) {
			if (canvas_dim->canvas[i][j] == '*' || canvas_dim->canvas[i][j] == '/') {
				canvas_dim->canvas[i][j] = '/';
			} else {
				canvas_dim->canvas[i][j] = '+';
			}
		}	
	} else if (args.s_row > args.e_row && args.s_col > args.e_col) {
		s_row = (canvas_dim->row - 1) - args.s_row;
		e_row = (canvas_dim->row - 1) - args.e_row;
		for (int i = s_row, j = args.s_col; j >= args.e_col && i <= e_row ; ++i, --j) {
			if (canvas_dim->canvas[i][j] == '*' || canvas_dim->canvas[i][j] == '/') {
				canvas_dim->canvas[i][j] = '/';
			} else {
				canvas_dim->canvas[i][j] = '+';
			}
		}	
	}
}

void e_command(Canvas* canvas_dim) {
	int row;
	int col;
	bool enough_args = e_enough_args(2, &row, &col);
	// printf("Row: %d\nCol: %d\n", row, col);
	int real_row = (canvas_dim->row - 1) - row;
	if (enough_args == true) {
		if (col < 0 || row < 0) {
			printf("Improper erase command.\n");
			return;
		} else if (col >= canvas_dim->col || row >= canvas_dim->row) {
			printf("Improper erase command.\n");
			return;			
		}
		canvas_dim->canvas[real_row][col] = '*';
		return;
	} else {
		consume_rest_input();
		printf("Improper erase command.\n");
		return;
	}
}

void r_command(Canvas* canvas_dim) {
	int row, col;
	bool enough_args = r_enough_args(2, &row, &col);
	if (enough_args) {
		if (col < 1 || row < 1) {
			printf("Improper resize command.\n");
			return;
		}
	}
	// printf("Row: %d\nCol: %d\n", row, col);
	int old_r = canvas_dim->row;
	int old_c = canvas_dim->col;
	char** holder =  (char**)malloc(old_r * sizeof(char*));
	for (int i = 0; i < old_r; ++i) {
		holder[i] = (char*)malloc(old_c * sizeof(char));
	}
	for (int i = 0; i < old_r; ++i) {
		for (int j = 0; j < old_c; ++j) {
			holder[i][j] = canvas_dim->canvas[i][j];
		}
	}

	canvas_dim->canvas = (char**)realloc(canvas_dim->canvas, row * sizeof(char*));
	for (int i = old_r; i < row; ++i) {
		canvas_dim->canvas[i] = (char*)malloc(col * sizeof(char));
	}
	canvas_dim->row = row;
	canvas_dim->col = col;

	int canvas_last_row = canvas_dim->row - 1;
	int holder_last_row = old_r - 1;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {

			canvas_dim->canvas[i][j] = '*';
		}
	} 


	if (row >= old_r && col >= old_c) {
		for (int h_r = holder_last_row; h_r >= 0; --h_r) {
			for(int h_c = 0; h_c < old_c; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}
	} else if(row >= old_r && col <= old_c) {
		for (int h_r = holder_last_row; h_r >= 0; --h_r) {
			for(int h_c = 0; h_c < col; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}	
	}else if(row <= old_r && col >= old_c) {
		for (int h_r = holder_last_row, need_r = 0; h_r > row && need_r < row; --h_r, need_r++) {
			for(int h_c = 0; h_c < old_c; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}
	} else if(row < col && row <= old_r && col <= old_c) {
			//printf("You called me boss\n");
			for (int h_r = holder_last_row, need_r = 0; h_r > row && need_r < row; --h_r, need_r++) {
				for(int h_c = 0; h_c < old_c; ++h_c) {
					canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
				}
			canvas_last_row -= 1;
		}
	}else if(row > col && row <= old_r && col <= old_c) {
			//printf("You called me boss 2.0\n");
			for (int h_r = holder_last_row, need_r = 0; h_r >=0 && need_r < row; --h_r, need_r++) {
				for(int h_c = 0; h_c < col; ++h_c) {
					canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
				}
			canvas_last_row -= 1;
		}
	}else if (row == old_r && col < old_c) {
		for (int h_r = holder_last_row; h_r >= 0; --h_r) {
			for(int h_c = 0; h_c < col; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}
	} else if (row < old_r && col == old_c) {
		for (int h_r = holder_last_row, need_r = 0; h_r > row && need_r < row; --h_r, need_r++) {
			for(int h_c = 0; h_c < old_c; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}
	} else if (row == col && row <= old_r && col <= old_c) {
		for (int h_r = holder_last_row, need_r = 0; h_r > row && need_r < row; --h_r, need_r++) {
			for(int h_c = 0; h_c < col; ++h_c) {
				canvas_dim->canvas[canvas_last_row][h_c] = holder[h_r][h_c];
			}
			canvas_last_row -= 1;
		}		
	} 

	for (int i = 0; i < old_r; ++i) {
		free(holder[i]); 
	}
	free(holder);
	holder = NULL;
}

void a_command(Canvas* canvas_dim) {
	char location_specifier;
	int row_or_col;
	int pre_row_val;
	int real_row;
	bool enough_args = a_enough_args(&location_specifier, &row_or_col);
	if (enough_args) {
		if (location_specifier == 'r') {
			if (row_or_col >= 0 && row_or_col <= canvas_dim->row + 1) {
				canvas_dim->canvas = (char**)realloc(canvas_dim->canvas, (canvas_dim->row + 1) * sizeof(char*));
				pre_row_val = canvas_dim->row;
				canvas_dim->row += 1;
				for (int i = pre_row_val; i < canvas_dim->row; ++i) {
					canvas_dim->canvas[i] = (char*)malloc(canvas_dim->col * sizeof(char));
					for (int j = 0; j < canvas_dim->col; ++j) {
						canvas_dim->canvas[i][j] = '*';
					}
				}
				char* row_holder = (char*)malloc(canvas_dim->col * sizeof(char));
				if (row_or_col >= pre_row_val) {
					if (row_or_col == pre_row_val) {
						for (int i = canvas_dim->row - 1; i > 0; --i) {
							row_holder = canvas_dim->canvas[i];
							canvas_dim->canvas[i] = canvas_dim->canvas[i - 1];
							canvas_dim->canvas[i - 1] = row_holder;
						}
					}
				} else if (row_or_col < pre_row_val) {
					real_row = pre_row_val  - row_or_col;
					for (int i = canvas_dim->row - 1; i > real_row; --i) {
						row_holder = canvas_dim->canvas[i];
						canvas_dim->canvas[i] = canvas_dim->canvas[i - 1];
						canvas_dim->canvas[i - 1] = row_holder;
					}	
				}
			} else {
				printf("Improper add command.\n");
			}
		} else if (location_specifier == 'c') {
			if (row_or_col >= 0 && row_or_col <= canvas_dim->col + 1) {
				canvas_dim->col += 1;
				for (int i = 0; i < canvas_dim->row; ++i) {
					canvas_dim->canvas[i] = (char*)realloc(canvas_dim->canvas[i], (canvas_dim->col + 1) * sizeof(char));
				}
				int col;
				for (int i = 0; i < canvas_dim->row; ++i) {
					for (col = canvas_dim->col - 1; col >= row_or_col; --col) {
						canvas_dim->canvas[i][col] = canvas_dim->canvas[i][col - 1];
					}
					canvas_dim->canvas[i][row_or_col] = '*';
				}
			} else {
				printf("Improper add command.\n");
			}
		} else {
			printf("Improper add command.\n");
		}
	} else {
		if (extra_input()) {
			consume_rest_input();
		}
		printf("Improper add command.\n");
		return;
	}
}

void d_command(Canvas* canvas_dim){
    char location_specifier;
    int row_or_col;
    bool enough_args = a_enough_args(&location_specifier, &row_or_col);
    char* row_holder = (char*)malloc(canvas_dim->col * sizeof(char));
    if (enough_args) {
        if (location_specifier == 'r') {
            if (row_or_col >= 0 && row_or_col < canvas_dim->row) {
                if (row_or_col == canvas_dim->row - 1) {
                    for (int i = 0; i < canvas_dim->row; ++i) {
                            row_holder = canvas_dim->canvas[i + 1];
                            canvas_dim->canvas[i] = row_holder;
                    }
                    canvas_dim->canvas = (char**)realloc(canvas_dim->canvas, (canvas_dim->row - 1) * sizeof(char*));
                    canvas_dim->row -= 1;
                } else if (row_or_col == 0) {
                    canvas_dim->canvas = (char**)realloc(canvas_dim->canvas, (canvas_dim->row - 1) * sizeof(char*));
                    canvas_dim->row -= 1;
                
                } else {
                    for (int i = row_or_col - 1; i < canvas_dim->row; ++i) {
                            row_holder = canvas_dim->canvas[i + 1];
                            canvas_dim->canvas[i] = row_holder;
                            canvas_dim->canvas[i + 1] = canvas_dim->canvas[i];
                    }
                    canvas_dim->canvas = (char**)realloc(canvas_dim->canvas, (canvas_dim->row - 1) * sizeof(char*));
                    canvas_dim->row -= 1;
                }
            }
            else {
                printf("Improper delete command.\n");
            }
        }
    else if (location_specifier == 'c') {
        if (row_or_col >= 0 && row_or_col < canvas_dim->col) {
            for (int i = 0; i < canvas_dim->row; ++i) {
                for (int col = row_or_col; col < canvas_dim->col - 1; ++col) {
                    canvas_dim->canvas[i][col] = canvas_dim->canvas[i][col + 1];
                }
            }
            canvas_dim->col -=1;
            for (int i = 0; i < canvas_dim->row; ++i) {
                canvas_dim->canvas[i] = (char*)realloc(canvas_dim->canvas[i], canvas_dim->col * sizeof(char));
            }
        }
        else {
            printf("Improper delete command.\n");
            }

    }
    } else {
        if (extra_input()) {
            consume_rest_input();
        }
        printf("Improper delete command.\n");
        return;
    }

}

void s_command(Canvas* canvas_dim) {
	char fileName[100];
	//printf("Runs here\n");
	if(s_file_exist(fileName)){
		FILE * myFile;
		myFile = fopen(fileName, "w");
		fprintf(myFile, "%d ", canvas_dim->row);
		fprintf(myFile, "%d\n", canvas_dim->col);
		for(int i = 0; i < canvas_dim->row; i++){
			fputs(canvas_dim->canvas[i], myFile);
		}
		fclose(myFile);
	} else{
		printf("Failed to open file: %s\n", fileName);
	}
}

void l_command(Canvas* canvas_dim) {
	char fileName[100];
	//printf("Runs here\n");
	if(l_file_exist(fileName)){
		FILE * myFile;
		myFile = fopen(fileName, "r");
		fscanf(myFile, "%d %d", &canvas_dim->row, &canvas_dim->col);
 		while (!feof(myFile)) {
			for(int i = 1; i <= canvas_dim->row; i++){
				fscanf(myFile, "%s", canvas_dim->canvas[i-1]);
			}
	 	}
	} else{
		printf("Failed to open file: %s\n", fileName);
	}
}





































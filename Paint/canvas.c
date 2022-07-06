#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "structs.h"
#include "commands.h"

char** create_canvas(Canvas* dimensions) {
	dimensions->canvas = (char**)malloc(dimensions->row * sizeof(char*));
	for (int j = 0; j < dimensions->row; ++j) {
		dimensions->canvas[j] = (char*)malloc(dimensions->col * sizeof(char));
	}
	for (int i = 0; i < dimensions->row; ++i) {
		for (int j = 0; j < dimensions->col; ++j) {
			dimensions->canvas[i][j] = '*';
		}
	}
	return dimensions->canvas;
}

void display_canvas(Canvas* canvas) { // can reduce args by passing a struct
	int count = 0;
  	for (int i = canvas->row - 1; i >= -1; --i) {
		if(i != -1) {
			printf("%d ", i);
			for (int j = 0; j < canvas->col; ++j) { // Allows to print the rows & cols in board while printing the headers
				printf("%c ", canvas->canvas[count][j]);
			}
			count += 1;
		} else if (i == -1) {
			printf(" ");
    		for (int j = 0; j < canvas->col; ++j) {
        		printf("%d ", j);
      		}
		}
		printf("\n");
	}
}

void free_function(Canvas* canvas) {
	for (int i = 0; i < canvas->row; ++i) {
		free(canvas->canvas[i]); 
	}
	free(canvas->canvas);
	//canvas->canvas = NULL;
}
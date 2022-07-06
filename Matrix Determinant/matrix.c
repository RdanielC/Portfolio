#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void read_file(FILE* file, Matrix* matrix) {
    //int item_count = 0;
    int col_count = 0;
    int row_count = 0;
    int item;
    if (file == NULL) {
        printf("Could not open file in matrix.c; Exiting\n");
        exit(0);
    } else {
        fscanf(file, "%d", &matrix->row);
        fscanf(file, "%d", &matrix->col);
        allocate_matrix(matrix);
        while(!feof(file) && row_count < matrix->row) { // can put the below code in another function
            if (col_count < matrix->col) {
                fscanf(file, "%d", &item);
                matrix->matrix[row_count][col_count] = item;
                col_count += 1;
            } else {
                row_count += 1;
                col_count = 0;
            }
        }
    }
}

void allocate_matrix(Matrix* matrix) {
    matrix->matrix = (int**)malloc(matrix->row * sizeof(int*));
    for (int i = 0; i < matrix->row; ++i) {
        matrix->matrix[i] = (int*)malloc(matrix->col * sizeof(int));
    }
    for (int i = 0; i < matrix->row; ++i) {
        for (int j = 0; j < matrix->col; ++j) {
            matrix->matrix[i][j] = 0;
        }
    }
}

int calculate_determinant(Matrix* matrix, int row, int col, int i) {
    // //int determinant;
    // if (row == 2 && col == 2) {
    //     //printf("%d", (matrix->matrix[0][0] *  matrix->matrix[1][1]) - (matrix->matrix[0][1] * matrix->matrix[1][0]));
    //     return (matrix->matrix[0][0] *  matrix->matrix[1][1]) - (matrix->matrix[0][1] * matrix->matrix[1][0]);
    //     printf("Base case\n");
    // } else {
    //     for (; i < row; ++i) {
    //         row -= 1, col -= 1;
    //         return matrix->matrix[0][i] *= calculate_determinant(matrix, row, col, i + 1);
    //         // return determinant;
    //     }
    // }
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->col; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
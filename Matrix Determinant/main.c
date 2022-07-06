#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char* argv[]) {
    Matrix matrix;
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file. Exiting\n");
        exit(0);
    }
    read_file(file, &matrix);
    // for (int i = 0; i < matrix.row; ++i) {
    //     for (int j = 0; j < matrix.col; ++j) {
    //         printf("%d ", matrix.matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int num = calculate_determinant(&matrix, matrix.row, matrix.col, 0);
    printf("num: %d\n", num);
    free(matrix.matrix);
    return 0;
}
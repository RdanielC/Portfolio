#ifndef MATRIX_H
    #define MATRIX_H
    #include <stdio.h>
    #include <stdlib.h>
    typedef struct Matrix_struct{
        int** matrix; 
        int row;
        int col;
    }Matrix;
    void read_file(FILE* file, Matrix* matrix);
    void allocate_matrix(Matrix* matrix);
    int calculate_determinant(Matrix* matrix, int row, int col, int i);
    
#endif
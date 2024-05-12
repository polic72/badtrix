#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>


typedef struct matrix {
    double *values;
    int m;
    int n;
} matrix;


//Mathematic Operations:
matrix *matrix_add(matrix *a, double x);
matrix *matrix_add(matrix *a, matrix *b);
matrix *matrix_subtract(matrix *a, double x);
matrix *matrix_subtract(matrix *a, matrix *b);
matrix *matrix_multiply(matrix *a, double x);
matrix *matrix_multiply(matrix *a, matrix *b);
//matrix *matrix_multiply(matrix *a, vector *v);

//Transform Operations:
matrix *matrix_adjoint(matrix *a);
matrix *matrix_cofactors(matrix *a);
matrix *matrix_inverse(matrix *a);
matrix *matrix_minors(matrix *a);
matrix *matrix_transpose(matrix *a);

#endif //MATRIX_H

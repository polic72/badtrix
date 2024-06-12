#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

#include "vector.h"


typedef struct matrix {
    size_t m;
    size_t n;
    double* values; //Consider possibly making this a variable-sized struct
} matrix;


//Mathematic Operations:
bool matrix_add_value(matrix* dest, const matrix* a, double x);
bool matrix_add_matrix(matrix* dest, const matrix* a, matrix* b);

bool matrix_subtract_value(matrix* dest, const matrix* a, double x);
bool matrix_subtract_matrix(matrix* dest, const matrix* a, matrix* b);

bool matrix_multiply_value(matrix* dest, const matrix* a, double x);
bool matrix_multiply_matrix(matrix* dest, const matrix* a, matrix* b);
bool matrix_multiply_vector(vector* dest, const matrix* a, vector* v);

//Sub Operations:
bool matrix_determinant(double* dest, const matrix* a);
bool matrix_get_cofactor(double* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_givens(matrix* givens, const matrix* a, size_t row, size_t column);
bool matrix_get_minor(double* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_submatrix(matrix* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_submatrix_range(matrix* dest, const matrix* a, size_t start_row, size_t start_column, size_t end_row, size_t end_column);

//Transform Operations:
bool matrix_adjoint(matrix* dest, const matrix* a);
bool matrix_inverse(matrix* dest, const matrix* a);
bool matrix_of_cofactors(matrix* dest, const matrix* a);
bool matrix_of_minors(matrix* dest, const matrix* a);
bool matrix_transpose(matrix* dest, const matrix* a);

//Other Operations:
size_t matrix_to_str(char* output, size_t output_size, const matrix* a, short decimals);
size_t matrix_to_str_10dec(char* output, size_t output_size, const matrix* a);

#endif //MATRIX_H

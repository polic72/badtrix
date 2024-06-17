#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

#include "vector.h"


typedef struct matrix {
    size_t m;
    size_t n;
    double* values; //Consider possibly making this a variable-sized struct
} matrix;


//Creational Operations:
bool matrix_create_identity(matrix* dest);
bool matrix_create_identity_scaled(matrix* dest, double scale);
bool matrix_create_zeros(matrix* dest);


//Mathematic Operations:
bool matrix_add_value(matrix* dest, const matrix* a, double x);
bool matrix_add_matrix(matrix* dest, const matrix* a, const matrix* b);

bool matrix_subtract_value(matrix* dest, const matrix* a, double x);
bool matrix_subtract_matrix(matrix* dest, const matrix* a, const matrix* b);

bool matrix_multiply_value(matrix* dest, const matrix* a, double x);
bool matrix_multiply_matrix(matrix* dest, const matrix* a, const matrix* b);
bool matrix_multiply_vector(vector* dest, const matrix* a, const vector* v);


//Sub Operations:
bool matrix_determinant(double* dest, const matrix* a);
bool matrix_get_cofactor(double* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_column_length(vector* dest, const matrix* a, size_t column, size_t start_row, size_t row_length);
bool matrix_get_column_whole(vector* dest, const matrix* a, size_t column);
bool matrix_get_givens(matrix* givens, const matrix* a, size_t row, size_t column); //Consider making a given procedure rather than using a full matrix.
bool matrix_get_minor(double* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_row_length(vector* dest, const matrix* a, size_t row, size_t start_column, size_t column_length);
bool matrix_get_row_whole(vector* dest, const matrix* a, size_t row);
bool matrix_get_submatrix(matrix* dest, const matrix* a, size_t row, size_t column);
bool matrix_get_submatrix_lengths(matrix* dest, const matrix* a, size_t start_row, size_t start_column, size_t end_row, size_t end_column);


//Transform Operations:
bool matrix_adjoint(matrix* dest, const matrix* a);
bool matrix_inverse(matrix* dest, const matrix* a);
bool matrix_of_cofactors(matrix* dest, const matrix* a);
bool matrix_of_minors(matrix* dest, const matrix* a);
bool matrix_transpose(matrix* dest, const matrix* a);
int matrix_triangle_upper(matrix* dest, const matrix* a, matrix givens[]);


//Eigen Operations:
typedef struct eigen_decomp {
    double* eigen_values;
    matrix* eigen_vectors;
} eigen_decomp;

bool matrix_decompose_eigens(eigen_decomp* dest, const matrix* a, size_t max_iterations);


//Other Operations:
bool matrix_copy_to(matrix* dest, const matrix* a);
size_t matrix_to_str(char* output, size_t output_size, const matrix* a, short decimals);
size_t matrix_to_str_10dec(char* output, size_t output_size, const matrix* a);

#endif //MATRIX_H

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
bool matrix_add_value(matrix* dest, matrix* a, double x);
bool matrix_add_matrix(matrix* dest, matrix* a, matrix* b);

bool matrix_subtract_value(matrix* dest, matrix* a, double x);
bool matrix_subtract_matrix(matrix* dest, matrix* a, matrix* b);

bool matrix_multiply_value(matrix* dest, matrix* a, double x);
bool matrix_multiply_matrix(matrix* dest, matrix* a, matrix* b);
bool matrix_multiply_vector(vector* dest, matrix* a, vector* v);

//Transform Operations:
bool matrix_adjoint(matrix* dest, matrix* a);
bool matrix_cofactors(matrix* dest, matrix* a);
bool matrix_inverse(matrix* dest, matrix* a);
bool matrix_minors(matrix* dest, matrix* a);
bool matrix_transpose(matrix* dest, matrix* a);

//Other Operations:
size_t matrix_to_str(char* output, size_t output_size, matrix* a);

#endif //MATRIX_H

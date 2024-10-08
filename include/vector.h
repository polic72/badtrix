#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <complex.h>


typedef struct vector {
    size_t n;
    double complex *values;
} vector;


//Mathematic Operations:
bool vector_add_value(vector *dest, const vector *a, double complex x);
bool vector_add_vector(vector *dest, const vector *a, const vector *b);

bool vector_subtract_value(vector *dest, const vector *a, double complex x);
bool vector_subtract_vector(vector *dest, const vector *a, const vector *b);

bool vector_multiply_value(vector *dest, const vector *a, double complex x);
bool vector_dot(double complex *dot, const vector *a, const vector *b);
bool vector_cross(vector *dest, ...);

//Transform Operations:
vector *vector_skewSymetric(vector *a);

//Other Operations:
size_t vector_to_str(char* output, size_t output_size, const vector* v, short decimals);
size_t vector_to_str_10dec(char* output, size_t output_size, const vector* v);

#endif //VECTOR_H

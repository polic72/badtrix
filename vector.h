#ifndef VECTOR_H
#define VECTOR_H

#include <stdarg.h>
#include <stdbool.h>


typedef struct vector {
    double *values;
    size_t n;
} vector;


//Mathematic Operations:
bool vector_add_value(vector *dest, const vector *a, double x);
bool vector_add_vector(vector *dest, const vector *a, const vector *b);

bool vector_subtract_value(vector *dest, const vector *a, double x);
bool vector_subtract_vector(vector *dest, const vector *a, const vector *b);

bool vector_multiply_value(vector *dest, const vector *a, double x);
bool vector_dot(double *dot, const vector *a, const vector *b);
bool vector_cross(vector *dest, ...);

//Transform Operations:
vector *vector_skewSymetric(vector *a);

#endif //VECTOR_H

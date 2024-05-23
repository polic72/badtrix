#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"


bool vector_add_value(vector *dest, const vector *a, double x)
{
    if (dest->n != a->n)
    {
        return false;
    }


    for (int i = 0; i < a->n; ++i)
    {
        dest->values[i] = a->values[i] + x;
    }


    return true;
}


bool vector_add_vector(vector *dest, const vector *a, const vector *b)
{
    if (dest->n != a->n && a->n != b->n)
    {
        return false;
    }


    for (int i = 0; i < a->n; ++i)
    {
        dest->values[i] = a->values[i] + b->values[i];
    }


    return true;
}


bool vector_subtract_value(vector *dest, const vector *a, double x)
{
    if (dest->n != a->n)
    {
        return false;
    }


    for (int i = 0; i < a->n; ++i)
    {
        dest->values[i] = a->values[i] - x;
    }


    return true;
}


bool vector_subtract_vector(vector *dest, const vector *a, const vector *b)
{
    if (dest->n != a->n && a->n != b->n)
    {
        return false;
    }


    for (int i = 0; i < a->n; ++i)
    {
        dest->values[i] = a->values[i] - b->values[i];
    }


    return true;
}


bool vector_multiply_value(vector *dest, const vector *a, double x)
{
    if (dest->n != a->n)
    {
        return false;
    }


    for (int i = 0; i < a->n; ++i)
    {
        dest->values[i] = a->values[i] * x;
    }


    return true;
}


bool vector_dot(double *dot, const vector *a, const vector *b)
{
    if (a->n != b->n)
    {
        return false;
    }


    double sum = 0;
    for (int i = 0; i < a->n; ++i)
    {
        sum += a->values[i] * b->values[i];
    }

    *dot = sum;


    return true;
}


//Need to do more work on matrix to do this fully, but I assure you that it WILL be cursed as hell.
bool vector_cross(vector *dest, ...)
{
//    if (a->n != b->n)
//    {
//        return NULL;
//    }


    va_list args;
    va_start(args, dest);


    va_end(args);

    return false;
}

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"


bool matrix_add_value(matrix* dest, matrix* a, double x)
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * a->n + c] = a->values[r * a->n + c] + x;
        }
    }

    return true;
}


bool matrix_add_matrix(matrix* dest, matrix* a, matrix* b)
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return false;
    }

    if (a->m != b->m && a->n != b->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * a->n + c] = a->values[r * a->n + c] + b->values[r * b->n + c];
        }
    }

    return true;
}


bool matrix_subtract_value(matrix* dest, matrix* a, double x)
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * a->n + c] = a->values[r * a->n + c] - x;
        }
    }

    return true;
}


bool matrix_subtract_matrix(matrix* dest, matrix* a, matrix* b)
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return false;
    }

    if (a->m != b->m && a->n != b->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * a->n + c] = a->values[r * a->n + c] - b->values[r * b->n + c];
        }
    }

    return true;
}


bool matrix_multiply_value(matrix* dest, matrix* a, double x)
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return false;
    }

    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * a->n + c] = a->values[r * a->n + c] * x;
        }
    }

    return true;
}


bool matrix_multiply_matrix(matrix* dest, matrix* a, matrix* b)
{
    if (dest->m != a->m && dest->n != b->n)
    {
        return false;
    }

    if (a->n != b->m)
    {
        return false;
    }


    for (size_t i = 0; i < a->m; ++i)
    {
        for (size_t j = 0; j < b->n; ++j)
        {
            dest->values[i * a->m + j] = 0;

            for (size_t k = 0; k < a->n; ++k)
            {
                dest->values[i * a->m + j] += a->values[i * a->m + k] * b->values[k * b->n + j];
            }
        }
    }

    return true;
}


bool matrix_multiply_vector(vector* dest, matrix* a, vector* v)
{
    if (dest->n != a->m)
    {
        return false;
    }

    if (a->n != v->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        dest->values[r] = 0;

        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r] += a->values[r * a->m + c] * v->values[c];
        }
    }

    return true;
}


//bool matrix_adjoint(matrix* dest, matrix* a)
//{
//
//}
//
//
//bool matrix_cofactors(matrix* dest, matrix* a)
//{
//
//}
//
//
//bool matrix_inverse(matrix* dest, matrix* a)
//{
//
//}
//
//
//bool matrix_minors(matrix* dest, matrix* a)
//{
//
//}


bool matrix_transpose(matrix* dest, matrix* a)
{
    if (dest->m != a->n && dest->n != a->m)
    {
        return false;
    }


    for (size_t r = 0; r < a->m - 1; ++r)
    {
        for (size_t c = r; c < a->n; ++c)
        {
            if (r == c)
            {
                continue;
            }

            //We need to do this just in case we're doing an in-place transpose.
            double temp = a->values[r * a->m + c];

            dest->values[r * a->m + c] = a->values[c * a->n + r];
            dest->values[c * a->n + r] = temp;
        }
    }

    return true;
}


size_t matrix_to_str(char* output, size_t output_size, matrix* a)
{
    //
}

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "extras.h"
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


size_t vector_to_str(char* output, size_t output_size, vector* v)
{
    int max_size = -1;

    for (size_t i = 0; i < v->n; ++i)
    {
        char temp_num[32];

        double_nice_str_10dec(temp_num, 32, v->values[i]);

        printf("%s\n", temp_num);
    }

    return 0;
//
//    if (max_size == -1)
//    {
//        switch (output_size)
//        {
//            case 0:
//                return 0;
//
//
//            case 1:
//                output[0] = '|';
//                return 1;
//
//
//            case 2:
//                output[0] = '|';
//                output[1] = ' ';
//                return 2;
//
//
//            case 3:
//                output[0] = '|';
//                output[1] = ' ';
//                output[2] = ' ';
//                return 3;
//
//
//            case 4:
//                output[0] = '|';
//                output[1] = ' ';
//                output[2] = ' ';
//                output[3] = '|';
//                return 4;
//
//
//            default:
//                output[0] = '|';
//                output[1] = ' ';
//                output[2] = ' ';
//                output[3] = '|';
//                return 4;
//        }
//    }
//
//
//    size_t counter = 0;
//
//    for (size_t i = 0; i < v->n; ++i)
//    {
//        output[counter] = '|';
//        counter++;
//
//        if (counter >= output_size)
//        {
//            return counter;
//        }
//
//
//        output[counter] = ' ';
//        counter++;
//
//        if (counter >= output_size)
//        {
//            return counter;
//        }
//
//
//        //
//    }
}

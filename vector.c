#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

        short num_size = strlen(temp_num);

        if (num_size > max_size)
        {
            max_size = num_size;
        }
    }


    //Just a quick hardcode for 0-length vectors.
    if (max_size == -1)
    {
        switch (output_size)
        {
            case 0:
                return 0;


            case 1:
                output[0] = '|';
                return 1;


            case 2:
                output[0] = '|';
                output[1] = ' ';
                return 2;


            case 3:
                output[0] = '|';
                output[1] = ' ';
                output[2] = ' ';
                return 3;


            case 4:
                output[0] = '|';
                output[1] = ' ';
                output[2] = ' ';
                output[3] = '|';
                return 4;


            default:
                output[0] = '|';
                output[1] = ' ';
                output[2] = ' ';
                output[3] = '|';
                return 4;
        }
    }


    size_t counter = 0;

    for (size_t i = 0; i < v->n; ++i)
    {
        output[counter] = '|';
        counter++;

        if (counter >= output_size)
        {
            return counter;
        }


        output[counter] = ' ';
        counter++;

        if (counter >= output_size)
        {
            return counter;
        }


        char temp_num[32];

        double_nice_str_10dec(temp_num, 32, v->values[i]);

        short num_size = strlen(temp_num);
        short half_size = (max_size - num_size) / 2;

        short left_pad = half_size + (((max_size - num_size) % 2 == 1) ? 1 : 0);
        short right_pad = half_size;


        for (short j = 0; j < left_pad; ++j)
        {
            output[counter] = ' ';
            counter++;

            if (counter >= output_size)
            {
                return counter;
            }
        } 


        size_t num_start = counter;

        while (counter - num_start < 32)
        {
            output[counter] = temp_num[counter - num_start];
            counter++;

            if (counter >= output_size)
            {
                return counter;
            }

            if (temp_num[counter - num_start] == '\0')
            {
                break;
            }
        }


        for (short j = 0; j < right_pad; ++j)
        {
            output[counter] = ' ';
            counter++;

            if (counter >= output_size)
            {
                return counter;
            }
        } 


        output[counter] = ' ';
        counter++;

        if (counter >= output_size)
        {
            return counter;
        }


        output[counter] = '|';
        counter++;

        if (counter >= output_size)
        {
            return counter;
        }


        if (i != v->n - 1)
        {
            output[counter] = '\n';
            counter++;

            if (counter >= output_size)
            {
                return counter;
            }
        }
    }


    output[counter] = '\0';
    counter++;

    return counter;
}

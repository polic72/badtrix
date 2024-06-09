#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "extras.h"
#include "matrix.h"


//Mathematic Operations:
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


//Sub Operations:
bool matrix_determinant(double* dest, matrix* a)
{
    if (a->m != a->n)
    {
        return false;
    }


    switch (a->m)
    {
        case 0:
            return false;


        case 1:
            *dest = a->values[0];
            return true;


        case 2:
            *dest = a->values[0] * a->values[3] - a->values[1] * a->values[2];
            return true;


        case 3:
            *dest = a->values[0] * (a->values[4] * a->values[8]) + a->values[1] * (a->values[5] * a->values[6]) 
                + a->values[2] * (a->values[3] * a->values[7]) 
                - (a->values[6] * (a->values[4] * a->values[2]) + a->values[7] * (a->values[5] * a->values[0]) 
                        + a->values[8] * a->values[3] * a->values[1]);
            return true;
    }


    double old = *dest;
    *dest = 0;

    for (size_t c = 0; c < a->n; ++c)
    {
        double temp;
        if (!matrix_get_cofactor(&temp, a, 0, c))
        {
            *dest = old;
            return false;
        }
        
        *dest += a->values[c] * temp;
    }


    return true;
}


bool matrix_get_cofactor(double* dest, matrix* a, size_t row, size_t column)
{
    if (!matrix_get_minor(dest, a, row, column))
    {
        return false;
    }


    if (row % 2 == 1 ^ column % 2 == 1)
    {
        *dest *= -1;
    }


    return true;
}


bool matrix_get_minor(double* dest, matrix* a, size_t row, size_t column)
{
    if (row < 0 || row >= a->m)
    {
        return false;
    }

    if (column < 0 || column >= a->n)
    {
        return false;
    }


    matrix minor_matrix;
    minor_matrix.values = malloc((a->m - 1) * (a->n - 1) * sizeof(double));
    minor_matrix.m = a->m - 1;
    minor_matrix.n = a->n - 1;

    if (!matrix_get_submatrix(&minor_matrix, a, row, column))
    {
        return false;
    }

    matrix_determinant(dest, &minor_matrix);

    free(minor_matrix.values);


    return true;
}


bool matrix_get_submatrix(matrix* dest, matrix* a, size_t row, size_t column)
{
    if (dest->m != a->m - 1)
    {
        return false;
    }

    if (dest->n != a->n - 1)
    {
        return false;
    }


    if (row < 0 || row >= a->m)
    {
        return false;
    }

    if (column < 0 || column >= a->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        if (r == row)
        {
            continue;
        }

        for (size_t c = 0; c < a->n; ++c)
        {
            if (c == column)
            {
                continue;
            }

            size_t r_t = (r < row) ? r : r - 1;
            size_t c_t = (c < column) ? c : c - 1;

            dest->values[r_t * dest->n + c_t] = a->values[r * a->n + c];
        }
    }


    return true;
}


bool matrix_get_submatrix_range(matrix* dest, matrix* a, size_t start_row, size_t start_column, size_t end_row, size_t end_column)
{
    size_t r_diff = end_row - start_row;
    size_t c_diff = end_column - start_column;

    if (r_diff < 0)
    {
        return false;
    }

    if (c_diff < 0)
    {
        return false;
    }


    if (dest->m != r_diff)
    {
        return false;
    }

    if (dest->n != c_diff)
    {
        return false;
    }


    if (start_row < 0)
    {
        return false;
    }

    if (end_row >= a->m)
    {
        return false;
    }
    

    if (start_column < 0)
    {
        return false;
    }

    if (end_column >= a->n)
    {
        return false;
    }


    for (size_t r = start_row; r < end_row; ++r)
    {
        for (size_t c = start_column; c < end_column; ++c)
        {
            dest->values[(r - start_row) * c_diff + (c - start_column)] = a->values[r * a->n + c];
        }
    }


    return true;
}


//Transform Operations:
bool matrix_adjoint(matrix* dest, matrix* a)
{
    if (!matrix_of_cofactors(dest, a))
    {
        return false;
    }


    matrix_transpose(dest, dest);


    return true;
}


bool matrix_of_cofactors(matrix* dest, matrix* a)
{
    if (dest->m != a->m)
    {
        return false;
    }

    if (dest->n != a->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            if (!matrix_get_cofactor(dest->values + r * a->n + c, a, r, c))
            {
                return false;
            }
        }
    }
    

    return true;
}


bool matrix_inverse(matrix* dest, matrix* a)
{
    if (!matrix_adjoint(dest, a))
    {
        return false;
    }


    double determinant = 0;

    for (size_t rc = 0; rc < dest->m; ++rc)
    {
        //Here it's the r...
        double val = dest->values[rc * dest->n];

        //...and here it's the c.
        determinant += val * a->values[rc];
    }


    matrix_multiply_value(dest, dest, 1 / determinant);


    return true;
}


bool matrix_of_minors(matrix* dest, matrix* a)
{
    if (dest->m != a->m)
    {
        return false;
    }

    if (dest->n != a->n)
    {
        return false;
    }


    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            if (!matrix_get_minor(dest->values + r * a->n + c, a, r, c))
            {
                return false;
            }
        }
    }
    

    return true;
}


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


//Other Operations:
size_t matrix_to_str(char* output, size_t output_size, matrix* a)
{
    int max_sizes[a->n];

    for (size_t c = 0; c < a->n; ++c)
    {
        max_sizes[c] = -1;
    }

    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            char temp_num[32];

            double_nice_str_10dec(temp_num, 32, a->values[r * a->n + c]);

            short num_size = strlen(temp_num);

            if (num_size > max_sizes[c])
            {
                max_sizes[c] = num_size;
            }
        }
    }


    //Just a quick hardcode for 0-size matrices.
    if (a->m == 0 || a->n == 0)
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

    for (size_t r = 0; r < a->m; ++r)
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


        for (size_t c = 0; c < a->n; ++c)
        {
            char temp_num[32];

            double_nice_str_10dec(temp_num, 32, a->values[r * a->n + c]);

            short num_size = strlen(temp_num);
            short half_size = (max_sizes[c] - num_size) / 2;

            short left_pad = half_size + (((max_sizes[c] - num_size) % 2 == 1) ? 1 : 0) + ((c == 0) ? 0 : 1);
            short right_pad = half_size + ((c == a->n - 1) ? 0 : 1);


            for (short i = 0; i < left_pad; ++i)
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


            for (short i = 0; i < right_pad; ++i)
            {
                output[counter] = ' ';
                counter++;

                if (counter >= output_size)
                {
                    return counter;
                }
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


        if (r != a->m - 1)
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

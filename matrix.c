#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
#include <string.h>
#include <math.h>

#include "extras.h"
#include "matrix.h"


//Creational Operations:
bool matrix_create_identity(matrix* dest)
{
    if (dest->m != dest->n)
    {
        return false;
    }


    for (size_t r = 0; r < dest->m; ++r)
    {
        for (size_t c = 0; c < dest->n; ++c)
        {
            if (r == c)
            {
                dest->values[r * dest->n + c] = 1;
            }
            else
            {
                dest->values[r * dest->n + c] = 0;
            }
        }
    }


    return true;
}


bool matrix_create_identity_scaled(matrix* dest, double complex scale)
{
    if (dest->m != dest->n)
    {
        return false;
    }


    for (size_t r = 0; r < dest->m; ++r)
    {
        for (size_t c = 0; c < dest->n; ++c)
        {
            if (r == c)
            {
                dest->values[r * dest->n + c] = scale;
            }
            else
            {
                dest->values[r * dest->n + c] = 0;
            }
        }
    }


    return true;
}


bool matrix_create_zeros(matrix* dest)
{
    for (size_t rc = 0; rc < dest->m * dest->n; ++rc)
    {
        dest->values[rc] = 0;
    }


    return true;
}


//Mathematic Operations:
bool matrix_add_value(matrix* dest, const matrix* a, double complex x)
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


bool matrix_add_matrix(matrix* dest, const matrix* a, const matrix* b)
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


bool matrix_subtract_value(matrix* dest, const matrix* a, double complex x)
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


bool matrix_subtract_matrix(matrix* dest, const matrix* a, const matrix* b)
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


bool matrix_multiply_value(matrix* dest, const matrix* a, double complex x)
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


bool matrix_multiply_matrix(matrix* dest, const matrix* a, const matrix* b)
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


bool matrix_multiply_vector(vector* dest, const matrix* a, const vector* v)
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
bool matrix_determinant(double complex* dest, const matrix* a)
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


    double complex old = *dest;
    *dest = 0;

    for (size_t c = 0; c < a->n; ++c)
    {
        double complex temp;
        if (!matrix_get_cofactor(&temp, a, 0, c))
        {
            *dest = old;
            return false;
        }
        
        *dest += a->values[c] * temp;
    }


    return true;
}


bool matrix_get_cofactor(double complex* dest, const matrix* a, size_t row, size_t column)
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


bool matrix_get_column_length(vector* dest, const matrix* a, size_t column, size_t start_row, size_t row_length)
{
    if (dest->n != row_length)
    {
        return false;
    }


    if (column < 0 || column >= a->n)
    {
        return false;
    }


    size_t end_row = start_row + row_length - 1;

    if (start_row < 0 || start_row >= a->m)
    {
        return false;
    }

    if (end_row < 0 || end_row >= a->m)
    {
        return false;
    }


    for (size_t i = 0; i < row_length; ++i)
    {
        dest->values[i] = a->values[(i + start_row) * a->n + column];
    }


    return true;
}


bool matrix_get_column_whole(vector* dest, const matrix* a, size_t column)
{
    return matrix_get_column_length(dest, a, column, 0, a->m);
}


bool matrix_get_givens(matrix* givens, const matrix* a, size_t row, size_t column)
{
    if (row < 0 || row >= a->m)
    {
        return false;
    }

    if (column < 0 || column >= a->n)
    {
        return false;
    }


    double complex negative_s_spot = a->values[row * a->n + column];
    double complex c_spot = a->values[column * a->n + column];

    double complex denominator = csqrt(negative_s_spot * negative_s_spot + c_spot * c_spot);

    double complex negative_s = negative_s_spot / denominator;
    double complex c = c_spot / denominator;


    for (size_t r = 0; r < givens->m; ++r)
    {
        for (size_t c = 0; c < givens->n; ++c)
        {
            givens->values[r * givens->n + c] = (r == c) ? 1 : 0;
        }
    }

    givens->values[row * givens->n + column] = -negative_s;
    givens->values[column * givens->n + row] = negative_s;

    givens->values[row * givens->n + row] = c;
    givens->values[column * givens->n + column] = c;


    return true;
}


bool matrix_get_minor(double complex* dest, const matrix* a, size_t row, size_t column)
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
    minor_matrix.values = malloc((a->m - 1) * (a->n - 1) * sizeof(double complex));
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


bool matrix_get_row_length(vector* dest, const matrix* a, size_t row, size_t start_column, size_t column_length)
{
    if (dest->n != column_length)
    {
        return false;
    }


    if (row < 0 || row >= a->n)
    {
        return false;
    }


    size_t end_column = start_column + column_length - 1;

    if (start_column < 0 || start_column >= a->n)
    {
        return false;
    }

    if (end_column < 0 || end_column >= a->n)
    {
        return false;
    }


    for (size_t i = 0; i < column_length; ++i)
    {
        dest->values[i] = a->values[row * a->n + (i + start_column)];
    }


    return true;
}


bool matrix_get_row_whole(vector* dest, const matrix* a, size_t row)
{
    return matrix_get_row_length(dest, a, row, 0, a->n);
}


bool matrix_get_submatrix(matrix* dest, const matrix* a, size_t row, size_t column)
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


bool matrix_get_submatrix_lengths(matrix* dest, const matrix* a, 
        size_t start_row, size_t row_length, size_t start_column, size_t column_length)
{
    if (dest->m != row_length)
    {
        return false;
    }

    if (dest->n != column_length)
    {
        return false;
    }


    size_t end_row = start_row + row_length - 1;
    size_t end_column = start_column + column_length - 1;

    if (start_row < 0 || start_row >= a->m)
    {
        return false;
    }

    if (end_row < 0 || end_row >= a->m)
    {
        return false;
    }


    if (start_column < 0 || start_column >= a->n)
    {
        return false;
    }

    if (end_column < 0 || end_column >= a->n)
    {
        return false;
    }


    for (size_t r = 0; r < row_length; ++r)
    {
        for (size_t c = 0; c < column_length; ++c)
        {
            dest->values[r * dest->n + c] = a->values[(r + start_row) * a->n + (c + start_column)];
        }
    }


    return true;
}


//Transform Operations:
bool matrix_adjoint(matrix* dest, const matrix* a)
{
    if (!matrix_of_cofactors(dest, a))
    {
        return false;
    }


    matrix_transpose(dest, dest);


    return true;
}


bool matrix_inverse(matrix* dest, const matrix* a)
{
    if (!matrix_adjoint(dest, a))
    {
        return false;
    }


    double complex determinant = 0;

    for (size_t rc = 0; rc < dest->m; ++rc)
    {
        //Here it's the r...
        double complex val = dest->values[rc * dest->n];

        //...and here it's the c.
        determinant += val * a->values[rc];
    }


    matrix_multiply_value(dest, dest, 1 / determinant);


    return true;
}


bool matrix_of_cofactors(matrix* dest, const matrix* a)
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


bool matrix_of_minors(matrix* dest, const matrix* a)
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


bool matrix_transpose(matrix* dest, const matrix* a)
{
    if (dest->m != a->m && dest->n != a->n)
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
            double complex temp = a->values[r * a->m + c];

            dest->values[r * a->m + c] = a->values[c * a->n + r];
            dest->values[c * a->n + r] = temp;
        }
    }

    return true;
}


int matrix_triangle_upper(matrix* dest, const matrix* a, matrix givens[])
{
    if (dest->m != a->m && dest->n != a->n)
    {
        return -1;
    }

    if (a->m != a->n)
    {
        return -1;
    }

    if (a->m <= 1)
    {
        return -1;
    }


    if (!matrix_copy_to(dest, a))
    {
        return -1;
    }


    matrix temp_matrix;
    temp_matrix.m = a->m;
    temp_matrix.n = a->n;

    double complex temp_mat_vals[temp_matrix.m * temp_matrix.n];
    temp_matrix.values = temp_mat_vals;


    int givens_counter = 0;

    for (size_t r = 1; r < a->m; ++r)
    {
        for (size_t c = 0; c < r; ++c)
        {
            if (cabs(dest->values[r * dest->n + c]) < 0.000000000000001)
            {
                //Skip the identity givens.
                continue;
            }


            if (!matrix_get_givens(&givens[givens_counter], dest, r, c))
            {
                return -1;
            }


            if (!matrix_copy_to(&temp_matrix, dest))
            {
                return -1;
            }


            if (!matrix_multiply_matrix(dest, &givens[givens_counter], &temp_matrix))
            {
                return -1;
            }


            givens_counter++;
        }
    }


    return givens_counter;
}


//Eigen Operations:
bool matrix_decompose_eigens(eigen_decomp* dest, const matrix* a, size_t max_iterations)
{
    if (dest->eigen_vectors->m != a->m && dest->eigen_vectors->n != a->n)
    {
        return false;
    }

    if (a->m != a->n)
    {
        return false;
    }


    //This will be used as a buffer for mathematical operations.
    matrix temp_matrix;
    temp_matrix.m = a->m;
    temp_matrix.n = a->n;

    double complex temp_vals[temp_matrix.m * temp_matrix.n];
    temp_matrix.values = temp_vals;


    size_t givens_max = a->n * (a->n + 1) / 2;    //This is just the number of elements below the diagonal.
    matrix givens[givens_max];
    for (size_t j = 0; j < givens_max; ++j)
    {
        givens[j].m = a->m;
        givens[j].n = a->n;

        givens[j].values = malloc(givens[j].m * givens[j].n * sizeof(double complex));
    }


    matrix_create_identity(dest->eigen_vectors);


    matrix a_i;
    a_i.m = a->m;
    a_i.n = a->n;

    double complex a_i_vals[a_i.m * a_i.n];
    a_i.values = a_i_vals;

    matrix_copy_to(&a_i, a);


    matrix a_super;
    a_super.m = a->m;
    a_super.n = a->n;

    double complex a_super_vals[a_super.m * a_super.n];
    a_super.values = a_super_vals;

    matrix_copy_to(&a_super, a);


    double complex mu = 0;

    for (size_t i = 0; i < max_iterations; ++i)
    {
        //matrix temp_matrix_aI;
        //temp_matrix_aI.m = a_i.m;
        //temp_matrix_aI.n = a_i.n;

        //double complex temp_matrix_aI_vals[temp_matrix_aI.m * temp_matrix_aI.n];
        //temp_matrix_aI.values = temp_matrix_aI_vals;

        //You can reset the size of the temp matrix to make things work. Get that mu goin.
        //Use https://web.stanford.edu/class/cme335/lecture5 for the Wilkinson shift.

        matrix R;
        R.m = a_i.m;
        R.n = a_i.n;

        double complex R_vals[R.m * R.n];
        R.values = R_vals;


        int num_givens = matrix_triangle_upper(&R, &a_i, givens);


        matrix Q;
        Q.m = a_i.m;
        Q.n = a_i.n;

        double complex Q_vals[Q.m * Q.n];
        Q.values = Q_vals;

        switch (num_givens)
        {
            case -1:
                return false;


            case 0:
                matrix_create_identity(&Q);
                break;


            default:
                matrix_copy_to(&Q, givens + num_givens - 1);

                for (long j = num_givens - 2; j >= 0; --j)
                {
                    matrix_multiply_matrix(&temp_matrix, &Q, givens + j);
                    matrix_copy_to(&Q, &temp_matrix);
                }

                matrix_transpose(&Q, &Q);   //This operation can be done in-place.
                break;
        }


        matrix_multiply_matrix(&a_i, &R, &Q);


        matrix_multiply_matrix(&temp_matrix, dest->eigen_vectors, &Q);
        matrix_copy_to(dest->eigen_vectors, &temp_matrix);
    }


    for (size_t i = 0; i < givens_max; ++i)
    {
        free(givens[i].values);
    }


    for (size_t rc = 0; rc < a_i.m; ++rc)
    {
        dest->eigen_values[rc] = a_i.values[rc * a_i.n + rc];
    }


    matrix schur_converter;
    schur_converter.m = a_i.m;
    schur_converter.n = a_i.n;

    double complex schur_converter_vals[schur_converter.m * schur_converter.n];
    schur_converter.values = schur_converter_vals;

    matrix_create_identity(&schur_converter);


    for (size_t c = 1; c < schur_converter.n; ++c)
    {
        matrix inner_temp_matrix;
        inner_temp_matrix.m = c;
        inner_temp_matrix.n = c;

        double complex inner_temp_matrix_vals[inner_temp_matrix.m * inner_temp_matrix.n];
        inner_temp_matrix.values = inner_temp_matrix_vals;


        matrix upper_biased_factor;
        upper_biased_factor.m = c;
        upper_biased_factor.n = c;

        double complex upper_biased_factor_vals[upper_biased_factor.m * upper_biased_factor.n];
        upper_biased_factor.values = upper_biased_factor_vals;


        matrix_create_identity_scaled(&upper_biased_factor, a_i.values[c * a_i.n + c]);


        matrix sub_temp_matrix;
        sub_temp_matrix.m = c;
        sub_temp_matrix.n = c;

        double complex sub_temp_matrix_vals[sub_temp_matrix.m * sub_temp_matrix.n];
        sub_temp_matrix.values = sub_temp_matrix_vals;


        matrix_get_submatrix_lengths(&sub_temp_matrix, &a_i, 0, c, 0, c);


        matrix_subtract_matrix(&inner_temp_matrix, &upper_biased_factor, &sub_temp_matrix);
        matrix_copy_to(&upper_biased_factor, &inner_temp_matrix);

        matrix_inverse(&inner_temp_matrix, &upper_biased_factor);
        matrix_copy_to(&upper_biased_factor, &inner_temp_matrix);


        vector temp_vector;
        temp_vector.n = c;

        double complex temp_vector_vals[temp_vector.n];
        temp_vector.values = temp_vector_vals;


        vector column_vector;
        column_vector.n = c;

        double complex column_vector_vals[column_vector.n];
        column_vector.values = column_vector_vals;

        matrix_get_column_length(&column_vector, &a_i, c, 0, c);


        bool passed = matrix_multiply_vector(&temp_vector, &upper_biased_factor, &column_vector);


        for (size_t r = 0; r < c; ++r)
        {
            schur_converter.values[r * schur_converter.n + c] = temp_vector.values[r];
        }
    }


    matrix_multiply_matrix(&temp_matrix, dest->eigen_vectors, &schur_converter);
    matrix_copy_to(dest->eigen_vectors, &temp_matrix);


    return true;
}


//Other Operations:
bool matrix_copy_to(matrix* dest, const matrix* a)
{
    if (dest->m != a->n && dest->n != a->m)
    {
        return false;
    }


    for (size_t i = 0; i < a->m * a->n; ++i)
    {
        dest->values[i] = a->values[i];
    }


    return true;
}


size_t matrix_to_str(char* output, size_t output_size, const matrix* a, short decimals)
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

            complex_nice_str(temp_num, 32, a->values[r * a->n + c], decimals);

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

            complex_nice_str(temp_num, 32, a->values[r * a->n + c], decimals);

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


size_t matrix_to_str_10dec(char* output, size_t output_size, const matrix* a)
{
    return matrix_to_str(output, output_size, a, 10);
}

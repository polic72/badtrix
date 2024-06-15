#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

//#include <check.h>    //I'm eventually going to use automake and do all that junk, but I'm fine with just a main file for now.

#include "extras.h"
#include "matrix.h"
#include "vector.h"


double quick_random_double()
{
    uint64_t r53 = ((uint64_t)(rand()) << 21) ^ (rand() >> 2);

    return (double)r53 / 9007199254740991.0; // 2^53 - 1
}


int main()
{
//    vector v;
//
//    v.n = 3;
//
//    double temp[v.n];
//    
//    v.values = temp;
//
//    for (unsigned int i = 0; i < v.n; ++i)
//    {
//        printf("%d\n", temp[i]);
//    }


    //matrix a;
    //a.m = 2;
    //a.n = 2;
//
    //double a_values[] = { 1, 2, 3, 4 };
//
    //a.values = a_values;
//
//
    //for (unsigned int i = 0; i < a.m; ++i)
    //{
//
    //}





    //Round 2
    //vector v;
    //v.n = 5;

    //double vals[] = { 1, 2.24, 3, -4, 123 };
    //v.values = vals;


    //char v_str[256];

    //vector_to_str(v_str, 256, &v);


    //printf("%s\n", v_str);
    

    ////char hmm[128];

    ////double_nice_str_10dec(hmm, 128, v.values[3]);

    ////printf("%s, %d\n", hmm, strlen(hmm));


    //printf("\n\n");


    //matrix a;
    //a.m = 3;
    //a.n = 3;

    //double a_vals[] = { 1, 2, -3, 4, 5.55, 6, 7, -8.245, 9 };
    //a.values = a_vals;


    //char a_str[256];

    //matrix_to_str_10dec(a_str, 256, &a);


    //printf("%s\n", a_str);


    //printf("\n\n");


    //matrix b;
    //b.m = 2;
    //b.n = 2;

    //double b_vals[] = { 1, 6.5, -2, -0.25 };
    //b.values = b_vals;


    //char b_str[256];

    //matrix_to_str_10dec(b_str, 256, &b);


    //printf("%s\n", b_str);
    

    matrix det_mat_1;
    det_mat_1.m = 2;
    det_mat_1.n = 2;

    double det_mat_1_vals[] = { 1, 4, 2, 3 };
    det_mat_1.values = det_mat_1_vals;

    char det_mat_1_str[256];

    matrix_to_str_10dec(det_mat_1_str, 256, &det_mat_1);
    printf("%s\n", det_mat_1_str);

    double det_1;
    matrix_determinant(&det_1, &det_mat_1);
    printf("determinant = %f\n", det_1);


    printf("\n\n");


    matrix det_mat_2;
    det_mat_2.m = 3;
    det_mat_2.n = 3;

    double det_mat_2_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    det_mat_2.values = det_mat_2_vals;

    char det_mat_2_str[256];

    matrix_to_str_10dec(det_mat_2_str, 256, &det_mat_2);
    printf("%s\n", det_mat_2_str);

    double det_2;
    matrix_determinant(&det_2, &det_mat_2);
    printf("determinant = %f\n", det_2);


    printf("\n\n");


    matrix det_mat_3;
    det_mat_3.m = 4;
    det_mat_3.n = 4;

    double det_mat_3_vals[] = { 1, 2, 3, 1, 4, 5, 6, -1, 7, 8, 9, 5, 6, 4, 8, 0 };
    det_mat_3.values = det_mat_3_vals;

    char det_mat_3_str[256];

    matrix_to_str_10dec(det_mat_3_str, 256, &det_mat_3);
    printf("%s\n", det_mat_3_str);

    double det_3;
    matrix_determinant(&det_3, &det_mat_3);
    printf("determinant = %f\n", det_3);


    printf("\n\n");


    matrix min_mat_1;
    min_mat_1.m = 3;
    min_mat_1.n = 3;

    double min_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    min_mat_1.values = min_mat_1_vals;

    char min_mat_1_str[256];

    matrix_to_str_10dec(min_mat_1_str, 256, &min_mat_1);
    printf("%s\n", min_mat_1_str);

    printf("matrix of minors:\n");

    matrix min_mat_1_out;
    min_mat_1_out.m = 3;
    min_mat_1_out.n = 3;

    double min_mat_1_out_vals[min_mat_1_out.m * min_mat_1_out.n];
    min_mat_1_out.values = min_mat_1_out_vals;

    matrix_of_minors(&min_mat_1_out, &min_mat_1);

    char min_mat_1_out_str[256];

    matrix_to_str_10dec(min_mat_1_out_str, 256, &min_mat_1_out);
    printf("%s\n", min_mat_1_out_str);


    printf("\n\n");


    matrix adj_mat_1;
    adj_mat_1.m = 3;
    adj_mat_1.n = 3;

    double adj_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    adj_mat_1.values = adj_mat_1_vals;

    char adj_mat_1_str[256];

    matrix_to_str_10dec(adj_mat_1_str, 256, &adj_mat_1);
    printf("%s\n", adj_mat_1_str);

    printf("adjoint matrix:\n");

    matrix adj_mat_1_out;
    adj_mat_1_out.m = 3;
    adj_mat_1_out.n = 3;

    double adj_mat_1_out_vals[adj_mat_1_out.m * adj_mat_1_out.n];
    adj_mat_1_out.values = adj_mat_1_out_vals;

    matrix_adjoint(&adj_mat_1_out, &adj_mat_1);

    char adj_mat_1_out_str[256];

    matrix_to_str_10dec(adj_mat_1_out_str, 256, &adj_mat_1_out);
    printf("%s\n", adj_mat_1_out_str);


    printf("\n\n");


    matrix inv_mat_1;
    inv_mat_1.m = 3;
    inv_mat_1.n = 3;

    double inv_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    inv_mat_1.values = inv_mat_1_vals;

    char inv_mat_1_str[256];

    matrix_to_str_10dec(inv_mat_1_str, 256, &inv_mat_1);
    printf("%s\n", inv_mat_1_str);

    printf("inverse matrix:\n");

    matrix inv_mat_1_out;
    inv_mat_1_out.m = 3;
    inv_mat_1_out.n = 3;

    double inv_mat_1_out_vals[inv_mat_1_out.m * inv_mat_1_out.n];
    inv_mat_1_out.values = inv_mat_1_out_vals;

    matrix_inverse(&inv_mat_1_out, &inv_mat_1);

    char inv_mat_1_out_str[256];

    matrix_to_str_10dec(inv_mat_1_out_str, 256, &inv_mat_1_out);
    printf("%s\n", inv_mat_1_out_str);


    printf("\n\n");


    int givens_spot_r = 2;
    int givens_spot_c = 0;

    matrix given_mat_1;
    given_mat_1.m = 3;
    given_mat_1.n = 3;

    double given_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    given_mat_1.values = given_mat_1_vals;

    char given_mat_1_str[256];

    matrix_to_str(given_mat_1_str, 256, &given_mat_1, 16);
    printf("%s\n", given_mat_1_str);

    printf("givens matrix for (%d, %d):\n", givens_spot_r, givens_spot_c);

    matrix given_mat_1_out;
    given_mat_1_out.m = 3;
    given_mat_1_out.n = 3;

    double given_mat_1_out_vals[given_mat_1_out.m * given_mat_1_out.n];
    given_mat_1_out.values = given_mat_1_out_vals;

    matrix_get_givens(&given_mat_1_out, &given_mat_1, givens_spot_r, givens_spot_c);

    char given_mat_1_out_str[256];

    matrix_to_str(given_mat_1_out_str, 256, &given_mat_1_out, 16);
    printf("%s\n", given_mat_1_out_str);


    printf("\n\n");


    ////srand(time(NULL));
    //srand(1);

    //matrix det_mat_big;
    //det_mat_big.m = 16;
    //det_mat_big.n = 16;

    //double det_mat_big_vals[det_mat_big.m * det_mat_big.n];
    //for (int r = 0; r < det_mat_big.m; ++r)
    //{
        //for (int c = 0; c < det_mat_big.n; ++c)
        //{
            //det_mat_big_vals[r * det_mat_big.n + c] = quick_random_double();
        //}
    //}

    //det_mat_big.values = det_mat_big_vals;

    //char det_mat_big_str[131072];

    //matrix_to_str_10dec(det_mat_big_str, 131072, &det_mat_big);
    //printf("%s\n", det_mat_big_str);

    //double det_big;
    //matrix_determinant(&det_big, &det_mat_big);
    //printf("determinant = %f\n", det_big);


    //printf("\n\n");


    matrix upt_mat_1;
    upt_mat_1.m = 3;
    upt_mat_1.n = 3;

    double upt_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    upt_mat_1.values = upt_mat_1_vals;

    char upt_mat_1_str[256];

    matrix_to_str_10dec(upt_mat_1_str, 256, &upt_mat_1);
    printf("%s\n", upt_mat_1_str);

    matrix upt_mat_1_out;
    upt_mat_1_out.m = 3;
    upt_mat_1_out.n = 3;

    double upt_mat_1_out_vals[upt_mat_1_out.m * upt_mat_1_out.n];
    upt_mat_1_out.values = upt_mat_1_out_vals;


    size_t givens_max = upt_mat_1_out.n * (upt_mat_1_out.n + 1) / 2;
    matrix upt_mat_givens[givens_max];

    for (size_t i = 0; i < givens_max; ++i)
    {
        upt_mat_givens[i].m = upt_mat_1.m;
        upt_mat_givens[i].n = upt_mat_1.n;

        upt_mat_givens[i].values = malloc(upt_mat_givens[i].m * upt_mat_givens[i].n * sizeof(double));
    }

    size_t givens_count = matrix_triangle_upper(&upt_mat_1_out, &upt_mat_1, upt_mat_givens);
    printf("givens count = %d\n", givens_count);

    printf("upper-triangle converted matrix:\n");

    char upt_mat_1_out_str[256];

    matrix_to_str_10dec(upt_mat_1_out_str, 256, &upt_mat_1_out);
    printf("%s\n", upt_mat_1_out_str);

    for (size_t i = 0; i < givens_max; ++i)
    {
        free(upt_mat_givens[i].values);
    }


    printf("\n\n");


    size_t QR_mat_1_iterations = 1000;

    matrix QR_mat_1;
    QR_mat_1.m = 3;
    QR_mat_1.n = 3;

    double QR_mat_1_vals[] = { 1, -2, 3, -2, 5, 8, 3, 8, 9 };   //Symmetric first.
    QR_mat_1.values = QR_mat_1_vals;


    eigen_decomp QR_mat_1_eigens;

    double QR_mat_1_eigen_vals[QR_mat_1.m];
    QR_mat_1_eigens.eigen_values = QR_mat_1_eigen_vals;

    matrix QR_mat_1_eigen_vectors;
    QR_mat_1_eigen_vectors.m = QR_mat_1.m;
    QR_mat_1_eigen_vectors.n = QR_mat_1.n;

    double QR_mat_1_eigen_vectors_vals[QR_mat_1_eigen_vectors.m * QR_mat_1_eigen_vectors.n];
    QR_mat_1_eigen_vectors.values = QR_mat_1_eigen_vectors_vals;

    QR_mat_1_eigens.eigen_vectors = &QR_mat_1_eigen_vectors;


    char QR_mat_1_str[256];

    matrix_to_str(QR_mat_1_str, 256, &QR_mat_1, 16);
    printf("%s\n", QR_mat_1_str);

    matrix_decompose_eigens(&QR_mat_1_eigens, &QR_mat_1, QR_mat_1_iterations);

    printf("eigen decomp for %d iterations:\n", QR_mat_1_iterations);

    printf("eigen values = [");
    for (size_t i = 0; i < QR_mat_1.m; ++i)
    {
        if (i != 0)
        {
            printf(", ");
        }

        char QR_mat_1_eigenvalue_out_str[256];

        double_nice_str(QR_mat_1_eigenvalue_out_str, 256, QR_mat_1_eigens.eigen_values[i], 16);

        printf("%s", QR_mat_1_eigenvalue_out_str);
    }
    printf("]\n");

    printf("eigen vectors = \n");
    matrix QR_mat_1_eigenvectors_copy;
    QR_mat_1_eigenvectors_copy.m = QR_mat_1_eigens.eigen_vectors->m;
    QR_mat_1_eigenvectors_copy.n = QR_mat_1_eigens.eigen_vectors->n;

    double QR_mat_1_eigenvectors_copy_vals[QR_mat_1_eigenvectors_copy.m * QR_mat_1_eigenvectors_copy.n];
    QR_mat_1_eigenvectors_copy.values = QR_mat_1_eigenvectors_copy_vals;

    matrix_copy_to(&QR_mat_1_eigenvectors_copy, QR_mat_1_eigens.eigen_vectors);

    for (size_t c = 0; c < QR_mat_1_eigenvectors_copy.n; ++c)
    {
        double denom = QR_mat_1_eigenvectors_copy.values[(QR_mat_1_eigenvectors_copy.m - 1) * QR_mat_1_eigenvectors_copy.n + c];

        for (size_t r = 0; r < QR_mat_1_eigenvectors_copy.m; ++r)
        {
            QR_mat_1_eigenvectors_copy.values[r * QR_mat_1_eigenvectors_copy.n + c] /= denom;
        }
    }


    char QR_mat_1_eigenvectors_out_str[256];

    matrix_to_str(QR_mat_1_eigenvectors_out_str, 256, &QR_mat_1_eigenvectors_copy, 16);
    printf("%s\n", QR_mat_1_eigenvectors_out_str);


    return 0;
}

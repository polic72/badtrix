#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include <check.h>    //I'm eventually going to use automake and do all that junk, but I'm fine with just a main file for now.

#include "extras.h"
#include "matrix.h"
#include "vector.h"


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

    //matrix_to_str(a_str, 256, &a);


    //printf("%s\n", a_str);


    //printf("\n\n");


    //matrix b;
    //b.m = 2;
    //b.n = 2;

    //double b_vals[] = { 1, 6.5, -2, -0.25 };
    //b.values = b_vals;


    //char b_str[256];

    //matrix_to_str(b_str, 256, &b);


    //printf("%s\n", b_str);
    

    matrix det_mat_1;
    det_mat_1.m = 2;
    det_mat_1.n = 2;

    double det_mat_1_vals[] = { 1, 4, 2, 3 };
    det_mat_1.values = det_mat_1_vals;

    char det_mat_1_str[256];

    matrix_to_str(det_mat_1_str, 256, &det_mat_1);
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

    matrix_to_str(det_mat_2_str, 256, &det_mat_2);
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

    matrix_to_str(det_mat_3_str, 256, &det_mat_3);
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

    matrix_to_str(min_mat_1_str, 256, &min_mat_1);
    printf("%s\n", min_mat_1_str);

    printf("matrix of minors:\n");

    matrix min_mat_1_out;
    min_mat_1_out.m = 3;
    min_mat_1_out.n = 3;

    double min_mat_1_out_vals[min_mat_1_out.m * min_mat_1_out.n];
    min_mat_1_out.values = min_mat_1_out_vals;

    matrix_of_minors(&min_mat_1_out, &min_mat_1);

    char min_mat_1_out_str[256];

    matrix_to_str(min_mat_1_out_str, 256, &min_mat_1_out);
    printf("%s\n", min_mat_1_out_str);


    printf("\n\n");


    matrix adj_mat_1;
    adj_mat_1.m = 3;
    adj_mat_1.n = 3;

    double adj_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    adj_mat_1.values = adj_mat_1_vals;

    char adj_mat_1_str[256];

    matrix_to_str(adj_mat_1_str, 256, &adj_mat_1);
    printf("%s\n", adj_mat_1_str);

    printf("adjoint matrix:\n");

    matrix adj_mat_1_out;
    adj_mat_1_out.m = 3;
    adj_mat_1_out.n = 3;

    double adj_mat_1_out_vals[adj_mat_1_out.m * adj_mat_1_out.n];
    adj_mat_1_out.values = adj_mat_1_out_vals;

    matrix_adjoint(&adj_mat_1_out, &adj_mat_1);

    char adj_mat_1_out_str[256];

    matrix_to_str(adj_mat_1_out_str, 256, &adj_mat_1_out);
    printf("%s\n", adj_mat_1_out_str);


    printf("\n\n");


    matrix inv_mat_1;
    inv_mat_1.m = 3;
    inv_mat_1.n = 3;

    double inv_mat_1_vals[] = { 1, 5, 3, 4, 5, 6, 7, 8, 9 };
    inv_mat_1.values = inv_mat_1_vals;

    char inv_mat_1_str[256];

    matrix_to_str(inv_mat_1_str, 256, &inv_mat_1);
    printf("%s\n", inv_mat_1_str);

    printf("inverse matrix:\n");

    matrix inv_mat_1_out;
    inv_mat_1_out.m = 3;
    inv_mat_1_out.n = 3;

    double inv_mat_1_out_vals[inv_mat_1_out.m * inv_mat_1_out.n];
    inv_mat_1_out.values = inv_mat_1_out_vals;

    matrix_inverse(&inv_mat_1_out, &inv_mat_1);

    char inv_mat_1_out_str[256];

    matrix_to_str(inv_mat_1_out_str, 256, &inv_mat_1_out);
    printf("%s\n", inv_mat_1_out_str);


    return 0;
}

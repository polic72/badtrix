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


    vector v;
    v.n = 5;

    double vals[] = { 1, 2.24, 3, -4, 123 };
    v.values = vals;


    char v_str[256];

    vector_to_str(v_str, 256, &v);


    printf("%s\n", v_str);
    

    //char hmm[128];

    //double_nice_str_10dec(hmm, 128, v.values[3]);

    //printf("%s, %d\n", hmm, strlen(hmm));


    printf("\n\n");


    matrix a;
    a.m = 3;
    a.n = 3;

    double a_vals[] = { 1, 2, -3, 4, 5.55, 6, 7, -8.245, 9 };
    a.values = a_vals;


    char a_str[256];

    matrix_to_str(a_str, 256, &a);


    printf("%s\n", a_str);


    printf("\n\n");


    matrix b;
    b.m = 2;
    b.n = 2;

    double b_vals[] = { 1, 6.5, -2, -0.25 };
    b.values = b_vals;


    char b_str[256];

    matrix_to_str(b_str, 256, &b);


    printf("%s\n", b_str);


    return 0;
}

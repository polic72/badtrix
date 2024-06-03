#include <stdio.h>
#include <stdlib.h>
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
    v.n = 3;

    double vals[] = { 1, 2, 3 };
    v.values = vals;

    vector_to_str(NULL, 0, &v);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "vector.h"


int sum(size_t n, int array[n]);

int main(int argc, char** argv)
{
//    vector v;
//
//    v.n = argc;
//    //v.values = double arr[v.n];
//
//    int arr[v.n];
//
//    for (unsigned int i = 0; i < v.n; ++i)
//    {
//        printf("%d\n", arr[i]);
//    }


    size_t count = 5;

    int arr[] = { 1, 2, 3, 4, 5 };


    printf("sum = %d\n", sum(count, arr));


    int* heap = malloc(count * sizeof(int));

    heap[0] = 1;
    heap[1] = 2;
    heap[2] = 3;
    heap[3] = 4;
    heap[4] = 5;


    printf("heap sum = %d\n", sum(count + 1, heap));


    return 0;
}


int sum(size_t n, int array[n])
{
    int sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        sum += array[i];
    }

    return sum;
}

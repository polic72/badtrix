#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "vector.h"


int main()
{
    vector v;

    v.n = 3;

    double temp[v.n];
    
    v.values = temp;

    for (unsigned int i = 0; i < v.n; ++i)
    {
        printf("%d\n", temp[i]);
    }

    return 0;
}

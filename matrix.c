#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"


bool matrix_add_value(matrix* dest, matrix* a, double x)
{
    for (size_t r = 0; r < a->m; ++r)
    {
        for (size_t c = 0; c < a->n; ++c)
        {
            dest->values[r * c + c] = a->values[r * c + c] + x;
        }
    }

    return true;
}

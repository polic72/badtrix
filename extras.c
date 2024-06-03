#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "extras.h"


size_t double_nice_str(char* output, size_t output_size, double val, short decimals)
{
    char temp[100];

    snprintf(temp, 100, "%.*g", decimals, ((int)(pow(10, decimals) * (fabs(val) - abs((int)val)) + 0.5)) / pow(10, decimals));

    return snprintf(output, output_size, "%d%s", (int)val, temp + 1);
}


size_t double_nice_str_10dec(char* output, size_t output_size, double val)
{
    return double_nice_str(output, output_size, val, 10);
}

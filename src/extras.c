#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#include "../include/extras.h"


size_t double_nice_str(char* output, size_t output_size, double val, short decimals)
{
    char temp[100];

    snprintf(temp, 100, "%.*g", decimals, 
            ((long)(pow(10, decimals) * (fabs(val) - labs((long)val)) + 0.5)) / pow(10, decimals));

    if ((int)val == 0 && val < 0)
    {
        return snprintf(output, output_size, "-%d%s", (int)val, temp + 1);
    }

    return snprintf(output, output_size, "%d%s", (int)val, temp + 1);
}


size_t double_nice_str_10dec(char* output, size_t output_size, double val)
{
    return double_nice_str(output, output_size, val, 10);
}


size_t complex_nice_str(char* output, size_t output_size, double complex val, short decimals)
{
    int write_pos = 0;


    char dec_comp[100];

    double real = creal(val);

    snprintf(dec_comp, 100, "%.*g", decimals, 
            ((long)(pow(10, decimals) * (fabs(real) - labs((long)real)) + 0.5)) / pow(10, decimals));

    if ((int)real == 0 && real < 0)
    {
        write_pos += snprintf(output, output_size, "(-%d%s", (int)real, dec_comp + 1);
    }
    else
    {
        write_pos += snprintf(output, output_size, "(%d%s", (int)real, dec_comp + 1);
    }


    double imag = cimag(val);

    snprintf(dec_comp, 100, "%.*g", decimals, 
            ((long)(pow(10, decimals) * (fabs(imag) - labs((long)imag)) + 0.5)) / pow(10, decimals));

    if ((int)imag == 0 && imag < 0)
    {
        write_pos += snprintf(output + write_pos, output_size - write_pos, ", -%d%s)", (int)imag, dec_comp + 1);
    }
    else
    {
        write_pos += snprintf(output + write_pos, output_size - write_pos, ", %d%s)", (int)imag, dec_comp + 1);
    }


    return write_pos;
}


size_t complex_nice_str_10dec(char* output, size_t output_size, double complex val)
{
    return complex_nice_str(output, output_size, val, 10);
}

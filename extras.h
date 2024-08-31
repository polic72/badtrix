#ifndef EXTRAS_H
#define EXTRAS_H

#include <stdlib.h>
#include <complex.h>


size_t double_nice_str(char* output, size_t output_size, double val, short decimals);
size_t double_nice_str_10dec(char* output, size_t output_size, double val);

size_t complex_nice_str(char* output, size_t output_size, double complex val, short decimals);
size_t complex_nice_str_10dec(char* output, size_t output_size, double complex val);


#endif

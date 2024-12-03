#ifndef UTILS_H
#define UTILS_H

#include <gmp.h>
#include <stdio.h>
#include <stdbool.h>

void print_variable(const char *var_name, mpz_t value, bool extra_newline);

#endif
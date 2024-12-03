#ifndef UTILS_H
#define UTILS_H

#include <gmp.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_variable(const char *var_name, mpz_t value, bool extra_newline);

void string_to_mpz(mpz_t result, const char *str);

void mpz_to_string(char *str, mpz_t value);

#endif
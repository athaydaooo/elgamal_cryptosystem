#include "utils.h"
#include <stdlib.h>

void print_variable(const char *var_name, mpz_t value, bool extra_newline) {
    printf("%s = ", var_name);
    gmp_printf("%Zd", value); 

    printf("\n");
    
    if (extra_newline) {
        printf("\n");
        printf("------------------------------------\n");
        printf("\n");
    }
    
}

void string_to_mpz(mpz_t result, const char *str) {
    size_t len = strlen(str);
    mpz_set_ui(result, 0);  // Inicializa result como 0

    // Converter cada caractere da string para um número e concatenar
    for (size_t i = 0; i < len; i++) {
        mpz_mul_ui(result, result, 256);  // Multiplica por 256 (base para os caracteres ASCII)
        mpz_add_ui(result, result, (unsigned char)str[i]);  // Adiciona o valor do caractere
    }
}

void mpz_to_string(char *str, mpz_t value) {
    size_t length = mpz_sizeinbase(value, 256) + 1;
    char *buffer = (char *)malloc(length);

    mpz_export(buffer, &length, 1, 1, 0, 0, value);
    strncpy(str, buffer, length);

    free(buffer);
}
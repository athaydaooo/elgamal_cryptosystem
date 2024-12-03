#include "utils.h"

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
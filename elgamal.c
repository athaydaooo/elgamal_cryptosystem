#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///fazendo o calculo exponencial modular | (base^exp) % mod.
long long int mod_exp(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    base = base % mod; ///melhorando a eficiencia do codigo ao usar numeros menores.
    while (exp > 0) {
        if (exp % 2 == 1) { ///se for ímpar multiplicados result por base e aplicamos o modulo.
            result = (result * base) % mod;
        }
        exp = exp >> 1; ///Dividindo o exp pela metade.
        base = (base * base) % mod; ///elevamos a base ao quadrado e aplicamos o modulo.
    }
    return result;
}

///Gerando a chave publica e privada
void gerar_chaves(long long int *p, long long int *r, long long int *x, long long int *a) {
    srand(time(NULL)); ///iniciando o srand
    *p = 997;    ///número primo grande
    *r = 5;      ///raiz primitiva de p
    *x = rand() % (*p - 1) + 1; ///chave privada
    *a = mod_exp(*r, *x, *p);    ///chave pública
}

// Função para criptografar um bloco da mensagem
void criptografar(long long int p, long long int r, long long int a, long long int m, long long int *c1, long long int *c2) {
    long long int k = rand() % (p - 1) + 1;  // Valor aleatório
    *c1 = mod_exp(r, k, p);                  // C1 = r^k mod p
    *c2 = (m * mod_exp(a, k, p)) % p;        // C2 = m * a^k mod p
}

// Função para descriptografar um bloco da mensagem
long long int descriptografar(long long int p, long long int x, long long int c1, long long int c2) {
    long long int s = mod_exp(c1, x, p);     // s = c1^x mod p
    long long int s_inv = mod_exp(s, p - 2, p); // inverso multiplicativo de s mod p
    return (c2 * s_inv) % p;                 // mensagem original m = c2 * s_inv mod p
}

// Função para criptografar a mensagem completa
void criptografar_mensagem(char *mensagem, long long int p, long long int r, long long int a, long long int *c1_array, long long int *c2_array) {
    for (int i = 0; i < strlen(mensagem); i++) {
        long long int m = mensagem[i];
        criptografar(p, r, a, m, &c1_array[i], &c2_array[i]);
    }
}

// Função para descriptografar a mensagem completa
void descriptografar_mensagem(long long int *c1_array, long long int *c2_array, int length, long long int p, long long int x, char *mensagem_decifrada) {
    for (int i = 0; i < length; i++) {
        long long int m = descriptografar(p, x, c1_array[i], c2_array[i]);
        mensagem_decifrada[i] = (char)m;
    }
    mensagem_decifrada[length] = '\0';
}

int main() {
    long long int p, r, x, a;                // p e r são parâmetros públicos; x e a são a chave privada e pública
    char mensagem[256];
    char mensagem_decifrada[256];
    long long int c1_array[256], c2_array[256]; // Arrays para armazenar C1 e C2 de cada caractere

    // Geração das chaves
    gerar_chaves(&p, &r, &x, &a);
    printf("Chave pública (p, r, a): (%lld, %lld, %lld)\n", p, r, a);
    printf("Chave p ada x: %lld\n", x);

    // Entrada da mensagem
    printf("Digite a mensagem para criptografar: ");
    fgets(mensagem, 256, stdin);
    mensagem[strcspn(mensagem, "\n")] = 0; // Remove o caractere de nova linha

    // Criptografia da mensagem completa
    criptografar_mensagem(mensagem, p, r, a, c1_array, c2_array);
    printf("Mensagem criptografada:\n");
    for (int i = 0; i < strlen(mensagem); i++) {
        printf("(C1 = %lld, C2 = %lld) ", c1_array[i], c2_array[i]);
    }
    printf("\n");

    // Descriptografia da mensagem completa
    descriptografar_mensagem(c1_array, c2_array, strlen(mensagem), p, x, mensagem_decifrada);
    printf("Mensagem descriptografada: %s\n", mensagem_decifrada);

    return 0;
}

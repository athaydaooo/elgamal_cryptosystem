#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

typedef struct {
    mpz_t p; // Primo grande
    mpz_t r; // Raiz primitiva de p
    mpz_t a; // Chave pública
} PublicKey;

typedef struct {
    mpz_t x; // Chave privada
} PrivateKey;

typedef struct {
    PublicKey pub;
    PrivateKey priv;
} ElGamal;

void init_elgamal(ElGamal *elgamal) {
    mpz_inits(elgamal->pub.p, elgamal->pub.r, elgamal->pub.a, elgamal->priv.x, NULL);
}

void generate_keys(ElGamal *elgamal, int bits) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));
    
    mpz_t q;
    mpz_init(q);
    
    // Gerando um número primo grande p
    mpz_urandomb(q, state, bits - 1);
    mpz_nextprime(elgamal->pub.p, q);
    
    // Gerando a raiz primitiva r de p
    mpz_urandomm(elgamal->pub.r, state, elgamal->pub.p);
    
    // Gerando a chave privada x
    mpz_urandomm(elgamal->priv.x, state, elgamal->pub.p);
    
    // Calculando a chave pública a = r^x mod p
    mpz_powm(elgamal->pub.a, elgamal->pub.r, elgamal->priv.x, elgamal->pub.p);
    
    mpz_clear(q);
}

void encrypt(mpz_t c1, mpz_t c2, ElGamal *elgamal, mpz_t message) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));

    mpz_t k, p;
    mpz_inits(k, p, NULL);
    mpz_set(p, elgamal->pub.p);
    
    // Gerar valor aleatório k
    mpz_urandomm(k, state, elgamal->pub.p);
    
    // c1 = r^k mod p
    mpz_powm(c1, elgamal->pub.r, k, p);
    
    // c2 = m * (a^k mod p)
    mpz_t ak;
    mpz_init(ak);
    mpz_powm(ak, elgamal->pub.a, k, p);
    mpz_mul(c2, message, ak);
    mpz_mod(c2, c2, p);
    
    mpz_clears(k, ak, NULL);
}

void decrypt(mpz_t decrypted, ElGamal *elgamal, mpz_t c1, mpz_t c2) {
    mpz_t p, cx;
    mpz_inits(p, cx, NULL);
    mpz_set(p, elgamal->pub.p);
    
    // c1^x mod p
    mpz_powm(cx, c1, elgamal->priv.x, p);
    
    // (c1^x)^-1 mod p
    mpz_invert(cx, cx, p);
    
    // m = c2 * (c1^x)^-1 mod p
    mpz_mul(decrypted, c2, cx);
    mpz_mod(decrypted, decrypted, p);
    
    mpz_clears(cx, NULL);
}

void print_keys(ElGamal *elgamal) {
    gmp_printf("Chave pública (p, r, a): \np = %Zd\nr = %Zd\na = %Zd\n", elgamal->pub.p, elgamal->pub.r, elgamal->pub.a);
    gmp_printf("Chave privada (x): \nx = %Zd\n", elgamal->priv.x);
}

int main() {
    ElGamal elgamal;
    init_elgamal(&elgamal);
    
    // Gerar um par de chaves (tamanho de 512 bits)
    generate_keys(&elgamal, 512);
    
    // Exibir as chaves
    print_keys(&elgamal);

    // Mensagem a ser criptografada (deve ser menor que p)
    mpz_t message;
    mpz_init_set_ui(message, 12345); // Exemplo de mensagem
    
    // Criptografar
    mpz_t c1, c2;
    mpz_inits(c1, c2, NULL);
    encrypt(c1, c2, &elgamal, message);
    
    gmp_printf("Mensagem criptografada: \nc1 = %Zd\nc2 = %Zd\n", c1, c2);
    
    // Descriptografar
    mpz_t decrypted;
    mpz_init(decrypted);
    decrypt(decrypted, &elgamal, c1, c2);
    
    gmp_printf("Mensagem descriptografada: \n%Zd\n", decrypted);
    
    // Liberar memória
    mpz_clears(elgamal.pub.p, elgamal.pub.r, elgamal.pub.a, elgamal.priv.x, message, c1, c2, decrypted, NULL);
    
    return 0;
}
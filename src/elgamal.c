#include "elgamal.h"

Keypair* generate_keys(int bits) {
    Keypair *keypair = (Keypair *)malloc(sizeof(Keypair));

    mpz_inits(keypair->publicKey.bigPrime, keypair->publicKey.primitiveRoot, keypair->publicKey.key,
                keypair->privateKey.key, NULL);

    //Inicializa gerador de numero aleatório
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));
    
    //Inicializa numero aleatório
    mpz_t randomNumber;
    mpz_init(randomNumber);
    
    //Calcula proximo numero primo
    mpz_urandomb(randomNumber, state, bits - 1);
    mpz_nextprime(keypair->publicKey.bigPrime, randomNumber);
    
    //Gera a raiz primitiva r de p
    mpz_urandomm(keypair->publicKey.primitiveRoot, state, keypair->publicKey.bigPrime);
    
    //Gera a chave privada x
    mpz_urandomm(keypair->privateKey.key, state, keypair->publicKey.bigPrime);
    
    //Calcula a chave pública a = r^x mod p
    mpz_powm(keypair->publicKey.key, keypair->publicKey.primitiveRoot, keypair->privateKey.key, keypair->publicKey.bigPrime);
    
    //Limpa variavel temporaria (optimizar memoria)
    mpz_clear(randomNumber);

    return keypair;
}

void encrypt(mpz_t originalMessage, Keypair *keypair , EncryptedMessage *encryptedMessage) {
    //Inicializa gerador de numero aleatório
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));

    // Inicializa variáveis
    mpz_t randomKey, bigPrime;
    mpz_inits(randomKey, bigPrime, NULL);
    mpz_set(bigPrime, keypair->publicKey.bigPrime);
    
    // Gerar valor aleatório entre 1 e o primo grande
    mpz_urandomm(randomKey, state, keypair->publicKey.bigPrime);
    
    //Calcula o firstBlock onde  c1 = r^k mod p
    mpz_powm(encryptedMessage->firstCipher, keypair->publicKey.primitiveRoot, randomKey, bigPrime);
    
    //Calcula o segundo bloco onde c2 = m * (a^k mod p)
    mpz_t ak;
    mpz_init(ak);
    mpz_powm(ak, keypair->publicKey.key, randomKey, bigPrime);
    mpz_mul(encryptedMessage->secondCipher, originalMessage, ak);
    mpz_mod(encryptedMessage->secondCipher, encryptedMessage->secondCipher, bigPrime);
    
    //Limpa Variaveis temporarias
    mpz_clears(randomKey, ak, NULL);
}

void decrypt(mpz_t decryptedMessage, Keypair *keypair, const EncryptedMessage *encryptedMessage) {
    mpz_t bigPrime, cypher1Mod , cypher1ModInverse;
    mpz_inits(bigPrime, cypher1Mod, cypher1ModInverse, NULL);
    mpz_set(bigPrime, keypair->publicKey.bigPrime);

    // c1^x mod p
    mpz_powm(cypher1Mod, encryptedMessage->firstCipher, keypair->privateKey.key, bigPrime);

    // (c1^x)^-1 mod p
    mpz_invert(cypher1ModInverse, cypher1Mod, bigPrime);

    // m = c2 * (c1^x)^-1 mod p
    mpz_mul(decryptedMessage, encryptedMessage->secondCipher, cypher1ModInverse);
    mpz_mod(decryptedMessage, decryptedMessage, bigPrime);

    // Limpeza de variáveis temporárias
    mpz_clears(cypher1Mod, cypher1ModInverse, NULL);
}


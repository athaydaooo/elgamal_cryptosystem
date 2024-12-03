#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    mpz_t bigPrime; // Primo grande
    mpz_t primitiveRoot; // Raiz primitiva de p
    mpz_t key; // Chave pública
} PublicKey;

typedef struct {
    mpz_t key; // Chave privada
} PrivateKey;

typedef struct {
    PublicKey publicKey;
    PrivateKey privateKey;
} Keypair;

typedef struct {
    mpz_t firstCipher;
    mpz_t secondCipher;
} EncryptedMessage;

void decryptdecrypt(mpz_t decryptedMessage, Keypair *keypair, const EncryptedMessage *encryptedMessage);
void encrypt(mpz_t originalMessage, Keypair *keypair , EncryptedMessage *encryptedMessage);
Keypair* generate_keys(int bits);

#endif 
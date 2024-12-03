#include "elgamal.h"
#include "utils.h"

int main() {
    Keypair *keypair = generate_keys(512);
    printf("Chaves geradas com sucesso!\n\n");
    print_variable("Primo Grande", keypair->publicKey.bigPrime, false);
    print_variable("Raiz Primitiva", keypair->publicKey.primitiveRoot, false);
    print_variable("Chave Pública", keypair->publicKey.key, false);
    print_variable("Chave Privada", keypair->privateKey.key, true);

    mpz_t originalMessage;
    mpz_init_set_ui(originalMessage, 25565);
    print_variable("Mensagem Original", originalMessage, true);

    EncryptedMessage *encryptedMessage = (EncryptedMessage *)malloc(sizeof(EncryptedMessage));
    mpz_inits(encryptedMessage->firstCipher, encryptedMessage->secondCipher, NULL);
    encrypt(originalMessage, keypair, encryptedMessage);
    printf("Mensagem Criptografada com sucesso!\n\n");
    print_variable("Cipher 1", encryptedMessage->firstCipher, false);
    print_variable("Cipher 2", encryptedMessage->secondCipher, true);
    
    mpz_t decryptedMessage;
    mpz_init(decryptedMessage);
    decrypt(decryptedMessage, keypair, encryptedMessage);
    printf("Mensagem descriptografada com sucesso!\n\n");
    print_variable("Mensagem descriptografada", decryptedMessage, true);
    
    // Liberar a memória 
    free(keypair);
    free(encryptedMessage);

    return 0;
}
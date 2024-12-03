#include "elgamal.h"
#include "utils.h"

int main() {
    Keypair *keypair = generate_keys(512);
    printf("Chaves geradas com sucesso!\n\n");
    print_variable("Primo Grande", keypair->publicKey.bigPrime, false);
    print_variable("Raiz Primitiva", keypair->publicKey.primitiveRoot, false);
    print_variable("Chave Pública", keypair->publicKey.key, false);
    print_variable("Chave Privada", keypair->privateKey.key, true);

    char userMessage[256];
    printf("Digite a mensagem para criptografar: ");
    fgets(userMessage, sizeof(userMessage), stdin);
    userMessage[strcspn(userMessage, "\n")] = 0;

    mpz_t originalMessage;
    mpz_init(originalMessage);
    string_to_mpz(originalMessage, userMessage);
    print_variable("Mensagem Original", originalMessage, false);
    printf("Mensagem Original como string = %s\n\n", userMessage);


    EncryptedMessage *encryptedMessage = (EncryptedMessage *)malloc(sizeof(EncryptedMessage));
    mpz_inits(encryptedMessage->firstCipher, encryptedMessage->secondCipher, NULL);
    encrypt(originalMessage, keypair, encryptedMessage);
    printf("Mensagem Criptografada com sucesso!\n\n");
    print_variable("Cipher 1", encryptedMessage->firstCipher, false);
    print_variable("Cipher 2", encryptedMessage->secondCipher, true);
    
    
    mpz_t decryptedMessage;
    mpz_init(decryptedMessage);
    char decryptedMessageStr[256];
    decrypt(decryptedMessage, keypair, encryptedMessage);
    mpz_to_string(decryptedMessageStr, decryptedMessage);
    printf("Mensagem descriptografada com sucesso!\n\n");
    print_variable("Mensagem descriptografada", decryptedMessage, false);
    printf("Mensagem descriptografada como string = %s\n\n", decryptedMessageStr);

    // Liberar a memória 
    free(keypair);
    free(encryptedMessage);

    return 0;
}
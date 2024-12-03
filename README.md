ElGamal Cryptosystem in C
Este programa implementa o Sistema de Criptografia ElGamal em C, um sistema de criptografia de chave pública baseado em problemas matemáticos difíceis, como o logaritmo discreto. O programa gera um par de chaves (pública e privada), criptografa e descriptografa mensagens usando o algoritmo ElGamal.

Funcionalidades
Geração de Chaves: O sistema gera uma chave pública (p, r, a) e uma chave privada (x) usando números primos.
Criptografia: Criptografa a mensagem caractere por caractere usando a chave pública.
Descriptografia: Descriptografa a mensagem cifrada usando a chave privada.
Exibição: Exibe a chave pública gerada e os blocos de mensagem criptografada.
Como Funciona
O processo de criptografia ElGamal envolve os seguintes passos:

Geração das Chaves:
Uma chave pública é gerada a partir de um número primo grande p, uma raiz primitiva r, e uma chave pública a = r^x mod p, onde x é a chave privada.
Criptografia:
Para cada caractere da mensagem, a criptografia é realizada gerando um valor aleatório k, calculando dois blocos: C1 = r^k mod p e C2 = m _ a^k mod p, onde m é o valor numérico do caractere da mensagem.
Descriptografia:
A descriptografia é feita utilizando a chave privada x. O algoritmo recupera a mensagem original usando a fórmula: m = C2 _ (C1^x)^-1 mod p.
Requisitos
C Compiler (gcc, clang).
Biblioteca GMP (GNU Multiple Precision Arithmetic Library) para manipulação de números grandes (se necessário).
Como Compilar e Executar

1. Instalar a biblioteca GMP
   Se você ainda não tem a biblioteca GMP instalada, você pode instalá-la usando os seguintes comandos (para sistemas baseados em Debian/Ubuntu):

bash
Copiar código
sudo apt update
sudo apt install libgmp-dev 2. Compilar o código
Para compilar o código, use o comando gcc:

bash
Copiar código
gcc -o elgamal elgamal.c -lgmp
Aqui, o arquivo elgamal.c é o código-fonte da implementação e -lgmp especifica a biblioteca GMP.

3. Executar o Programa
   Após a compilação, execute o programa com:

bash
Copiar código
./elgamal
O programa solicitará que você digite uma mensagem para criptografar, exibirá a chave pública gerada e, em seguida, mostrará a mensagem criptografada e sua versão descriptografada.

Estrutura do Código
O código está dividido da seguinte maneira:

1. Função mod_exp:
   Realiza a exponenciação modular, ou seja, calcula (base^exp) % mod de forma eficiente.
2. Função gerar_chaves:
   Gera a chave pública e privada, escolhendo um número primo p, uma raiz primitiva r, e a chave privada x aleatoriamente.
   A chave pública é calculada como a = r^x mod p.
3. Funções criptografar e descriptografar:
   A função criptografar cifra a mensagem usando a chave pública.
   A função descriptografar recupera a mensagem original utilizando a chave privada.
4. Funções para criptografar e descriptografar a mensagem inteira:
   criptografar_mensagem: Criptografa uma mensagem completa caractere por caractere.
   descriptografar_mensagem: Descriptografa uma mensagem completa e reconstrói a mensagem original.
5. Função main:
   O ponto de entrada do programa. Solicita a entrada da mensagem, gera as chaves, criptografa e descriptografa a mensagem e exibe os resultados.
   Exemplo de Execução
   Saída Esperada:
   Entrada:

bash
Copiar código
Digite a mensagem para criptografar: Teste
Saída:

bash
Copiar código
Chave pública (p, r, a): (997, 5, 258)
Chave privada x: 564
Mensagem criptografada:
(C1 = 896, C2 = 350) (C1 = 698, C2 = 249) (C1 = 158, C2 = 529) (C1 = 322, C2 = 202)
Mensagem descriptografada: Teste
Descrição dos Campos:
Chave pública: (p, r, a) são os parâmetros públicos usados para a criptografia.
Chave privada: x é a chave privada usada para a descriptografia.
Mensagem criptografada: Cada caractere é transformado em dois números, (C1, C2).
Mensagem descriptografada: A mensagem original é restaurada após a descriptografia.
Limitações e Considerações
Tamanho do número primo: O exemplo usa p = 997 (um número primo pequeno). Para uso em produção ou aplicações reais, é recomendado usar números primos muito maiores (geralmente centenas de dígitos).
Segurança: A segurança do ElGamal depende da dificuldade do problema do logaritmo discreto. Para garantir a segurança, os parâmetros devem ser escolhidos corretamente.
Tamanho da mensagem: A função usa o valor ASCII de cada caractere, o que significa que o tamanho da mensagem está limitado a caracteres que podem ser representados por um valor long long int.
Contribuindo
Fork o repositório.
Crie um branch (git checkout -b feature-xyz).
Faça suas mudanças e commit (git commit -am 'Add new feature').
Envie para o branch (git push origin feature-xyz).
Abra um pull request.

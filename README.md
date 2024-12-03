ElGamal Cryptosystem in C
Este projeto implementa o Sistema de Criptografia ElGamal usando a linguagem C, com o objetivo de fornecer uma criptografia baseada em chave pública, onde a chave pública é usada para criptografar a mensagem e a chave privada para descriptografá-la. A aplicação usa a biblioteca GMP para manipulação de números grandes e realiza criptografia e descriptografia de mensagens utilizando o método ElGamal.

Funcionalidades
Geração de Chaves: O sistema gera um par de chaves (pública e privada) com um número primo grande p, uma raiz primitiva r, e a chave pública a = r^x mod p, onde x é a chave privada.
Criptografia: Criptografa uma mensagem utilizando a chave pública.
Descriptografia: Descriptografa uma mensagem utilizando a chave privada.
Exibição: O programa imprime as chaves geradas, a mensagem original, a criptografada e a descriptografada.
Estrutura do Projeto
A estrutura do repositório é a seguinte:

css
Copiar código
.
├── include
│ ├── elgamal.h
│ └── utils.h
├── src
│ ├── elgamal.c
│ ├── main.c
│ └── utils.c
├── Makefile
└── README.md
Descrição dos Diretórios e Arquivos:
include/: Contém os arquivos de cabeçalho (.h) que definem as funções e estruturas.
src/: Contém os arquivos de implementação (.c) para as funções de criptografia, descriptografia e outras utilidades.
Makefile: Arquivo para facilitar a compilação do projeto.
README.md: Este arquivo, que descreve o projeto e como usá-lo.
Como Compilar e Executar
Pré-requisitos
Antes de compilar, você precisa ter a biblioteca GMP instalada. Se você estiver usando Ubuntu ou Debian, instale a GMP com os seguintes comandos:

bash
Copiar código
sudo apt update
sudo apt install libgmp-dev
Compilar o Código
Clone o repositório ou faça o download dos arquivos.
Navegue até o diretório do projeto.
Execute o comando abaixo para compilar o projeto:
bash
Copiar código
make
Isso irá gerar o executável elgamal.

Executar o Programa
Após a compilação, execute o programa com:

bash
Copiar código
./elgamal
O programa irá gerar as chaves, criptografar a mensagem inserida, e depois descriptografá-la. Ele exibe todos os detalhes no console.

Estrutura do Código
O código está organizado da seguinte forma:

1. src/elgamal.c
   Contém a implementação das funções principais para o Sistema ElGamal:

generate_keys: Gera o par de chaves pública e privada.
encrypt: Criptografa a mensagem.
decrypt: Descriptografa a mensagem. 2. src/utils.c
Contém a implementação de funções auxiliares, como a impressão de variáveis GMP (print_variable).

3. src/main.c
   Contém a função main, que orquestra o fluxo do programa. Gera as chaves, criptografa e descriptografa a mensagem.

4. include/elgamal.h
   Define as estruturas de dados (Keypair, EncryptedMessage) e declarações de funções usadas para criptografar, descriptografar e gerar as chaves.

5. include/utils.h
   Declara a função utilitária print_variable, usada para imprimir variáveis de tipo mpz_t de forma legível.

Exemplo de Execução
Entrada:
O programa solicitará a entrada de uma mensagem que será criptografada e descriptografada:

bash
Copiar código
Digite a mensagem para criptografar: Hello
Saída Esperada:
bash
Copiar código
Chaves geradas com sucesso!

Primo Grande = 997
Raiz Primitiva = 5
Chave Pública = 258
Chave Privada = 564

Mensagem Original = 72

Mensagem Criptografada com sucesso!

Cipher 1 = 896
Cipher 2 = 350

Mensagem descriptografada com sucesso!

Mensagem descriptografada = Hello
Descrição dos Campos:
Chave pública: A chave pública gerada consiste em (p, r, a).
Chave privada: A chave privada é x, que é usada para a descriptografia.
Mensagem Original: O valor numérico da mensagem original.
Cipher 1 e Cipher 2: Blocos gerados durante a criptografia (c1 e c2).
Mensagem Descriptografada: A mensagem original recuperada após a descriptografia.
Limitações e Considerações
Segurança: O código usa um número primo pequeno (p = 997) para fins educacionais. Para uso real, números primos muito maiores (de centenas de dígitos) devem ser usados para garantir a segurança.
Geração de Chaves: A geração de chaves utiliza números aleatórios para a chave privada x, garantindo variabilidade nas chaves geradas.
Contribuindo
Faça o fork deste repositório.
Crie um branch (git checkout -b feature-xyz).
Faça suas alterações e commit (git commit -am 'Add new feature').
Envie o branch (git push origin feature-xyz).
Abra um pull request para discutir as mudanças.

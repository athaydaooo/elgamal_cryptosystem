# ElGamal Cryptosystem in C

Este projeto implementa o **Sistema de Criptografia ElGamal** utilizando a linguagem C e a biblioteca **GMP** para manipulação de números grandes. O sistema de criptografia ElGamal é um algoritmo de chave pública baseado no problema do logaritmo discreto.

## Funcionalidades

- **Geração de Chaves**: O sistema gera um par de chaves pública e privada, usando um número primo grande `p`, uma raiz primitiva `r` e a chave pública `a = r^x mod p`, onde `x` é a chave privada.
- **Criptografia**: O sistema criptografa uma mensagem com a chave pública gerada, produzindo dois valores `C1` e `C2` que representam a mensagem criptografada.
- **Descriptografia**: O sistema descriptografa os valores `C1` e `C2` utilizando a chave privada `x` para recuperar a mensagem original.
- **Exibição das Variáveis**: O programa exibe as chaves pública e privada, a mensagem original, a mensagem criptografada e a mensagem descriptografada.

### Arquivos principais

- **`include/elgamal.h`**: Contém as definições das estruturas e declarações das funções principais de criptografia e geração de chaves.
- **`include/utils.h`**: Declara funções auxiliares, como a impressão de variáveis GMP.
- **`src/elgamal.c`**: Implementa as funções principais de criptografia e geração de chaves.
- **`src/utils.c`**: Implementa as funções auxiliares, como a função de impressão de variáveis GMP.
- **`src/main.c`**: Contém a função principal que orquestra a geração de chaves, criptografia e descriptografia.

## Como Compilar e Executar

### Compilando o Código

Para compilar o código, utilize o Makefile incluído no projeto. Ele irá compilar os arquivos-fonte automaticamente e gerar o executável. Para compilar o projeto, execute os seguintes comandos no diretório do projeto:

```bash
gcc elgamal.c -o elgamal -lgmp
```

Este comando irá compilar todos os arquivos .c e gerar o executável chamado elgamal. Se tudo ocorrer corretamente, você verá o arquivo executável gerado na pasta raiz do projeto.

Executando o Programa
Após a compilação, execute o programa com o seguinte comando:

```bash
./elgamal
```

Isso irá rodar o programa que gerará as chaves, criptografará a mensagem inserida, e depois descriptografará a mensagem, exibindo todos os resultados no terminal.

### Exemplo de Execução

Quando você executar o programa, ele solicitará uma mensagem para ser criptografada. Aqui está um exemplo de execução:

```bash
Chave p�blica (p, r, a): (997, 5, 648)
Chave p ada x: 147
Digite a mensagem para criptografar: 123
Mensagem criptografada:
(C1 = 772, C2 = 57) (C1 = 36, C2 = 461) (C1 = 415, C2 = 451)
Mensagem descriptografada: 123
```

### Descrição das Saídas

- Primo Grande: O número primo p gerado para o sistema.
- Raiz Primitiva: A raiz primitiva r gerada para o sistema.
- Chave Pública: A chave pública a = r^x mod p.
- Chave Privada: A chave privada x.
- Mensagem Original: A mensagem original a ser criptografada (exibida como um número inteiro).
- Cipher 1 e Cipher 2: Os dois blocos da mensagem criptografada.
- Mensagem Descriptografada: A mensagem original recuperada após a descriptografia.

## Limitações e Melhorias Futuras

- Tamanho do número primo: O exemplo usa p = 997 (um número primo pequeno). Para uso em produção ou aplicações reais, é recomendado usar números primos muito maiores (geralmente centenas de dígitos).
- Segurança: A segurança do ElGamal depende da dificuldade do problema do logaritmo discreto. Para garantir a segurança, os parâmetros devem ser escolhidos corretamente.
- Tamanho da mensagem: A função usa o valor ASCII de cada caractere, o que significa que o tamanho da mensagem está limitado a caracteres que podem ser representados por um valor long long int.

## Se você deseja contribuir para o projeto, siga os passos abaixo:

- Faça um fork deste repositório.
- Crie um branch para a sua feature (git checkout -b feature-xyz).
- Faça as suas modificações e commit (git commit -am 'Add new feature').
- Envie o branch (git push origin feature-xyz).
- Abra um pull request para discutir as modificações.

# Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo LICENSE para mais detalhes.

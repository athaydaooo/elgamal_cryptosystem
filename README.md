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

### Pré-requisitos

Antes de compilar, você precisa ter a **biblioteca GMP** instalada. Caso esteja usando **Ubuntu** ou **Debian**, pode instalar com o seguinte comando:

```bash
sudo apt update
sudo apt install libgmp-dev
```

### Compilando o Código

Para compilar o código, utilize o Makefile incluído no projeto. Ele irá compilar os arquivos-fonte automaticamente e gerar o executável. Para compilar o projeto, execute os seguintes comandos no diretório do projeto:

```bash
make
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
Chaves geradas com sucesso!

Primo Grande = 2586535874071348893839797803327225162244104522469012244863473941457740935918077014483349126013169299422127606769963429655826862073573951931705936473217031
Raiz Primitiva = 1160454161069284190250444268068783031982524993818986038604672257294305758570416029424470616398252090668651002968104325074007417706976400989990068428844486
Chave Pública = 2528609066783191407547932147752188543759631972375398821021404341392156863523718994282181490787595248845115553448060654798378973414384981756515363243022029
Chave Privada = 2152019801741526985090081936864175423447364127114374822204681963176941480760727691154462387698608141978179057231960181151028080596171606028600391397832327

------------------------------------

Digite a mensagem para criptografar: aaaa
Mensagem Original = 1633771873
Mensagem Original como string = aaaa

Mensagem Criptografada com sucesso!

Cipher 1 = 781167205680465158559897777545486232191868697348585063036552745897340352372037632262532744788310373655723083922919881134692577251081442858780606803231694
Cipher 2 = 1116572218981417260774945157807611770151983305977801019436369426593208052209808812940976618332131509024481359286792101329801227854082793267436139786432476

------------------------------------

Mensagem descriptografada com sucesso!

Mensagem descriptografada = 1633771873
Mensagem descriptografada como string = aaaa
```

### Descrição das Saídas

- Primo Grande: O número primo p gerado para o sistema.
- Raiz Primitiva: A raiz primitiva r gerada para o sistema.
- Chave Pública: A chave pública a = r^x mod p.
- Chave Privada: A chave privada x.
- Mensagem Original: A mensagem original a ser criptografada (exibida como um número inteiro).
- Cipher 1 e Cipher 2: Os dois blocos da mensagem criptografada.
- Mensagem Descriptografada: A mensagem original recuperada após a descriptografia.

## Estrutura de Funções

1. generate_keys
   Gera o par de chaves pública e privada. Usa um número primo grande p, gera uma raiz primitiva r de p, e a chave privada x. A chave pública a é calculada como r^x mod p.

2. encrypt
   Criptografa a mensagem original utilizando a chave pública. Calcula os valores C1 = r^k mod p e C2 = m \* a^k mod p, onde m é a mensagem original.

3. decrypt
   Descriptografa a mensagem cifrada utilizando a chave privada x. Recupera a mensagem original com a fórmula m = C2 \* (C1^x)^-1 mod p.

4. print_variable
   Função utilitária que imprime variáveis mpz_t (tipos de dados grandes usados pela GMP), facilitando a visualização das chaves e mensagens.

## Limitações e Melhorias Futuras

- Segurança: O código usa um número primo pequeno (997) para fins educacionais. Para uso em produção ou em sistemas reais, é necessário utilizar números primos de centenas de dígitos para garantir a segurança.
- Entrada e Saída de Mensagens: O programa atualmente utiliza números inteiros para representar mensagens. Futuramente, seria interessante permitir que o programa também aceitasse texto (strings) como entrada, convertendo as mensagens de texto em números inteiros antes da criptografia e vice-versa.
- Tratamento de Erros: O código pode ser melhorado com tratamento de erros em várias funções, como alocação de memória e operações com a biblioteca GMP.
  Contribuindo

## Se você deseja contribuir para o projeto, siga os passos abaixo:

- Faça um fork deste repositório.
- Crie um branch para a sua feature (git checkout -b feature-xyz).
- Faça as suas modificações e commit (git commit -am 'Add new feature').
- Envie o branch (git push origin feature-xyz).
- Abra um pull request para discutir as modificações.

# Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo LICENSE para mais detalhes.

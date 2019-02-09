
Universidade Federal de Alagoas

Instituto de Computação

Disciplina: Introdução à Computação

Semestre letivo: 2018.1

Professor: André Lage Freitas

# Trabalho Prático AB2 (TP AB2.1)

## Objetivo

Compreender o consumo dos recursos do computador pelos processos. Investigar a utilização da UCP e da memória pelos processos através de experimentos.

## Especificação

**Importante**. Leia atentamente essa seção pois só serão aceitos trabalhos que obedecerem as a especificações a seguir. 

O trabalho consiste em escrever um programa que crie e monitore a execução de um processo do sistema operacional. A criação de um processo UNIX é feito pela chamada de sistema [fork](http://man7.org/linux/man-pages/man2/fork.2.html), que cria um processo filho através do processo que o executa (processo pai).

O exemplo no arquivo `main.c`, adaptado de [1], mostra como esse procedimento é feito.

A equipe deve estudar esse código, re-escrevê-lo e adaptá-lo conforme as instruções escritas nos `TODO`s; ver dentro dos comentários do arquivo `main.c`.

## Informações técnicas úteis

* Como saber o ID do processo filho: [fork man page](http://man7.org/linux/man-pages/man2/fork.2.html), ver seção [`RETURN VALUE`](http://man7.org/linux/man-pages/man2/fork.2.html#RETURN_VALUE).
* [Como saber o ID de um processo](https://ubuntuforums.org/showthread.php?t=1430052).
* Exemplo de código com utilização intensa da UCP (um laço "infinito"):

```c
for (;;) {}
```

* Exemplo de código com utilização intensa da UCP e da memória (alocações sucessivas de memórias através da função `malloc`):

```c
for (;;) {
	malloc(sizeof(100000));
}
```
* Exemplo de programa que extrai a quantidade de memória consumida pelo processo cujo ID é 1 (adaptado [dessa referência](https://stackoverflow.com/questions/14393762/executing-bash-command-and-getting-the-output-in-c)):

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char bash_cmd[256] = "ps v 1 | awk '{print $12}' | grep -v MEM";
	char buffer[1000];
	FILE *pipe;
	int len; 
	pipe = popen(bash_cmd, "r");

	if (NULL == pipe) {
		perror("pipe");
		exit(1);
	} 
	
	char* mem_usage = fgets(buffer, sizeof(buffer), pipe);
	len = strlen(bash_cmd);
	bash_cmd[len-1] = '\0'; 
	pclose(pipe);

	printf("mem_usage == %s", mem_usage);
}
```
 

## Relatório

Deverá ser entregue um relatório feito em [Markdown](https://en.wikipedia.org/wiki/Markdown), com **mínimo de 600 e máximo de 1.000 palavras**. 

O relatório deverá utilizar o modelo ```REPORT.md``` como especificado dentro do modelo.  Atentar aos `TODO`s contidos nesse arquivo.

## Controle de versão

A equipe deverá fazer um [git fork](https://help.github.com/articles/fork-a-repo/) desse [projeto](https://github.com/alage/TODO) e utilizá-lo para hospedar os arquivos do seu trabalho.

Todos os dados necessários para a reprodução do experimento devem estar no repositório com seus passos descritos no arquivo ```INSTALL.md``` em Markdown. As instruções do arquivo ```INSTALL.md``` serão utilizadas para compilar e executar os códigos.

## Linguagem de programação, compilação e execução

O programa deve ser implementado na **linguagem de programação C** obedecendo os seguintes critérios:

* código sob o padrão ANSI C;
* utilização dos compiladores gcc ou g++;
* bibliotecas externas deve ser entregues junto com o código;

Os **comandos completos para compilação** do programa devem ser indicados. Se não for explicitado, o seguinte comando será utilizado:

```
gcc -o bin main.c 
```

Se for utilizado algum programa para automação de compilação, os comandos devem ser indicados. Os únicos programas de automação aceitos são o [make](https://www.gnu.org/software/make/) e o [cmake](http://www.cmake.org).

Para a **execução do programa**, serão usados os seguintes comandos:

* Para execução do código com utilização intensa da UCP:

```
./bin ucp
```

* Para execução do código com utilização intensa da UCP e da memória:

```
./bin ucp-mem
```

## Sistema operacional

O programa será testado no sistema operacional GNU/Linux, distribuição Ubuntu 15.10 (ou superior). Essa distribuição pode ser obtida gratuitamente [nessa página Web](http://www.ubuntu.com/download/desktop).

Usuários de outros sistemas operacionais podem utilizar gratuitamente a [VirtualBox](https://www.virtualbox.org/wiki/Downloads) para instalação do Ubuntu.
 
Em suma, entendam que quem corrigirá o seu trabalho utilizará outro ambiente computacional. Logo, forneçam as instruções necessárias para a compilação e execução do seu programa, como descrita na Seção _Linguagem de programação e compilação_.

## Critérios de Correção

* A nota máxima atribuída será de 30,0 pontos distribuídos da seguinte maneira:
	* Conteúdo (12,0 pontos): se o programa funciona de acordo com a sua especificação distribuídos da seguinte forma:
		* 6,0 pontos: código com utilização intensa da CPU;
		* 6,0 pontos: código com utilização intensa da CPU e da memória.
	* Relatório (12,0 pontos) distribuídos da seguinte forma: 
		* 6,0 pontos: seção Resultados;
		* 6,0 pontos: seção Discussão.
	* Organização (6,0 pontos): relatório claros, objetivos e sem erros ortográficos; código-fonte comentado e padronizado.
* Cada equipe deverá distribuir os pontos entre os membros da equipe sendo a nota individual de cada membro não poderá ser maior que 10,0 pontos.
* Equipes devem conter **3 discentes**.
 * Importante: preencher no arquivo `REPORT.md` o campo **Distribuição da nota (%)**, indicando a porcentagem que cada discente deve obter em relação à nota que será atribuída ao Trabalho. Caso esses campos não sejam preenchidos, o Professor distribuirá homogeneamente as notas entres os compenentes da equipe.

 
### Pontuação extra

Os(as) discentes que realizarem mais tarefas, além do que foi especificado neste trabalho, o professor atribuirá de 0,5 a 1,0 ponto extra a depender da relevância da contribuição no programa. O critério será decidido pelo professor. Por exemplo, adição de funcionalidades, armazenamento de dados em arquivo, documentação de código, comentários em inglês sem erros ortográficos, etc.

### Plágio

A nota zero será atribuída caso haja qualquer tipo de cópia parcial ou integral assim como as devidas medidas legais. **Leia a [cartilha sobre plágio](http://www.noticias.uff.br/arquivos/cartilha-sobre-plagio-academico.pdf)**.


## Entrega do trabalho

### Forma 

O código-fonte deverá ser entregue **exclusivamente pelo Google Classroom**.

A responsabilidade sobre a integridade do arquivo contendo trabalho é exclusivamente dos discentes.  Serão ignorados os trabalhos cujos arquivos não conseguirem ser abertos.

### Prazos

O prazo de entrega está estabelecido no Google Classroom.

**Nenhum trabalho será aceito após o prazo estabelecido.**

## Referências

[1] Maziero, Carlos A. [Sistemas Operacionais: Conceitos e Mecanismos](http://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=so:so-livro.pdf). 2017.

## Disclaimer

Esse material foi elaborado pelo [Prof. André Lage Freitas](https://sites.google.com/a/ic.ufal.br/andrelage/) e está licenciado sob a licença [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0-standalone.html).

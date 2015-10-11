<p align="center">
Universidade Federal de Alagoas</br>
Instituto de Computação</br>
</p>

#Trabalho Prático AB2

Disciplina: Introdução à Computação</br>
Semestre letivo: 2015.1</br>
Professor: André Lage Freitas</br>

## Objetivo

Compreender o consumo dos recursos do computador pelos processos. Investigar a utilização da UCP e da memória pelos processos através de experimentos. Experimentar a gestão de processos.

## Especificação

**Importante**. Leia atentamente essa seção pois só serão aceitos trabalhos que obedecerem as a especificações a seguir. 

O trabalho consiste em escrever um programa que crie e monitore a execução de um processo do sistema operacional. A criação de um processo UNIX é feito pela chamada de sistema [fork](), que cria um processo filho dentro do  processo que o executa (processo pai). 

O exemplo no arquivo ```main.c```, adaptado de [1], mostra como esse procedimento é feito.

A equipe deve estudar esse código, re-escrevê-lo e adaptá-lo conforme as instruções escritas nos TODOs; ver dentro dos comentários do programa.


* Exemplo de código com utilização intensa da UCP:

```
for (;;) {}
```

* Exemplo de código com utilização intensa da UCP e da memória:

```
for (;;) {
	malloc(sizeof(100000));
}
```


## Relatório

Deverá ser entregue um relatório feito em [Markdown](https://en.wikipedia.org/wiki/Markdown), com **mínimo de 600 e máximo de 1.000 palavras**. O relatório deverá utilizar o modelo ```REPORT.md``` como especificado dentro do modelo.


## Controle de versão

A equipe deverá fazer um [git fork](https://help.github.com/articles/fork-a-repo/) desse [projeto](https://github.com/alage/2015.1-IAC-trabalho-pratico) e utilizá-lo para a execução do trabalho. 

Todos os dados necessários para a reprodução do experimento devem estar no repositório com seus passos descritos no arquivo ```INSTALL.md``` em Markdown. As instruções do arquivo ```INSTALL.md``` serão utilizadas para compilar e executar os códigos.

## Linguagem de programação

O programa deve ser implementado na linguagem de programação **C** obedecendo os seguintes critérios:

* código sob o padrão ANSI C;
* utilização dos compiladores gcc ou g++;
* bibliotecas externas deve ser entregues junto com o código;
* os comandos completos para compilação do programa devem ser indicados;
* se o comando não for indicado, o seguinte comando será utilizado:

```
gcc -o bin main.c 
```

* se for utilizado algum programa para automação de compilação, os comandos devem ser indicados;
	* os programas de automação aceitos são o [make](https://www.gnu.org/software/make/) e o [cmake](http://www.cmake.org).

## Sistema operacional

O programa será testado no sistema operacional GNU/Linux, distribuição Ubuntu 14.04.2 LTS. Essa distribuição pode ser obtida gratuitamente [nessa página Web](http://www.ubuntu.com/download/desktop).

Usuários de outros sistemas operacionais podem utilizar gratuitamente a [VirtualBox](https://www.virtualbox.org/wiki/Downloads) para instalação do Ubuntu.
 
Em suma, entendam que quem corrigirá o seu trabalho utilizará outro ambiente computacional. Logo, forneçam as instruções e programas necessários para a compilação e execução do seu programa.

## Critérios de Correção


* A nota máxima atribuída será de 20,0 pontos distribuídos da seguinte maneira:
	* Organização (**4,0 pontos**): código bem escrito, padronizado e comentado.
	* Conteúdo (**16,0 pontos**): 
		* **10,0 pontos**: se o programa compila, executa e funciona como especificado;
 		* **6,0 pontos**: relatório, sendo 3 pontos para cada seção da Seção Discussão.

* Cada equipe deverá distribuir os pontos entre os membros da equipe sendo a nota individual de cada membro não poderá ser maior que 10,0 pontos.
* Após a divulgação da nota do trabalho pelo Monitor da disciplina, a equipe terá **48h** para enviar as notas individuais para o Monitor por e-mail.

### Pontuação extra

O(a) discente que realizar mais tarefas, além do que foi especificado neste trabalho, o professor atribuirá de 0,5 a 1,0 ponto extra a depender da relevância da contribuição no programa. O critério será decidido pelo professor. 

O(a) discente deve indicar qual é a tarefa executada. Por exemplo, adição de funcionalidades, armazenamento de dados em arquivo, documentação de código, comentários em inglês sem erros ortográficos, etc.


### Plágio

A nota zero será atribuída caso haja qualquer tipo de cópia parcial ou integral assim como as devidas medidas legais. Leia a [cartilha sobre plágio](http://www.noticias.uff.br/arquivos/cartilha-sobre-plagio-academico.pdf).


## Entrega do trabalho

### Forma 

O código-fonte deverá ser entregue **exclusivamente por e-mail** para o monitor da disciplina para o seguinte endereço: **filipebatista** (no) **ic ufal br**


Será registrada como data de recebimento do trabalho a data indicada pelo servidor de e-mail do monitor. 

A responsabilidade sobre a integridade do arquivo contendo trabalho é exclusivamente dos discentes.  Serão ignorados os trabalhos cujos arquivos não conseguirem ser abertos ou se o e-mail não chegar à caixa de entrada de e-mail do monitor.

### Prazos

O prazo de entrega sem atraso é o dia **20/10/15**.

Trabalhos entregues com atraso serão aceitos, no máximo, até o o dia **22/10/15**. Serão descontados 5% da nota obtida por dia de atraso.


## Referências

[1] Maziero, Carlos A. [Sistemas Operacionais: Conceitos e Mecanismos](http://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=so:so-livro.pdf). 2013. 

## Disclaimer

Esse material foi elaborado pelo [Prof. André Lage Freitas](https://sites.google.com/a/ic.ufal.br/andrelage/) e está licenciado sob a licença _GNU General Public License v3.0_.

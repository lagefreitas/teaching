<p align="center">
Universidade Federal de Alagoas</br>
Instituto de Computação</br>
</p>

#Trabalho Prático AB2

Disciplina: Sistemas Operacionais</br>
Semestre letivo: 2015.1</br>
Professor: André Lage Freitas</br>

## Objetivo

Simulador o Escalonador de Tarefas de um Sistema Operacional.

## Especificação

**Importante**. Leia atentamente essa seção pois só serão aceitos trabalhos que obedecerem as a especificações a seguir. 

O trabalho consiste em simular o escalonamento de um conjunto de tarefas usando os seguintes algoritmos de escalonamento de tarefas [1]:

* **FCFS** (First Come, First Served)
* **Round-Robin** com quantum = **2s**
	* Observação: quem implementar com prioridade, será considerado como pontuação extra (até 1,0 ponto)


### Entrada do Programa

#### ```args[1]``` 

O programa deverá ler os dados dos processos a partir de um arquivo passado como o primeiro parâmetro (```args[1]```). Cada linha da entrada corresponde a um processo, com os seguintes dados fornecidos como inteiros separados por um ou mais espaços em branco:

* data de criação;
* duração em segundos;
* prioridade estática (escala de prioridades positiva).

A seguir, um exemplo de arquivo de entrada:

```
0 5 2
0 2 3
3 3 4
1 4 1
```

Nesse exemplo de entrada, o processo P1 (primeira linha) tem data de criação 0, sua execução dura 5 segundos e sua prioridade é 2. Esse formato de entrada deverá ser respeitado, pois o simulador será testado com outros dados de entrada. 

Observe que essa listagem não precisa necessariamente estar ordenada por data de criação de cada processo. Entretanto, o programa deverá ser capaz de identificar cada tempo de ingresso e escalonar o processo corretamente.

**O programa deverá aceitar, no mínimo, 9 processos** nomeados de P1 à P9, ordenados com base no tempo de ingresso no sistema onde P1 ingressou antes de P2 que ingressou antes de P3 e, assim, sucessivamente. 


#### ```args[2]``` 

O segundo parâmetro de entrada deve ser a política de escalonamento de tarefas:

* ```fcfs``` FCFS (First Come, First Served)
* ```rr``` Round-Robin com quantum = **2s**, com prioridade

#### Exemplos de compilação e execução em C

O exemplo a seguir compila e executa o programa com arquivo de entrada ```input.txt``` e simulando a política FCFS:

``` 
$ gcc -o bin main.c
$ ./bin input.txt fcfs
...
```

### Saída do Programa

O simulador deverá produzir **o diagrama de tempo da execução** gravado em arquivo. Esse arquivo deverá ser nomeado de ```output```.

O diagrama de tempo de cada execução deve ser gerado na vertical, de cima para baixo (uma linha por segundo), conforme mostra o exemplo a seguir:

```
tempo   P1  P2  P3  P4
 0- 1   ##  --
 1- 2   ##  --  --
 2- 3   --  ##  --
 3- 4   --  ##  --  --
 4- 5   --      ##  --
 5- 6   --      ##  --
 6- 7   ##      --  --
 7- 8   ##      --  --
 8- 9   --      --  ## 
 9-10   --      --  ##
10-11   --      ##  --
11-12   --      ##  --
12-13   ##          --
13-14               ##
```

### Implementação

Sugestão de implementação (pseudo-código que deve ser ajustado para cada política):

```
início
  lê dados das tarefas da entrada padrão
  imprime cabeçalho do diagrama
  
  t = 0
  enquanto t < tmax

    se há uma tarefa rodando
      se a tarefa rodando chegou ao fim da execução
        migra a tarefa para o estado terminado 
        libera o processador
      senão
        se a tarefa rodando chegou ao fim de seu quantum
        migra a tarefa para a fila de prontos
        libera o processador
      fim se
    fim se

    para cada tarefa i
      se a tarefa i inicia agora (em t)
        coloca a tarefa na fila de prontos
      fim se
    fim para

    se o processador estiver livre
      se houver tarefa na fila de prontas
        escolhe uma tarefa da fila de prontas
        migra essa tarefa para o estado "rodando"
      fim se
    fim se

    imprime linha do diagrama com o estado de cada tarefa

    incrementa o tempo (t++)
    incrementa contadores da tarefa corrente (tempo de vida e de quantum)

  fim enquanto

  calcula e imprime tempos médios
fim
```

Sugere-se definir para cada tarefa:

* identificador;
* datas de inicio e de conclusão;
* duração (tempo necessário no processador);
* estado atual (nova, pronta, rodando, terminada, ...);
* tempo já executado (total e no quantum atual);
* (outros campos podem ser necessários para algumas políticas).

## Controle de versão

A equipe deverá fazer um [git fork](https://help.github.com/articles/fork-a-repo/) desse [projeto](https://github.com/alage/2015.1-IAC-trabalho-pratico) e utilizá-lo para a execução do trabalho. 

Todos os dados necessários para a reprodução do experimento devem estar no repositório com seus passos descritos no arquivo ```INSTALL.md``` em Markdown. As instruções do arquivo ```INSTALL.md``` serão utilizadas para compilar e executar os códigos.

## Linguagem de programação

O trabalho poderá ser implementado na linguagem de programação desejada pelo discente desde que:

* o compilador seja software livre e/ou gratuito e esteja disponível para instalação no sistema operacional definido nessa especificação;
* o(a) discente informe como instalar o compilador da linguagem no sistema operacional definido nessa especificação;
* se a linguagem de programação for **C**, os critérios são:
	* código sob o padrão ANSI C;
	* utilização dos compiladores gcc ou g++;
* bibliotecas externas deve ser entregues junto com o código;
* os comandos completos para compilação do programa devem ser indicados no arquivo ```INSTALL.md```;
	* se for utilizado algum programa para automação de compilação ou [IDE](https://pt.wikipedia.org/wiki/Ambiente_de_desenvolvimento_integrado), os comandos para instalação do programa devem ser indicados;
	* exemplos de programas de automação: [maven](http://maven.apache.org), [ant](http://ant.apache.org), [make](https://www.gnu.org/software/make/) e o [cmake](http://www.cmake.org).
	
	
## Sistema operacional

O programa será testado no sistema operacional GNU/Linux, distribuição Ubuntu 14.04.2 LTS. Essa distribuição pode ser obtida gratuitamente [nessa página Web](http://www.ubuntu.com/download/desktop).

Usuários de outros sistemas operacionais podem utilizar gratuitamente a [VirtualBox](https://www.virtualbox.org/wiki/Downloads) para instalação do Ubuntu.
 
Em suma, entendam que quem corrigirá o seu trabalho utilizará outro ambiente computacional. Logo, forneçam as instruções e programas necessários para a compilação e execução do seu código devem ser indicados no arquivo ```INSTALL.md```.

## Critérios de Correção

* A nota máxima atribuída será de 20,0 pontos distribuídos da seguinte maneira:
	* Organização (**4,0 pontos**): código bem escrito, padronizado e comentado.
	* Conteúdo (**16,0 pontos**): se o programa funciona de acordo com a sua especificação:
		* **8,0 pontos**: simula corretamente a política de escalonamento **FCFS** (First Come, First Served);
 		* **8,0 pontos**: simula corretamente a política de escalonamento **Round-Robin** com quantum = **2s**, com prioridade.

* Cada equipe deverá conter **dois** discentes no máximo.
* Cada equipe deverá distribuir os pontos entre os membros da equipe sendo a nota individual de cada membro não poderá ser maior que 10,0 pontos.
* Após a divulgação da nota do trabalho pelo Monitor da disciplina, a equipe terá **48h** para enviar as notas individuais para o Monitor por e-mail.

### Pontuação extra

O(a) discente que realizar mais tarefas, além do que foi especificado neste trabalho, o professor atribuirá de 0,5 a 1,0 ponto extra a depender da relevância da contribuição no programa. O critério será decidido pelo professor. 

O(a) discente deve indicar qual é a tarefa executada. Por exemplo, adição de funcionalidades, armazenamento de dados em arquivo, documentação de código, comentários em inglês sem erros ortográficos, etc.


### Plágio

A nota zero será atribuída caso haja qualquer tipo de cópia parcial ou integral assim como as devidas medidas legais. Leia a [cartilha sobre plágio](http://www.noticias.uff.br/arquivos/cartilha-sobre-plagio-academico.pdf).


## Entrega do trabalho

### Forma 

O código-fonte deverá ser entregue **exclusivamente por e-mail** para o monitor da disciplina para o seguinte endereço: **thiagopeixoto** (no) **linux com**


Será registrada como data de recebimento do trabalho a data indicada pelo servidor de e-mail do monitor. 

A responsabilidade sobre a integridade do arquivo contendo trabalho é exclusivamente dos discentes.  Serão ignorados os trabalhos cujos arquivos não conseguirem ser abertos ou se o e-mail não chegar à caixa de entrada de e-mail do monitor.

### Prazos


O prazo de entrega sem atraso é o dia **23/10/15**.

Trabalhos entregues com atraso serão aceitos, no máximo, até o o dia **25/10/15**. Serão descontados 5% da nota obtida por dia de atraso.


## Referências

[1] Maziero, Carlos A. [Sistemas Operacionais: Conceitos e Mecanismos](http://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=so:so-livro.pdf). 2013. 

## Disclaimer

Esse material foi elaborado pelo [Prof. André Lage Freitas](https://sites.google.com/a/ic.ufal.br/andrelage/) e foi baseado no projeto Algoritmos de Escalonamento da [disciplina IF66D](http://dainf.ct.utfpr.edu.br/~maziero/doku.php/so:algoritmos_de_escalonamento) (DAINF-UFTPR), de autoria do Prof. Maziero, que está licenciado sob a licença [Creative Commons BY-NC-SA](http://creativecommons.org/licenses/by-nc-sa/3.0/br/). 

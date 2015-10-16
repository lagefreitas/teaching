<p align="center">
Universidade Federal de Alagoas</br>
Instituto de Computação</br>
</p>

#Compilação e execução do algoritmo

A seguir, serão descritos os passos necessários para realizar a utilização do algoritmo em questão com sucesso.

## Compilação: 

* Para a compilação do algoritmo, primeiramente deve-se certificar de que está no diretório que contém o arquivo ```main.c```, caso contrário, navegue até ele. Em caso de dúvidas, o diretório é o seguinte: ``` /teaching/2015.1-IAC-trabalho-pratico/src/ ```.

* Em seguida, executar o seguinte comando: ```gcc main.c```.
	* Isso irá compilar o algoritmo, gerando como saída um binário nomeado como ```a.out```.

## Execução:

* Tendo realizados os passo anteriores, agora deve-se executar o comando ```./a.out cpu```.
	* Esse comando irá executar o binário resultante da compilação realizada anteriormente. Nesta execução, o algoritmo irá apenas fazer a análise do uso da cpu.
	
* Para realizar a execução completa, o seguinte comando deverá ser executado: ```./a.out cpu-mem```.
	* Esse comando irá executar o binário resultante da compilação realizada anteriormente. Nesta execução, o algoritmo irá fazer a análise do uso da cpu e alocar memória, também analisando o seu uso.

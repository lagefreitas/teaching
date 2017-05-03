{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "<p align=\"center\">\n",
    "Universidade Federal de Alagoas</br>\n",
    "\n",
    "Instituto de Computação</br>\n",
    "\n",
    "</p>\n",
    "\n",
    "#Trabalho Prático AB2\n",
    "\n",
    "Disciplina: Sistemas Distribuídos\n",
    "\n",
    "Semestre letivo: 2016.2\n",
    "\n",
    "Professor: André Lage Freitas\n",
    "\n",
    "## Especificação\n",
    "\n",
    "**Importante**. Leia atentamente essa seção pois só serão aceitos trabalhos que obedecerem as a especificações a seguir. \n",
    "\n",
    "Baseado(a) no exemplo a seguir de implementação do B-multicast em Julia, façam os exercícios descritos nesse documento."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "oi!\n"
     ]
    }
   ],
   "source": [
    "function B_multicast(g,m,B_deliver)\n",
    "    for p in g\n",
    "        remotecall(p, B_deliver, m)\n",
    "    end\n",
    "end\n",
    "\n",
    "# Adding 3 processes (workers)\n",
    "#addprocs(3)\n",
    "\n",
    "# My group is composed by all workers\n",
    "g = workers()\n",
    "\n",
    "# Multicasting \"oi!\" message to group `g` by assuming `println` as B_deliver function.\n",
    "B_multicast(g,\"oi!\",println)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "### Exercício 1: Sincronismo (2,0 pontos)\n",
    "\n",
    "Adicione 10 processos com o comando `addprocs` abaixo. \n",
    "\n",
    "_Atenção_: sua instalação local de Julia pode não conseguir adicionar 10 processos, use a [JuliaBox](https://juliabox.com)."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "10-element Array{Any,1}:\n",
       "  2\n",
       "  3\n",
       "  4\n",
       "  5\n",
       "  6\n",
       "  7\n",
       "  8\n",
       "  9\n",
       " 10\n",
       " 11"
      ]
     },
     "execution_count": 2,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "addprocs(10)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "Modifique a implementação do B-multicast para utilizar communicação síncrona."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "#TODO implementação do B-multicast síncrono."
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "Execute as duas versões do B-multicast (síncrona e assíncrona) e compare as saídas.\n",
    "\n",
    "A ordem das mensagens das saídas foram as mesmas para ambas versões do B-multicast? Por quê?\n",
    "\n",
    "**Resposta**: _em itálico_\n",
    "\n",
    "\n",
    "\n",
    "### Exercício 2: Análise de desempenho do B-multicast (2,0 pontos)\n",
    "\n",
    "Meça o tempo de execução duas versões do B-multicast (síncrona e assíncrona). Dica: utilize a macro `@time`.\n",
    "\n",
    "* Execute 50 vezes essa medição e construa um gráfico em forma de barras:\n",
    "\t* cada barra representando cada versão do B-multicast;\n",
    "\t* calcule e coloque no gráfico o [intervalo de confiança](https://en.wikipedia.org/wiki/Confidence_interval) com nível de 95%.\n",
    "    \n",
    "**Gráfico**: _por aqui_    \n",
    "    \n",
    "    \n",
    "* Qual das duas versões teve o menor tempo de execução? Por quê?\n",
    "\n",
    "**Resposta**: _em itálico_\n",
    "\n",
    "\n",
    "\n",
    "### Exercício 3: Análise de desempenho do R-multicast (3,0 pontos)\n",
    "\n",
    "Implemente duas versões do algoritmo R-multicast: uma assíncrona e outra síncrona.\n",
    "\n",
    "* R-multicast assíncrono"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": [
    "#TODO implementação do R-multicast síncrono."
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* R-multicast assíncrono"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "metadata": {
    "collapsed": false
   },
   "outputs": [],
   "source": [
    "#TODO implementação do R-multicast assíncrono."
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "collapsed": true
   },
   "source": [
    "Faça a mesma análise de desempenho para o R-multicast que você fez no Exercício 2.\n",
    "\n",
    "\n",
    "**Gráfico**: _por aqui_    \n",
    "    \n",
    "    \n",
    "* Qual das duas versões (R-multicast assíncrono e assíncrono) teve o menor tempo de execução? Por quê?\n",
    "\n",
    "**Resposta**: _em itálico_\n",
    "\n",
    "\n",
    "\n",
    "### Exercício 4: Análise de desempenho: B-multicast vs. R-multicast (3,0 pontos)\n",
    "\n",
    "Para cada uma das comparações abaixo, qual dos algoritmos teve o menor tempo de execução? Por quê?\n",
    "\n",
    "* B-multicast assíncrono vs. R-multicast assíncrono.\n",
    "    \n",
    "\n",
    "**Resposta**: _em itálico_    \n",
    "    \n",
    "* B-multicast síncrono vs. R-multicast síncrono.\n",
    "\n",
    "\n",
    "**Resposta**: _em itálico_\n",
    "\n",
    "## Entrega\n",
    "\n",
    "As respostas deverão ser entregues nos devidos campos desse arquivo, ou seja, em [Markdown](https://en.wikipedia.org/wiki/Markdown) e no formato [IJulia Notebook](https://github.com/JuliaLang/IJulia.jl).\n",
    "\n",
    "O programa deve ser implementado na linguagem de programação **Julia**. Seu trabalho será testado na [JuliaBox](https://juliabox.com), portanto teste seu arquivo IJulia na JulizBox antes de enviá-lo.\n",
    "\n",
    "\n",
    "### Forma \n",
    "\n",
    "O arquivo IJulia Notebook deverá ser entregue ao Professor **exclusivamente por e-mail** para o seguinte endereço: **prof.alage** (no) **gmail com**\n",
    "\n",
    "\n",
    "Será registrada como data de recebimento do trabalho a data indicada pelo servidor de e-mail do Professor. \n",
    "\n",
    "A responsabilidade sobre a integridade do arquivo contendo trabalho é exclusivamente dos discentes. Serão ignorados os trabalhos cujos arquivos não conseguirem ser abertos ou se o e-mail não chegar à caixa de entrada de e-mail do Professor.\n",
    "\n",
    "### Prazos\n",
    "\n",
    "O prazo de entrega sem atraso é o dia **12/05/17**.\n",
    "\n",
    "Trabalhos entregues com atraso serão aceitos, no máximo, até o o dia **14/05/17**. Serão descontados 5% da nota obtida por dia de atraso.\n",
    "\n",
    "\n",
    "## Pontuação extra\n",
    "\n",
    "O(a) discente que realizar mais tarefas, além do que foi especificado neste trabalho, o professor atribuirá de 0,5 a 1,0 ponto extra a depender da relevância da contribuição no programa. O critério será decidido pelo professor. \n",
    "\n",
    "O(a) discente deve indicar qual é a tarefa executada. Por exemplo, adição de funcionalidades, armazenamento de dados em arquivo, documentação de código, comentários em inglês sem erros ortográficos, etc.\n",
    "\n",
    "\n",
    "**Plágio** A nota zero será atribuída caso haja qualquer tipo de cópia parcial ou integral assim como as devidas medidas legais. Leia a [cartilha sobre plágio](http://www.noticias.uff.br/arquivos/cartilha-sobre-plagio-academico.pdf).\n",
    "\n",
    "## Disclaimer\n",
    "\n",
    "Esse material foi elaborado pelo [Prof. André Lage Freitas](https://sites.google.com/a/ic.ufal.br/andrelage/) e está licenciado sob a licença _GNU General Public License v3.0_."
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Julia 0.3.12",
   "language": "julia",
   "name": "julia-0.3"
  },
  "language_info": {
   "file_extension": ".jl",
   "mimetype": "application/julia",
   "name": "julia",
   "version": "0.3.12"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 0
}

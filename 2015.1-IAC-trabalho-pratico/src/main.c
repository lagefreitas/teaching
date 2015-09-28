#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {

int pid ; /* identificador de processo */

pid = fork () ; /* replicação do processo */

if ( pid < 0 ) { /* se fork não funcionou */
	perror ("Erro: ") ;
	exit (-1) ; /* encerra o processo com código de erro -1 */
}
else if( pid > 0 ) /* se sou o processo pai*/
{
	//TODO guarde a cada segundo o consumo de memória (em Kilobytes) e CPU (em porcentagem) do processo filho
	//TODO após 10 segundos de execução, mate o proceso filho
}
else /* senão, sou o processo filho*/
{
	if ( strcmp(argv[1], "cpu") == 0 ){
		//Código com uso intenso de cpu
		for (;;) {}
	} else if ( strcmp(argv[1], "cpu-mem") == 0 ){
		//Código com uso intenso de memória e cpu
		for (;;) {
    	malloc(sizeof(100000));
		}
	}
	//22 é o erro de argumento inválido
	//http://www.virtsync.com/c-error-codes-include-errno
	fprintf(stderr, "Erro: %s\n", strerror(22));
	exit(22);
}

perror ("Erro: ") ; /* execve não funcionou */

printf ("Tchau !\n") ;
exit(0) ; /* encerra o processo com sucesso (código 0) */

}

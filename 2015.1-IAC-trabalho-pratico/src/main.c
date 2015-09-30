#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {

int pid, i, j, k; /* identificador de processo */
float pcpu, pmem, memoria;

FILE *fp;
char dump[50], file_path[50] = "/proc/", str_pid[50], cpu_command[100] = "ps -p ", mem_command[100] = "ps -p ";
char path[50];
char *memtotal = NULL;
char * line = NULL;
size_t len = 0;
ssize_t read;

pid = fork () ; /* replicação do processo */


sprintf(str_pid, "%d", pid);
strcat(file_path, str_pid);
strcat(file_path, "/status");
strcat(cpu_command, str_pid);
strcat(cpu_command, " -o %cpu | sed 1d");
strcat(mem_command, str_pid);
strcat(mem_command, " -o %mem | sed 1d");

if ( pid < 0 ) { /* se fork não funcionou */
	perror ("Erro: ") ;
	exit (-1) ; /* encerra o processo com código de erro -1 */
}
else if( pid > 0 ) /* se sou o processo pai*/
{
	printf("PID: %d\n", pid);
	fp = fopen("/proc/meminfo","r");
	while ((read = getline(&line, &len, fp)) != -1) {
		if (!strncmp(line, "MemTotal:", 9))
		{
			memtotal = strdup(&line[17]);
			memoria = atof(strtok(memtotal, " "));
			printf("Memória Total: %.2f KB\n", memoria);
		}
	}
	//TODO guarde a cada segundo o consumo de memória (em Kilobytes) e CPU (em porcentagem) do processo filho
	for(j = 0; j < 10; j++){
		fp = popen(cpu_command,"r");
		//fp = fopen(file_path,"r");
		/*while ((read = getline(&line, &len, fp)) != -1) {
			if (!strncmp(line, "VmRSS:", 6))
			{
				vmhwm = strdup(&line[6]);
			}
		}*/
		while (fgets(path, sizeof(path)-1, fp) != NULL) {
			for(i = 0; i < strlen(path);i++){
				if(path[i] != ' '){
					path[i-1] = path[i];
				}
			}
			pcpu = atof(path);
			printf("CPU: %.2f%%\n", pcpu);
		}
		fclose(fp);
		
		fp = popen(mem_command,"r");
		//fp = fopen(file_path,"r");
		/*while ((read = getline(&line, &len, fp)) != -1) {
			if (!strncmp(line, "VmRSS:", 6))
			{
				vmhwm = strdup(&line[6]);
			}
		}*/
		while (fgets(path, sizeof(path)-1, fp) != NULL) {
			for(i = 0; i < strlen(path);i++){
				if(path[i] != ' '){
					path[i-1] = path[i];
				}
			}
			pmem = atof(path);
			printf("Memória: %.2f KB\n", (memoria*pmem)/100);
		}
		fclose(fp);
		
		sleep(1);
	}
	if (line){
		free(line);
	}
	//após 10 segundos de execução, mate o proceso filho
	kill(pid, SIGKILL);
}
else /* senão, sou o processo filho*/
{
	if ( strcmp(argv[1], "cpu") == 0 ){
		//Código com uso intenso de cpu
		for (;;) {}
	} else if ( strcmp(argv[1], "cpu-mem") == 0 ){
		//Código com uso intenso de memória e cpu
		for (k = 0;k < 50000;k++) {
    		malloc(10000000);
		}
		sleep(15);
	}else{
		//22 é o erro de argumento inválido
		//http://www.virtsync.com/c-error-codes-include-errno
		fprintf(stderr, "Erro: %s\n", strerror(22));
		exit(22);	
	}
}

perror ("Erro: ") ; /* execve não funcionou */

printf ("Tchau !\n") ;
exit(0) ; /* encerra o processo com sucesso (código 0) */

}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>

int i;

void consumeCPU() {
	for (;;) {}
}

void consumeMemory() {
	for(;;){
		malloc(1024);
		usleep(1000);
	}
}

//CPU: ps -p <PID> -o pcpu | sed 1d | tr -d ' '
double getCpuUsage(int pid){
	char comando[50];
	FILE *fp; //Ponteiro para a leitura do arquivo retornado pelo popen
	double porcentagem;
	int numNucleos = get_nprocs_conf();

	sprintf(comando, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");
	fp = popen(comando, "r");
	fscanf(fp, "%lf", &porcentagem);

	return porcentagem/numNucleos;
}

//Memória: pmap <PID> -x | grep total | awk '{print $4}'
int getMemoryUsage(int pid){
	char comando[50];
	FILE *fp; //Ponteiro para a leitura do arquivo retornado pelo popen
	int memoria;

	sprintf(comando, "%s%d%s", "pmap ", pid, " -x | grep total | awk '{print $4}'");
	fp = popen(comando, "r");
	fscanf(fp, "%d", &memoria);

	return memoria;
}

int main (int argc, char *argv[], char *envp[]) {
	system("clear");

	int pid = fork();

	if ( pid < 0 ) {
		perror ("Erro: ");
		exit (-1);
	}
	else if ( pid > 0 ) {
		struct sysinfo info;
		sysinfo( &info );
		printf("PID do processo filho: %d\n\n", pid);
		printf("Memória total: %lu\n", ((size_t)info.totalram * (size_t)info.mem_unit)/1024);

		for (i = 0; i < 10; i++){
			printf("Tempo: %ds\tCPU: %.2lf%%\tMemória: %d kB\n", i, getCpuUsage(pid), getMemoryUsage(pid));
			sleep(1);
		}
		kill(pid, SIGKILL); //Mata o processo filho
	}
	else {
		if (strcmp(argv[1], "cpu") == 0 ) {
			consumeCPU();
		} else if ( strcmp(argv[1], "cpu-mem") == 0 ) {
			consumeMemory();
		}

		fprintf(stderr, "Erro: %s\n", strerror(22));
		exit(22);
	}

	//Execve??
	perror ("\nErro"); /* execve não funcionou */

	printf ("Tchau!\n");
	exit(0); /* encerra o processo com sucesso (código 0) */

}

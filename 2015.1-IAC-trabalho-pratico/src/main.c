#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>

void usoCPU() {
	for (;;) {}
}

//TODO como ele termina a iteração muito rápido, o processador logo fica ocioso.
void usoMemoria() {
	int i;
	for (i = 0; i < 10000; i++) {
			malloc(10000000);
	}
	sleep(15);
}

int main (int argc, char *argv[], char *envp[]) {
	system("clear");

	int pid = fork(); /* replicação do processo */

	if ( pid < 0 ) {
		perror ("Erro: ");
		exit (-1); /* encerra o processo com código de erro -1 */
	}
	else if ( pid > 0 ) {

		int i, j; //Iteradores para uso geral

		FILE *fp; //Ponteiro para leitura de arquivos

		char file_path[50] = "/proc/", str_pid[50], cpu_command[100] = "ps -p ", mem_command[100] = "ps -p ";
		char path[50];
		char *memtotal = NULL;
		char *line = NULL;
		size_t len = 0;
		ssize_t read;

		double pcpu, pmem, memoria;

		int numNucleos = get_nprocs_conf(); //Número de núcleos do processador

		sprintf(str_pid, "%d", pid);

		strcat(file_path, str_pid);
		strcat(file_path, "/status");
		strcat(cpu_command, str_pid);
		strcat(cpu_command, " -o %cpu | sed 1d");
		strcat(mem_command, str_pid);
		strcat(mem_command, " -o %mem | sed 1d");

		printf("PID: %d\n", pid);
		fp = fopen("/proc/meminfo","r");

		while ((read = getline(&line, &len, fp)) != -1) {
			if (!strncmp(line, "MemTotal:", 9))
			{
				memtotal = strdup(&line[17]);
				memoria = atof(strtok(memtotal, " "));
				printf("Memória Total: %.2lf KB\n", memoria);
			}
		}

		printf("Número de núcleos: %d\n\n", numNucleos);

		for(j = 0; j <= 100; j++){

			printf("Tempo: %ds\t", j);

			fp = popen(cpu_command,"r");

			while (fgets(path, sizeof(path)-1, fp) != NULL) {
				for(i = 0; i < strlen(path);i++){
					if(path[i] != ' '){
						path[i-1] = path[i];
					}
				}
				pcpu = atof(path);
				printf("CPU: %.2lf%%", pcpu/numNucleos);
			}
			fclose(fp);

			fp = popen(mem_command,"r");

			while (fgets(path, sizeof(path)-1, fp) != NULL) {
				for(i = 0; i < strlen(path);i++){
					if(path[i] != ' '){
						path[i] = path[i];
					}
				}
				pmem = atof(path);
				printf("\tMemória: %.2lf KB\n", (memoria*pmem)/100);
			}
			fclose(fp);

			sleep(1);
		}

		if (line) {
			free(line);
		}

		kill(pid, SIGKILL); //Mata o processo filho

	}
	else {
		if (strcmp(argv[1], "cpu") == 0 ) {
			usoCPU();
		} else if ( strcmp(argv[1], "cpu-mem") == 0 ) {
			usoMemoria();
		}
			fprintf(stderr, "Erro: %s\n", strerror(22));
			exit(22);

	}

	//Execve??
	perror ("\nErro"); /* execve não funcionou */

	printf ("Tchau!\n");
	exit(0); /* encerra o processo com sucesso (código 0) */

}

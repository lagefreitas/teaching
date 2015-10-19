#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>
#include <pthread.h>

#define NUCLEOS get_nprocs_conf() //Total CPU cores

//Global general purpose iterator
int i;

void consumeCPU() {
	for (;;) {}
}

void *consumeCPU_thread(void *threadid)
{
  for(;;){}
}

void consumeMemory() {
	//Thread to the continuous CPU usage
	pthread_t thread;
	pthread_create(&thread, NULL, consumeCPU_thread, (void *)1);

	for(;;){
		malloc(1024); //Each loop allocates 1024 bytes in memory
		usleep(100);
	}
}

//CPU: ps -p <PID> -o pcpu | sed 1d | tr -d ' '
double getCpuUsage(int pid){
	char comando[50];
	FILE *fp; //Pointer to the file reading returned by popen
	double porcentagem;

	sprintf(comando, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");
	fp = popen(comando, "r");
	fscanf(fp, "%lf", &porcentagem);
	fclose(fp);

	return porcentagem/NUCLEOS;
}

//Memory: pmap <PID> -x | grep total | awk '{print $4}'
int getMemoryUsage(int pid){
	char comando[50];
	FILE *fp; //Pointer to the file reading returned by popen
	int memoria;

	sprintf(comando, "%s%d%s", "pmap ", pid, " -x | grep total | awk '{print $4}'");
	fp = popen(comando, "r");
	fscanf(fp, "%d", &memoria);
	fclose(fp);

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

		FILE *logFile, *plotFile; //Pointers to log.txt and plot.txt files
		logFile = fopen("log.txt", "w"); //Opening log.txt with write permission
		plotFile = fopen("plot.txt", "w"); //Opening plot.txt with write permission

		printf("PID: %d\n", pid); //PID of the child process
		printf("Número de núcleos: %d\n", NUCLEOS);
		printf("Memória total: %lu MB\n\n", ((size_t)info.totalram * (size_t)info.mem_unit)/(1024*1024)); //Total primary memory

		printf("Tempo\tCPU\tMemória\n");

		for (i = 0; i < 10; i++){
			double cpuUsage = getCpuUsage(pid);
			int memoryUsage = getMemoryUsage(pid);
			printf("%ds\t%.2lf%%\t%d kB\n", i, cpuUsage, memoryUsage);
			fprintf(logFile, "%ds\t%.2lf%%\t%d kB\n", i, cpuUsage, memoryUsage); //Writing the data in log.txt
			fprintf(plotFile, "%d %.2lf %d \n", i, cpuUsage, memoryUsage); //Writing the data in plot.txt
			sleep(1);
		}
		//Closing the opened files
		fclose(logFile);
		fclose(plotFile);
		kill(pid, SIGKILL); //Kill the child process
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

	if (strcmp(argv[2], "plot") == 0 ) {
		system("julia plot.jl");
	}

	exit(0); /* Terminates the process successfully (code 0) */

}

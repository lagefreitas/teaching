#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {

    int pid ; //process identifier
    int i;	//counter
    int nucleos; //number of CPU's cores
    FILE *file; //auxiliar file
    char cpu[100]; //command of cpu usage 
    char mem[100]; //command of memory usage 
    char cm[100]; //command used to kill the process
    char aux1[100], aux2[100];
    
	pid = fork() ; //process replication

	if (pid < 0) { //if fork doesn't work
		perror ("Erro: ") ;
		exit (-1) ; //terminates the process with error code -1
	}
	else if(pid > 0) //if I'm the father process 
	{
        //these sprintf function format the used command
        sprintf(aux1, "%s%d%s", "ps -e -o pid,pcpu | grep ", pid, " | awk '{print $2}'");
        sprintf(aux2, "%s%d%s", "cat /proc/", pid,"/status | grep VmSize | awk '{print $2}'");
        sprintf(cm, "%s%d", "kill -9 ", pid);
        
        nucleos = get_nprocs_conf();

        for(i = 0; i < 10; i++) {
	    printf("t%d:\n", i + 1);	
            //file receives the result of the command and the string cpu stores the result
            file = popen(aux1, "r");
            fgets(cpu, 100, file);
            printf("CPU: %.1f%c\n", atof(cpu)/nucleos , 37);
            
            //file receives the result of the command and the string mem stores the result
            file = popen(aux2, "r");
            fgets(mem, 100, file);
            printf("Memória: %d kB\n", atoi(mem));
            
            printf("----\n");
            sleep(1); //waits one second
        }
        fclose(file);
        system(cm); //running the killing command
	}
	else //else I'm the son process
	{
		if(strcmp(argv[1], "cpu") == 0) {
		    for(;;) {
		    }
		}

        if(strcmp(argv[1], "cpu-mem") == 0) {
            for (;;) {
                malloc(sizeof(100000));
            }
		}
	}
	perror ("Erro: ") ; //execve didn't work

	printf ("Tchau !\n") ;
	exit(0) ; //terminates the process with success (code 0) */ 

}



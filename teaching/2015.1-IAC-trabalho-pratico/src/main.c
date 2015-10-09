#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {

	int pid ; //process identifier
    int i;
    char cpu[100]; //command of cpu usage 
    char mem[100]; //command of memory usage 
    char cm[100]; //command used to kill the process
    
	pid = fork() ; //process replication

	if (pid < 0) { //if fork doesn't work
		perror ("Erro: ") ;
		exit (-1) ; //terminates the process with error code -1
	}
	else if(pid > 0) //if I'm the father process 
	{
        //this 3 sprintf functions format the used commands
        sprintf(cpu, "%s%d%s", "ps -e -o pid,pcpu | grep ", pid, " | awk '{print $2}'");
        sprintf(mem, "%s%d%s", "cat /proc/", pid,"/status | grep VmRSS | awk '{print $2}'");
        sprintf(cm, "%s%d", "kill -9 ", pid);
        
        for(i = 0; i < 10; i++) {
            printf("CPU(%c)\n", 37);
            system(cpu); //running the cpu usage command
            printf("Mem(kB)\n");
            system(mem); //running the memory usage command
            printf("----\n");
            sleep(1); //waits one second
        }
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


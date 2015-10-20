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
    FILE *log; //file that stores the results
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
        
        //the "ps" command lists the running process. The parameters "pid" and "pcpu" returns the CPU consumption through process with this PID
        //grep is used to filter result of system log files(in this case, I just want the data relative to this PID)
        //awk formats outputs(in this case, I just want to print the second column of output)
        sprintf(aux1, "%s%d%s", "ps -e -o pid,pcpu | grep ", pid, " | awk '{print $2}'");
        
        //the /proc on Linux is a virtual directory that provides, among others, information about processes. 
        //"VmRSS" indicates the amount of memory currently in use by process 
        sprintf(aux2, "%s%d%s", "cat /proc/", pid,"/status | grep VmRSS | awk '{print $2}'");
        
        //this command "kills" the process 
        sprintf(cm, "%s%d", "kill -9 ", pid);
        
        nucleos = get_nprocs_conf();

	log = fopen("log.out", "w");

        for(i = 0; i < 10; i++) {
	    printf("t%d - ", i + 1);	
            //file receives the result of the command and the string cpu stores the result
            file = popen(aux1, "r");
            fgets(cpu, 100, file);
            printf("CPU: %.1f%c. ", atof(cpu)/nucleos , 37);
	    fprintf(log, "CPU: %.1f%c. ", atof(cpu)/nucleos , 37);	
            
            //file receives the result of the command and the string mem stores the result
            file = popen(aux2, "r");
            fgets(mem, 100, file);
            printf("Memória: %d kB\n", atoi(mem));
            fprintf(log, "Memória: %d kB\n", atoi(mem));
            sleep(1); //waits one second
        }
        
	fprintf(log, "\n");
        fclose(file);
        fclose(log);
        
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



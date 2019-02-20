#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


/*
 * This program creates a child process and monitors it's cpu usage for 30 seconds.
 */




/* This function returns the bash command used
 * Signal variable defines data type to be obtained(cpu usage or mem usage). (-1 when we want cpu usage and argv[1] == "cpu", 
 0 when when we want cpu usage and argv[1] == "cpu-mem" and 1 when we want mem usage )
 */
char * getBashCommand(int pid, int signal){
    char * bash_cmd = (char*) malloc(256 * sizeof(char));
    if(signal == -1 || signal == 0) {

       sprintf(bash_cmd,"ps u %d | awk '{print $3}' | grep -v %%CPU", pid); //cpu usage command

    }else{
        sprintf(bash_cmd,"ps u %d | awk '{print $5}' | grep -v VSZ", pid); // mem usage command
    }

    return bash_cmd;

}

//print data on bash session
void printBash(int signal, char * cpuUsage, char * memUsage){

    printf("Uso de UCP(%%): %s\n", cpuUsage);
    if(signal == -1)
        return;
    printf("Consumo de MEM.(Kb): %s\n", memUsage);

}


int main(int argc, char const *argv[]) {

    //in case there is no argument
    if (argv[1] == NULL)
    {
        printf("Defina um parâmetro válido\n");
        return -1;
    }
    //in case argument is incorrect
    if( strcasecmp(argv[1], "ucp") != 0 && strcasecmp(argv[1], "ucp-mem") != 0){
        printf("%s\n", argv[1]);
        printf("Parâmentro incorreto.\n"
               "Operação cancelada.\n");
        exit(1);
    }


    //buffers used to get data
    char buffer1[1000], buffer2[1000];
    char * memUsage, * cpuUsage;

    // time_t variables are used to time count

    //pipe file for popen
    FILE * pipe;


    int pid, signal;
    pid = fork();
    signal = (strcasecmp(argv[1], "ucp") == 0 ? -1 : 0);


    //in case an error occurs
    if(pid < 0){
        exit(1);

    // when pid > 0 it means that parent-process is running and pid is child's pid
    }if (pid > 0) {
        int i;

        //time variables
        time_t initTime, currentTime;
        time(&initTime);

        //get current time
        time(&currentTime);
        for (i = 0; difftime(currentTime, initTime) < 10.00f;) {
            if(difftime(currentTime, initTime) == i * 1.00f){

                    pipe = popen(getBashCommand(pid, signal), "r"); //get cpu data
                    cpuUsage = fgets(buffer1, sizeof(buffer1), pipe);
                    pclose(pipe);
                    if(signal != -1){//get mem data
                        signal = (signal == 0 ? 1 : 0);
                        pipe = popen(getBashCommand(pid, signal), "r");
                        memUsage = fgets(buffer2, sizeof(buffer2), pipe);
                        pclose(pipe);
                        signal = (signal == 0 ? 1 : 0);
                    }

                    printBash(signal, cpuUsage, memUsage);
                    i++;
            }

            time(&currentTime);
        }
        kill(pid, 1);
        pclose(pipe);

    //when pid == 0, wich means only child process can get here
    }else{

        //when argv[1] == "ucp", child process gets here
        if(signal == -1) {
            for (;;) {
            }

        //when argv[1] = "ucp-mem", child process allocates a 1 byte block of memory in a infinity loop
        }else{
            int i;
            for (i = 0;; i++) {
               if(i%10 == 0){
                malloc(sizeof(unsigned char));
                }
            }
        }

    }
}
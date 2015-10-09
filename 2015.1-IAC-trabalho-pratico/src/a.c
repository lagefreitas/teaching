
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[], char *envp[]) {
  for(;;){ //Código com uso intenso de UCP e Memória
        malloc(1024);
        usleep(1000);
  }
}

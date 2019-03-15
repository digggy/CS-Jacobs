
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (; argc > 0; argc--) {
        int pid;
        pid=fork();
        if (pid == 0) { 
	  //delay the child process	
         	  sleep(10);
	  exit(1);
        }else{
	  //print the process id of childs
	  printf("The process id is : %d\n",pid); 
        }
    }
 
printf("\nThe main process ended\n\n");
return 0;
}

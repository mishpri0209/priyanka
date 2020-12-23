#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    const char *filename = "/root/ques_jailconfine/audit.txt";
    int pid1, pid2; 

    pid1 = fork();

    if (pid1 > 0)  
    {   // Parent process
        fprintf(stderr,"parent> Parent spawned Server_Process\n");
        
        pid2 = fork();
        
        if (pid2 > 0) { // Again, parent process.
          fprintf(stderr,"parent> Parent spawned Client_Process\n");
        }
        else { 
          fprintf(stderr,"client> In Client_Process\n");
          // Client process, spawned by the parent process.
        }
    } 
    else { 
      // Server process, spawned by the parent process.
      fprintf(stderr,"server> In Server_Process\n");
    }

    return 0;
}

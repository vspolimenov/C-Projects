#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

void execCommand(char* command){

 char message[80] ="/bin/";

        strcat(message, command);
        if (execl(message, command,0) == -1) {
               err(99, "err execling");
        } else {
                printf("foobar\n");
        }
     exit(0);
}

void subProcesses(int i, char* argv[], int successCounter, int errorCounter){
int status;
if(fork() > 0) {
wait(&status);
if(WIFEXITED(status)){
      int es = WEXITSTATUS(status);
        if(es ==0){
           successCounter++;
        } else{
        errorCounter++;
      }

execCommand(argv[i]);
}
} else {

if(i==1) {
printf("Succeeded: %d\n Errors: %d\n", successCounter, errorCounter);
exit(0);
}else{

subProcesses(i-1,argv, successCounter, errorCounter);
printf("Child");
exit(0);
}
}
}

int main(int argc, char* argv[]) {
int successCounter = 0;
int errorCounter = 0;
subProcesses(argc - 1, argv, successCounter, errorCounter);
}

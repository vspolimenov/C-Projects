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

int main(int argc, char* argv[]) {

int successCounter = 0;
int errorCounter = 0;
int status;

for(int i = 1; i < argc; i++) {
	if(fork()>0) {
		wait(&status);
	
       			 int es = WEXITSTATUS(status);
 		         if(es ==0){
          			 successCounter++;
       			 } else{
       				 errorCounter++;
     			 }
	
	} else {
		execCommand(argv[i]);

	}
}

printf("Succeeded: %d\n Errors: %d\n", successCounter, errorCounter);
exit(0);
}

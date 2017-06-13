#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execCommand(char* command){
 char message[80] ="/bin/";

        strcat(message, command);
	printf("%s with PID = %d\n",command, getpid());
        if (execl(message, command,0) == -1) {
               err(99, "err execling");
	} else {
		printf("foobar\n");
	} 
     exit(0);
}


int main (int argc, char* argv[]) {

 if (argc != 4) {
	 errx(1, "err");
}

int status1;
if(fork()>0) { 
	wait(&status1);
	  if(WIFEXITED(status1)){
        int es = WEXITSTATUS(status1);
        printf("Exit status was %d\n", es);
        }
        execCommand(argv[3]);	
       } else {
	int status2;
	 if(fork()>0) {
	 wait(&status2);
	  if(WIFEXITED(status2)){
        int es = WEXITSTATUS(status2);
        printf("Exit status was %d\n", es);
        }

	execCommand(argv[2]);
	}else{
	execCommand(argv[1]);
	}
}
exit(0);
}


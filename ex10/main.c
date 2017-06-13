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

 if (argc != 3) {
         errx(1, "err");
}
int status;

if(fork() > 0) {
wait(&status);
if(WIFEXITED(status)){
        int es = WEXITSTATUS(status);
        if(es ==0){
	   execCommand(argv[2]);
	} else{
	exit(-1);
	}
        }

}else {
   execCommand(argv[1]);
}
exit(0);
}


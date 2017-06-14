#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>

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

 if (argc != 4) {
         errx(1, "err");
}

int status;
int fd1;
fd1=open(argv[3], O_CREAT|O_RDWR|O_TRUNC, S_IRWXU );
        if(fd1==-1) {
                err(99,"Error openign file");
        }

if(fork() > 0) {
wait(&status);
if(WIFEXITED(status)){
        int es = WEXITSTATUS(status);
        if(es ==0){
          write(fd1, argv[1],strlen(argv[1]));
     	 }
        }
execCommand(argv[2]);
}else {
   execCommand(argv[1]);
}
exit(0);
}


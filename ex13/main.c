#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

void execCommand(char* command, int value){
 char message[80] ="/bin/";
        strcat(message, command);
       if(execl(message, command,0)==-1) { 
	if(value == -1){
	printf("%d",-1);
	}
	value = -1;
	exit(-1);
	}
}



int main(int argc, char* argv[]) {

 if (argc != 3) {
         errx(1, "err");
}

    int fd[2];
    int value = 0;
pipe(fd);
if(fork() > 0) {
printf("Parent: %d\n", getpid());
close(fd[0]);
value  = getpid();
write(fd[1], &value, sizeof(int));
close(fd[1]);
execCommand(argv[1], value);
}else {
printf("Child: %d\n", getpid());
close(fd[1]);
read(fd[0], &value, sizeof(int));
if(value >0){
printf("First: %d\n", value);
} else if(value == 0) {
printf("First: %d\n", getpid());
}
close(fd[0]);
   execCommand(argv[2], value);
}

exit(0);
}


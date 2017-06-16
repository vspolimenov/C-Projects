#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char* argv[]) {

if(argc != 2) {
	err(33, "Wrong arguments number!\n");
}

int pd1[2];

pipe(pd1);
int pid = fork();

if(pid == -1) {
	err(33, "Problem forking!\n");

}

if(pid  > 0) {

	int pd2[2];
	pipe(pd2);
	int pid2 = fork();

	if (pid2 == -1) {
		err(33, "Problem forking\n");
	}
	
	if(pid2 == 0) {
		close(pd1[1]);
		close(pd2[0]);
		dup2(pd1[0], 0);
		dup2(pd2[1], 1);
		
		if (execlp("sort", "sort",0)==-1){
                	err(33, "Error execling!");
       		 }
	}
	
	close(pd1[0]);
	close(pd1[1]);
	close(pd2[1]);
	dup2(pd2[0],0);
	
	if (execlp("wc", "wc","-l",0)==-1){ 
		err(33, "Error execling!");
	}

} else {

	close(pd1[0]);
	dup2(pd1[1], 1);
	
	 if (execlp("cat","cat", argv[1],0)==-1){
                err(33, "Error execling!");
        }

}

exit(0);
}

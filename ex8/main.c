#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char* argv[]) {

if(argc != 2) { 
	err(33,"Wrong number of parameters");
}

int status;
int fd1;

if(fork()>0){
wait(&status);
char c;
fd1=open(argv[1], O_RDONLY);
        if(fd1==-1) {
                err(99,"Error openign file");
        }
while(read(fd1,&c,1)) {
write(1,&c,1);
c = ' ';
write(1,&c,1);
}
close(fd1);
} else {
    fd1=open(argv[1], O_CREAT|O_RDWR|O_TRUNC, S_IRWXU );
	if(fd1==-1) {
		err(99,"Error openign file");
	}
	if(write(fd1, "foobar\n",8)==-1){
		err(29,"Error writing file");
	}
close(fd1);
}

exit(0);
}

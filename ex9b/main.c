#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
int main() {

int fd1;
int status;

fd1=open("test", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU );
        if(fd1==-1) {
                err(99,"Error openign file");
        }
if(fork() > 0) {
wait(&status);
write(fd1, "foo",3);

}else {
write(fd1,"bar",3);
}

close(fd1);
exit(0);
}


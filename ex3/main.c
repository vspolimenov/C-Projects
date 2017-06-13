#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
        if (argc < 2) {
                err(1, "Wrong number of arguments");
	}

        int fd1;
        int fd2;
        char a;

        if ( ( fd2 = open(argv[argc-1], O_CREAT|O_WRONLY, S_IRWXU ) )== -1  )  {
                err(1, "Can't open write descriptor.\n");
        }
    
        for (int i=1; i<argc-1; i++){
                if ( ( fd1 = open(argv[i], O_RDONLY) ) == -1 ) {
                        fprintf(stderr, "File failed to open.\n");
                }


                else {
                        while(read(fd1, &a, 1)){
                                write(fd2, &a, 1);
                        }
                        close(fd1);
                }
        }

        close(fd2);

       exit(0);
}


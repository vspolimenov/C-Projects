#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]){

   if(argc != 3) {
        write(2, "Invalid arguments count!",33);
        exit(-1);
        }

        int fd1;
        int fd2;
        char a;

          if ( ( fd1 = open(argv[1], O_RDONLY) ) == -1 ) {
                 err(1, "Can't open write descriptor.\n");

          }

          if ( ( fd2 = open(argv[2], O_CREAT|O_WRONLY, S_IRWXU ) )== -1  )  {
                  close(fd1);
                  err(1, "Can't open write descriptor.\n");

          }

                while(read(fd1, &a, 1)){
                         write(fd2, &a, 1);
                       }

                       close(fd1);
                       close(fd2);
         exit(0);
}
                                                        

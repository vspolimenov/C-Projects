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
        char a;
       
        for (int i=1; i<argc; i++){
         
	  if ( ( fd1 = open(argv[i], O_RDONLY))== -1  )  {
                err(1, "Can't open write descriptor.\n");
        }
	
          while(read(fd1, &a, 1)){
               write(1, &a, 1);
          }
          close(fd1);
       }

exit(0);
}

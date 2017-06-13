#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
   
        int fd1;
        int fd2;
        char a;

	 if ( ( fd1 = open("/etc/passwd", O_RDONLY) ) == -1 ) {
            fprintf(stderr, "File failed to open.\n");
         }


         if ( ( fd2 = open("passwd", O_CREAT|O_WRONLY, S_IRWXU ) )== -1  )  {
                err(1, "Can't open write descriptor.\n");
       }
             while(read(fd1, &a, 1)){
                  if(a==':'){
	           a='?';
                }
                  write(fd2, &a, 1);
              }

     close(fd1);
     close(fd2);

	exit(0);
}

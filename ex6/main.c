#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {

        if (argc != 2) {
                errx(1, "err");
        }
char message[80] ="/bin/";
 strcat(message, argv[1]);
printf("%s\n", message);
      if (execl(message, argv[1],(char*)NULL) == -1) {
               err(99, "err execling");
       } else {
		printf("%s\n",argv[1]);
           }

        exit(0);
}

#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){

if (argc != 3) {
                err(1, "Wrong number of arguments");
}

int fd1;
 if ( ( fd1 = open(argv[2], O_RDONLY) ) == -1 ) {
            fprintf(stderr, "File failed to open.\n");
         }

uint16_t num[3200]; 
int i =0; 
uint16_t max = 0;
uint16_t min = 9999;
while(read(fd1,&num[i] , 16)){
	if(strcmp("--max",argv[1])==0) {
		if(num[i] >max) {
		max = num[i];
		}
	} else if( strcmp("--min",argv[1]) == 0){
        	if(num[i] < min){
 		min = num[i];
		}
	}
	else if(strcmp("--print", argv[1]) == 0){
        	printf("%d\n", num[i]);
	}
       i++;
}

if(strcmp("--max",argv[1])==0) {
	printf("%d\n", max);
}

if(strcmp("--min",argv[1])==0) {
	printf("%d\n", min);
}

close(fd1);
exit(0);

}

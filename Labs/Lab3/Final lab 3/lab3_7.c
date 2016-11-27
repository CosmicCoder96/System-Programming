#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    int fd[2];
    int depth = 0; /* keep track of number of generations from original */
    int i;
    pipe(fd);  /* create a pipe which will be inherited by all children */
    for(i=0; i<10; i++) {
        if(fork() == 0) { 
            write(fd[1], &i, 1);  /* write one byte into the pipe*/
            depth += 1;
        }
    }
    close(fd[1]);
    if( depth == 0 ) { /* original process */
      i=0;
      while(read(fd[0],&depth,1) != 0)
        i += 1;
      printf( "%d total processes spawned\n", i);
    }

    return 0;
}

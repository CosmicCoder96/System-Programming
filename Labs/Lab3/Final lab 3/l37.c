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
	    printf("%d ",i);
            depth += 1;
        }
    }
	printf("\n");
    close(fd[1]);
    if( depth == 0 ) { /* original process */
      i=0;
      while(read(fd[0],&depth,1) != 0)
      {
	  i += 1;
	  printf("%d ",depth);
	}
	printf("\n");
      printf( "%d total processes spawned\n", i);
	printf("%d %d\n",fd[0],fd[1]);
    }
    return 0;
}

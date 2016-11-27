#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

	int pid;
	int status;

	 pid =fork();
	 if(pid>0)
	 {
		printf("Now in parent :P\n");
	 	pid=wait(&status);
		printf("In parent \nprocess id of parent = %d \nchild process id = %d \nstate of child in decimal = %d \nstate of child in heaxadecimal = %04x\n",getpid(),pid,status,status);
	 }
	 else
	 {
	 	printf("In child and it's process id = %d\n",getpid());
		exit(0);
	 }
	return 0;

}

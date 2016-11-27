#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int pid,state;
	printf("BEFORE fork() : Parent id=%d\n",getpid());
	pid=fork();
	if(pid>0)
	{
		printf("Going into child process...\n");
		wait(&state);
		printf("Back in parent...\n");
		printf("PID of the child id=%d , state=%d\n",pid,state);
	}
	if(pid==0)
	{
		printf("In child process\n");
		printf("Current state of the child=%d\n",state);
		printf("Current state of the child=%x\n",state);
		exit(0);
	}
	return 0;
}

#include <stdio.h>
#include <unistd.h>

int main ()
{
	int x;
	int pid;
	pid = fork();
	if (pid > 0) {
		wait();
		printf("in parent process with id:%d\n",getpid());
		printf("address of variable:%p\n", (void*)&x);
	}
	else if (pid == 0) {
		printf("in child process with parent_id:%d\n",getppid());
		printf("address of variable:%p\n", (void*)&x);
	}
	return 0;
}
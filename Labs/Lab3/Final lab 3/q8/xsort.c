#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc,char *args[])
{
	int ans,pid,status;
	pid=fork();
	const char *argv[100]={"sort1",args[1],NULL};
	if(pid==0)
	{
		ans=execve(argv[0],(char **)argv,NULL);
		exit(0);
	}
	else
	{
		pid=wait(&status);
	}
	return 0;
}

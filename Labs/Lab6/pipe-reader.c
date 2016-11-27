#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main()
{

	int fd;
	char * var = "./pipe";
	char buff[100];
	mkfifo(var, 0666);
	fd = open(var,O_RDONLY);
	printf("Please enter some input in the other terminal in the writer file to continue\n");
	while(1)
	{
		printf("Waiting for input .... \t");
		read(fd,buff, sizeof(buff));
		printf("Got it .. :%s",buff);
		if(strcmp(buff,"exit\n")==0)
			break;
	}
	close(fd);
	unlink(var);
	printf("\nExiting ...\n");
	exit(0);
	
}
	
	

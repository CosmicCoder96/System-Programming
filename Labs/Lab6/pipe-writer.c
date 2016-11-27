#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main()
{

	int fd;
	char * var = "./pipe";
	char buff[100];

	fd = open(var,O_WRONLY);
	while(1)
	{
		printf("Enter input .... \t");
		fgets(buff, sizeof(buff),stdin);
		printf("\nWriting input....");

		write(fd,buff, sizeof(buff));
		printf("\nDone..\n");
		if(strcmp(buff,"exit\n")==0)
		break;
	}
	close(fd);
	unlink(var);
	printf("\nExiting ...\n");
	exit(0);
	
}
	
	

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char * pipe1 = "./pipe1";
	char * pipe2 = "./pipe2";
 	int buff1, buff2;
	srand(time(0));
	int fd1[2], fd2[2],pid,status,c1=0,c2=0,e;
	pipe(fd1);
	pipe(fd2);
	pid = fork();
	if(pid==0)
	{
		
		while(1)
		{
			buff1 = rand()%23;
			close(fd1[0]);
			write(fd1[1],&buff1,sizeof(buff1));
			if(c1==10||c2==10)
				break;
//			printf("written\n");
		}

	}
	else
	{
		pid = fork();
		if(pid ==0)
		{
			
			while(1){
			buff2 = rand()%17;
			close(fd2[0]);
			write(fd2[1],&buff2,sizeof(buff2));
			if(c1==10||c2==10)
				break;
			}
		}
		else
		{
			while(1)
			{
				e = rand()%2;
				close(fd1[1]);
				read(fd1[0], &buff1, sizeof(buff1));
				close(fd2[1]);
				read(fd2[0], &buff2, sizeof(buff2));
				if(e==0)
				{
					printf("Minimum winner \t");
				}
				else
				{
					printf("Maximum winner \t");
				}
				printf("child 1 writes :%d child 2 writes : %d",buff1,buff2);
				if(e==0)
				{
					if(buff1<buff2)
					{
						c1++;
						printf("child 1 wins this round\n");
					}
					else
					{
						c2++;
						printf("child 2 wins this round\n");
					}
					if(c1==10||c2==10)
						break;

				}
				else
				{
					if(buff1>=2)
					{
						c1++;
						printf("child 1 wins this round\n");
					}
					else
					{
						c2++;
						printf("child 2 wins this round\n");
					}
					if(c1==10||c2==10)
						break;
					//printf("%s %s\n",buff1,buff2);
				}
				}
			
			if(c1==10)
			{	
				printf("Child 1 has won the game\n");
			}
			else
			{
				printf("Child 2 has won the game\n");
			}
		}	
	}
}

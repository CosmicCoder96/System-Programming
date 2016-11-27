#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
void rec(char c[100])
{
	DIR *dp;
	struct dirent *myf;
	dp=opendir(c);
	if(errno>0)
	{
		perror(c);
		exit(0);
	}
	if(!dp)
	{
		perror(c);
	}
    	struct stat path_stat;
    	chdir(c);
	if(errno>0)
	{
		perror(c);
	}
	while((myf=readdir(dp))!=NULL)
	{
		int z = stat(myf->d_name, &path_stat);
    		if(z<0)
		{
			perror(myf->d_name);
		}
		if(strcmp("..",myf->d_name)==0||strcmp(".",myf->d_name)==0)
		{
			continue;
		}
		if(S_ISREG(path_stat.st_mode))
		{
			printf("%s\n",myf->d_name);
			int y=unlink(myf->d_name);
			if(y<0)
			{
				perror(myf->d_name);
			}
		}
		else if(S_ISDIR(path_stat.st_mode))
		{
			rec(myf->d_name);
			printf("%s\n",myf->d_name);
			chdir("../");
			int y=rmdir(myf->d_name);
			if(y<0)
			{
				perror(myf->d_name);
			}
		}
	}
	closedir(dp);
}
int main()
{
        char str[100];
        scanf("%s",str);
        rec(str);
        chdir("../");
        int y=rmdir(str);
        if(y<0)
        {
            perror(str);
        }
        return 0;
}

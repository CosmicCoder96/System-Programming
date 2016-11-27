#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include<string.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
char fs[100];
void rec(char *c)
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
        if(strcmp(c,fs)==0)
        {
            printf("found %s in directory %s\n",fs,c);
            exit(0);
        }
        chdir(c);
        struct stat path_stat;
        while((myf=readdir(dp))!=NULL)
        {
            if(strcmp("..",myf->d_name)==0||strcmp(".",myf->d_name)==0)
            {
                continue;
            }
            //printf("%s\n",myf->d_name);
            int z = stat(myf->d_name, &path_stat);
                if(z<0)
            {
                perror(myf->d_name);
            }
            if(S_ISREG(path_stat.st_mode))
            {
                if(strcmp(myf->d_name,fs)==0)
                {
                    printf("found %s in directory %s\n",fs,c);
                    exit(0);
                }
            }
            else if(S_ISDIR(path_stat.st_mode))
            {
                if(strcmp(myf->d_name,fs)==0)
                {
                    printf("found %s in directory %s\n",fs,c);
                    exit(0);
                }
                rec(myf->d_name);
            }
        }
}
int main()
{
	char str[100];
	scanf("%s%s",str,fs);
	rec(str);
	printf("Not found %s : \n",fs);
	return 0;
}

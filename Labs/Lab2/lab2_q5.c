#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include<string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
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
                //printf("%s\n",myf->d_name);
                int y=unlink(myf->d_name);
                if(y<0)
                {
                    perror(myf->d_name);
                }
            }
            else if(S_ISDIR(path_stat.st_mode))
            {
                rec(myf->d_name);
                //printf("%s\n",myf->d_name);
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
        char str[1000];
        while(1)
        {
            printf("myshell$");
            scanf("%s",str);
            if(strcmp(str,"exit")==0)
            {
                break;
            }
            else if(strcmp(str,"cd")==0)
            {
                char w[1000];
                scanf("%s",w);
                chdir(w);
                if(errno>0)
                {
                    perror(w);
                }
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
                        fprintf(stdout, "Current working dir: %s\n", cwd);
                    }
                else
                {
                        perror("getcwd() error");
                }
            }
            else if(strcmp(str,"pwd")==0)
            {
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
                    fprintf(stdout, "Current working dir: %s\n", cwd);
                    }
                else
                {
                    perror("getcwd() error");
                }
            }
            else if(strcmp(str,"mkdir")==0)
            {
                char w[1000];
                scanf("%s",w);
                int c=mkdir(w);
                if(errno>0)
                {
                    perror(w);
                }
                if(!c)
                {
                    printf("Directory created\n");
                }
                else
                {
                    printf("Error\n");
                }
            }
            else if(strcmp(str,"ls")==0)
            {
                char w[1000];
                scanf("%s",w);
                DIR *dp;
                struct dirent *myf;
                dp=opendir(w);
                if(errno>0)
                {
                    perror(w);
                }
                if(!dp)
                {
                    perror(w);
                }
                printf("%s :\n",w);
                while((myf=readdir(dp))!=NULL)
                {
                    if(strcmp(myf->d_name,".")==0||strcmp(myf->d_name,"..")==0)
                    {
                        continue;
                    }
                    printf("%s\n",myf->d_name);
                }
                closedir(dp);
            }
            else if(strcmp(str,"rmdir")==0)
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
                printf("%s removed\n",str);
            }
            else
            {
                printf("Command not found\n");
            }
        }
        return 0;
}

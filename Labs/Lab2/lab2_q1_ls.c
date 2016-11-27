#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char ** argv)
{
        DIR *dp;
        struct dirent *myf;
        dp=opendir(argv[1]);
        if(!dp)
        {
            perror(argv[1]);
            exit(0);
        }
        printf("%s :\n",argv[1]);
        while((myf=readdir(dp))!=NULL)
        {
            if(strcmp(myf->d_name,".")==0||strcmp(myf->d_name,"..")==0)
            {
                continue;
            }
            printf("\t%s\n",myf->d_name);
        }
        closedir(dp);
        return 0;
}

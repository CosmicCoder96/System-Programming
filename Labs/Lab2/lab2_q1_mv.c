#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char ** argv)
{
        char str[1000],w[1000];
        scanf("%s%s",str,w);
        int fd=open(str,O_RDWR|O_CREAT|O_APPEND,0644);
        if(fd==-1)
        {
            printf("Error in opening file\n");
        }
        else
        {
            int sz,fw;
            char *c;
            c=(char *)malloc(100*sizeof(char));
            fw=open(w,O_RDWR|O_CREAT|O_APPEND,0644);
            while((sz=read(fd,c,100)))
            {
                c[sz]='\0';
                sz=write(fw,c,sz);
            }
            int y=unlink(str);
            fw=open(w,O_RDONLY);
            while((sz=read(fw,c,100)))
            {
                c[sz]='\0';
                printf("%s\n",c);
            }
        }
        return 0;
}

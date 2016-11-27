#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        char str[1000];
        scanf("%s",str);
        int fd=open(str,O_RDONLY);
        if(fd==-1)
        {
            printf("Error in opening file\n");
        }
        else
        {
            int sz;
            char *c;
            c=(char *)malloc(100*sizeof(char));
            while((sz=read(fd,c,100)))
            {
                c[sz]='\0';
                printf("%s\n",c);
            }
        }
        close(fd);
        return 0;
}

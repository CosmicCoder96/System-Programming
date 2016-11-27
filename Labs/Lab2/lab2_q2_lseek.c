#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv)
{
        int fd;

        fd=open(argv[1],O_RDONLY);

        size_t sz;
        off_t w;
        off_t currentPos = lseek(fd, (size_t)0, SEEK_CUR);
        w = lseek(fd, (off_t)0, SEEK_END);

        sz=(size_t) w;

        close(fd);
        printf("%zu",w);
        return 0;
}

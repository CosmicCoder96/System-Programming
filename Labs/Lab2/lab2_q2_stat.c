#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
struct stat st;
size_t getFilesize(char* filename) {
    
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;
}
int main(int argc,char **argv)
{
	printf("%zu",getFilesize(argv[1]));
	return 0;
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int x = 0, y = 0, result;

	printf("%s %s %s = ",argv[1],argv[3],argv[2]);
	x = atoi(argv[1]);
	y = atoi(argv[2]);

	if(strcmp(argv[3],"+") == 0)
		result = x+y;
	else
		result = x-y;
	return result;
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char a[100], b[10], opr[10];
	int result, pid;	 
		printf("N1: ");
		gets(a);
		printf("N2: ");
		gets(b);
		printf("(+/-): ");
		gets(opr); 
		pid = fork();
		if(pid == 0){
			if(execl("./s.out", "s.out", a, b, opr, (char*)NULL) == -1)
				perror("Server failed to start");
		}
		
		else if(pid > 0){
			waitpid(pid, &result, 0);
			printf("%d\n", WEXITSTATUS(result));
		}
	
	return 0;
}

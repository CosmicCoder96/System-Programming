#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define ARGS "a:b:t:"
#define MAX 100

struct matrix_structure 
{
	int  A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
	int r1,c1,r2,c2;
};


int main(int argc, char ** argv)
{

	int n,c,i,j,g3;
	FILE *fd1,*fd2;
	struct matrix_structure matrix;
	char * g1, *g2,*file1, *file2;
	
	fd1 = fopen("filea.txt","r");
	//fd2 = fopen("fileb.txt","r");
	fscanf(fd1, "%d", &matrix.r1);
		printf("%d\n",matrix.r1);
	fscanf(fd1," %s%s%d",g1,g2,&g3);
	fscanf(fd1,"%d",&g3);
	printf("%d\n",g3);

	

}
	


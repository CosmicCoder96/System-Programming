#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define ARGS "a:b:t:"
#define MAX 100

struct matrix_structure 
{
	int A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
	int r1,c1,r2,c2;
	int x;
}matrix;

void * multiply(void * a);
int main(int argc, char ** argv)
{

	int n,c,i,j,g3,groups[MAX];
	pthread_t threads[10];
	FILE *fp1,*fp2;
	//struct matrix_structure matrix;
	char g1[10], g2[10],*file1, *file2;
	while((c=getopt(argc,argv,ARGS))!=EOF)
	{
		switch(c)
		{
			case 'a':
				file1 = optarg;
				break;
			case 'b':
				file2 = optarg;
				break;
			case 't':
				n = atoi(optarg);
				break;

			default:
				fprintf(stderr,"\nIncorrect usage: Use %s\n",ARGS);
		}
	}
	
	fp1 = fopen(file1, "r");
	fp2 = fopen(file2,"r");

	fscanf(fp1, "%d%d",&matrix.r1,&matrix.c1);
	fscanf(fp2, "%d%d",&matrix.r2,&matrix.c2);

	for(i=0;i<matrix.r1;i++)
	{
		fscanf(fp1,"%s %s %d",g1,g2,&g3);
		for(j=0;j<matrix.c1;j++)
		{
			fscanf(fp1," %d",&matrix.A[i][j]);
		//	printf("\n%d\n ",matrix.A[i][j]);
		}
	}
	for(i=0;i<matrix.r2;i++)
	{
		fscanf(fp2,"%s %s %d",g1,g2,&g3);
		for(j=0;j<matrix.c2;j++)
		{
			fscanf(fp2,"%d",&matrix.B[i][j]);
		}
	}
//	int nThreadGroups = matrix.r1/4;
	matrix.x = 1;
	int counter =-1;
	//if(nThreadGroups!=0)
	//	printf("fuck you");
	for(i=0;i<n;i++)
	{
		if(matrix.x%i==0)
			counter++;
		pthread_create(&threads[i],NULL,multiply,(void *)&counter);
		
	}
	for(i=0;i<n;i++)
	{
	pthread_join(threads[i],NULL);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	multiply(&matrix);



}

void * multiply(void *a)
{
	//struct matrix_structure *matrix = (struct matrix_structure *) a;
	int * begin = (int*) a;
	int i, j;
	printf("%d",*begin);
	for(i=((*begin)-1)*matrix.x;i<matrix.x;i++)
	{
		for(j=0;j<matrix.c1;j++)
		{
			matrix.C[i][j]=matrix.A[i][j]*matrix.B[j][i];
			printf("%d ", matrix.C[i][j]);
		}
		printf("\n");
	}
}












			
			


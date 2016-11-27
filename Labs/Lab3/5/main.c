#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct arg_structure{
	float a[100][100];
	float b[100][100];
	float c[100][100];
	int row1,col1,row2,col2;
	int rbt;
	int i;
};
int rem;
int last;
void * matrix_mul(void * d){
	struct arg_structure*  args = (struct arg_structure *) d;
	int id = args->i;
	//printf("\nid = %d\n",id);
	int i,j,k;
	float sum = 0;
	int lim;
	if(rem != 0 ) { 
		lim = (id+1)*(args->rbt) + 1;	
		rem--;
		for (i = last; i < lim && i < args->row1; i++) {
	      		for (j = 0; j < args->col2; j++) {
	        		for (k = 0; k < args->row2; k++) {
	         		 sum = sum + args->a[i][k]* args->b[k][j];
	        		}
	 
	       		 args->c[i][j] = sum;
	       		 sum = 0;
	     		 }
	   	 }
		last = i - 1;
	
	
	}
	else {
		lim = (id+1)*(args->rbt);
	
	for (i = last; i <= lim && i < args->row1; i++) {
	      for (j = 0; j < args->col2; j++) {
	        for (k = 0; k < args->row2; k++) {
	          sum = sum + args->a[i][k]* args->b[k][j];
	        }
	 
	        args->c[i][j] = sum;
	        sum = 0;
	      }
	    }
		last = i;
	}
	
}

void Display (float z[][100],int row,int cols){
	int i ,j;
	for(i=0;i<row;i++){
		for(j=0;j<cols;j++){
			printf("%f\t",z[i][j]);
		}
		printf("\n");
	}
}

int main(int argc,char * argv[]){
	int i;
	int j;
	int k;
	
	struct arg_structure args;
	FILE *fp1,*fp2;
	char str[3],str1[3];
	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"r");
		fscanf(fp1,"%d%d",&args.row1,&args.col1);
		fscanf(fp2,"%d%d",&args.row2,&args.col2);

		for(i = 0;i<args.row1;i++){
			fscanf(fp1,"%s %s %d",str,str1,&k);
			for(j=0;j<args.col1;j++){
				fscanf(fp1,"%f",&args.a[i][j]);
				
			}
		}

		for(i = 0;i<args.row2;i++){
			fscanf(fp2,"%s %s %d",str,str1,&k);
			for(j=0;j<args.col2;j++){
				fscanf(fp2,"%f",&args.b[i][j]);
				
			}
		}

	fclose(fp1);
	fclose(fp2);
	
	//Display(a,row1,col1);
	//Display(b,row2,col2);
	

	pthread_t t_id[10];
	int nofthread = atoi(argv[3]);
	args.rbt = args.row1/nofthread;
	//printf("%d",args.rbt);
	int pid[10];
	int rem = args.row1 % nofthread;
	for(i=0;i<nofthread;i++){
		args.i = i;
		pthread_create(&t_id[i],NULL,matrix_mul,(void*)&args);
		pthread_join(t_id[i],NULL);
	}

	for(i=0;i<nofthread;i++){
	//pthread_join(t_id[i],NULL);
	}	
	//pthread_exit(NULL);
	//Display(args.c,args.row1,args.col2);
	fp1 = fopen("filec.txt","w");
	fprintf(fp1,"%d %d",args.row1,args.col2);	
	printf("%d %d",args.row1,args.col2);
	for(i=0;i<args.row1;i++){
		fprintf(fp1,"\n# ROW %d\n",i);
		printf("\n# ROW %d\n",i);
		for(j=0;j<args.col2;j++){
			fprintf(fp1,"%f\n",args.c[i][j]);
			printf("%f\n",args.c[i][j]);
		}
		//printf(fp1,"\n");
	}
	fclose(fp1);
	return 0;
}

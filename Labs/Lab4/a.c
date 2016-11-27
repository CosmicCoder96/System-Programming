#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int fun(double *bt, int a)
{
	int i;
	for(i = 0; i < a; i++){
		if(bt[i] > 0)
			return 0;
	}
	return 1;
}

int main(int argc, char **argv){
	FILE *fp;
	fp = fopen (argv[1], "r");
	char pid[1000][1000];
	int arr[1000], pr[1000], flag[1000];
	double bt[1000], wt[1000], tat[1000], et[1000], tsw[1000]; 
	int a;
	int arrival = 0;
	for(a = 0; !feof (fp); a++){
		fscanf(fp, "%s %d %lf %lf %lf %d", pid[a], &arr[a], &bt[a], &et[a], &tsw[a], &pr[a]);
		arr[a] += arrival;
		arrival = arr[a];
		flag[a] = 0;
		wt[a] = 0;
		tat[a] = bt[a];
	}
	char PID[1000][1000];
	a--;
	double avg_tat = 0, avg_wt = 0;
	double time = 0;
	int i, j;
	double tbst = 0.0;
	for(i = 0; i < a; i++){
		tbst += bt[i];
	}
	i = 0;
	while(1){
		int l = fun(bt, a);
		if(l){
			break;
		}
		double min_t = 1000000.00;
		int min_j = 0;
		for(i = 0; i < a; i++){
		if(arr[i] <= time && bt[i] > 0 && bt[i] < min_t){
				min_t = bt[i];
				min_j = i;
			}
		}
		//bt[min_j] -= 0.1;
		for(i = 0; i < a;i++){
			if(i != min_j && (arr[i] <= time && bt[i] > 0.0f)){
				//printf("I is %d min_j is :%d nndn bt[i] =%lf and wt[i] is = %lf\n",i,min_j,bt[i],wt[i]);
				wt[i] += 1;
			}	
		}
		bt[min_j] -= 1;
		time += 1;
	}
	for(i = 0; i < a; i++){
		tat[i] += wt[i];
		avg_tat += tat[i];
		avg_wt += wt[i];
	}
	
	avg_wt = (double) avg_wt / a;
	avg_tat = (double) avg_tat / a;
	double x;
	double sum = 0;
	for (i = 0; i < a; i++){
		x = tat[i] - avg_tat;
		x = x * x;
		sum += x;
	}
	double s = sqrt(sum);
	
	printf("<%s> \n\n",argv[1]);
	printf("Process Name\tTurn Around Time\tWaiting time\n");
	for(i = 0; i < a; i++){
		printf("%s\t\t%.2lf\t\t\t%.2lf\n", pid[i], tat[i], wt[i]);
	}
	
	printf("\n\nAvg time to complete process : %.2lf\nStandard Deviation of complete time :%.2lf\n", avg_tat, s);

	fclose(fp);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int main()
{
	int priority[MAX], at[MAX],n=0,i;
	double bt[MAX], et[MAX],io[MAX],wp[MAX],wt[MAX],tat[MAX],avtat,time=0,minTime = 1000000, tbst=0;
	int minIndex=0;
	char name[MAX][MAX];
	FILE* fp;
	fp = fopen("1.txt", "r");
	while(getc(fp)!='x')
	{
		fscanf(fp,"%s %d %lf %lf %lf %d",name[n],&at[n],&et[n],&io[n],&wp[n],&priority[n]);
		bt[n] = et[n];
		tbst+=bt[n];
		wt[n] = 0;
		tat[n] = bt[n];
		n++;
	}
	n--;
	for(i=1;i<n;i++)
	{
		at[i] = at[i-1]+at[i];
	}
//	wt[0] = 0;
	while(tbst--)
	{
//		int l = check(tbst);
//		if(l)
//			break;
		minTime = 1000000;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]>0&& bt[i]<minTime)
			{
				minTime = bt[i];
				minIndex = i;
			}
		}
		for(i=0;i<n;i++)
		{
			if(i!=minIndex && (at[i] <= time && bt[i]> 0))
				wt[i] += 1;
		}
		bt[minIndex] -=1;
		time++;
	}

	for(i=0;i<n;i++)
	{
		tat[i] +=wt[i];
	}
	printf("\nProcess name\tTurn around Time\tWaiting time\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%lf\t\t%lf\n",name[i],tat[i],wt[i]);
	}
	for(i = 0;i < n;i++)
	{
		avtat += tat[i];	
	}
	avtat = avtat / n;
	printf("Average time for process completion was %f \n",avtat);
	float stdev=0;
	for(i = 0;i < n;i++)
	{
	    stdev += pow((avtat-tat[i]),2);
	}
	stdev = stdev/n;
	stdev = sqrt(stdev);
	printf("Standard deviation for process completion was %f \n",stdev);
	return 0;
}	


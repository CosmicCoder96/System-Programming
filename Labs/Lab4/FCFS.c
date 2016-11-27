#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int main()
{
	int priority[MAX], n=0,i;
	float at[MAX], et[MAX],io[MAX],wp[MAX],wt[MAX],tat[MAX],avtat,time;
	char name[MAX][MAX];
	FILE* fp;
	fp = fopen("1.txt", "r");
	while(getc(fp)!='x')
	{
		fscanf(fp,"%s %f %f %f %f %d",name[n],&at[n],&et[n],&io[n],&wp[n],&priority[n]);
		n++;
	}
	n--;
	for(i=1;i<n;i++)
	{
		at[i] = at[i-1]+at[i];
	}
	wt[0] = 0;
	for(i=0;i<n;i++)
	{
		if(time<at[i])
			time = at[i];
		time = time + et[i];
			tat[i] = time - at[i];
		wt[i] = tat[i] - et[i];
	}
	printf("\nProcess name\tTurn around Time\tWaiting time\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%f\t\t%f\n",name[i],tat[i],wt[i]);
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






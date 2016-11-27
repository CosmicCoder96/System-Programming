#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<math.h>
int main()
{
	printf("Name of the file to be read : ");
	char name[100];
	scanf("%s",name);
	FILE* file = fopen (name, "r");
	int n = 0;
	char ch[100][100];
	int at[100],priority[100];
	double et[100],intio[100],iotime[100];
	int i,j;
	while(getc(file)!='x')
	{
		fscanf(file,"%s %d %lf %lf %lf %d",ch[n],&at[n],&et[n],&intio[n],&iotime[n],&priority[n]);
		n++;
	}
	n--;
	//printf("%d\n\n", n);
	double tat[100],wt[100];
	double avtat = 0;
	double time = 0;
	wt[0] = 0;
	for(i = 1;i < n;i++)
	{
		at[i] += at[i-1];
	}
	for(i = 0;i < n;i++)
	{
		//time = time + et[i];		
		if(time < at[i])
		{
			time = at[i];

		}
		time = time + et[i];
		tat[i] = time - at[i];		
		wt[i] = tat[i] - et[i];

	}
	for(i = 0;i < n;i++)
	{
		avtat += tat[i];	
	}
	avtat = avtat / n;
	printf("process name\tturn around time\ttotal wait time\n");
	for(i = 0;i < n;i++)
	{
		printf("P%d:\t\t%lf\t\t%lf\n",i+1,tat[i],wt[i]);

	}
	printf("Average time for process completion was %lf \n",avtat);
	double stdev=0;
	for(i = 0;i < n;i++)
	{
	    stdev += pow((avtat-tat[i]),2);
	}
	stdev = stdev/n;
	stdev = sqrt(stdev);
	printf("Standard deviation for process completion was %lf \n",stdev);
	return 0;
}

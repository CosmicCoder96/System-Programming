#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<math.h>
void enqueue(int PQ[][100],int cnt,int a,int b)
{
	PQ[0][cnt] = a;
	PQ[1][cnt] = b;
}

void dequeue(int PQ[][100],int cnt)
{
	int i;
	for(i = 0;i < cnt-1;i++) {
		PQ[0][i] = PQ[0][i+1];
		PQ[1][i] = PQ[1][i+1];
	}
}

void Sort(int PQ[][100],int cnt)
{
	int i,j,tmp;
	for(i = 0;i < cnt;i++) {
		for(j = 0;j < cnt-1;j++) {
			if(PQ[1][j] > PQ[1][j+1]) {
				tmp = PQ[1][j];
				PQ[1][j] = PQ[1][j+1];
				PQ[1][j+1] = tmp;
				tmp = PQ[0][j];
				PQ[0][j] = PQ[0][j+1];
				PQ[0][j+1] = tmp;
			}

		}
	}
}
int main()
{
	printf("Name of the file to be read : ");
	char name[100];
	scanf("%s",name);
	FILE* file = fopen (name, "r");
	int n=0;
	char ch[100];
	int at[100],priority[100];
	double et[100],intio[100],proio[100];
	fscanf(file,"%s",ch);
	int i,j;
	while(ch[0]!='x')
	{
		fscanf(file,"%d %lf %lf %lf %d",&at[n],&et[n],&intio[n],&proio[n],&priority[n]);
		fscanf(file,"%s",ch);
		n++;
	}
	for(i=1;i<n;i++)
	{
		at[i]+=at[i-1];
	}
	int tat[100];
	int wt[100];
	double avtat=0;
	int time = 0;
	for(i=0;i<100;i++)
		wt[i]=0;

	int PQ[2][100];
	int chk=0;
	int cnt=0;
	at[n]=INT_MAX;
	while(cnt != 0||time ==0)
	{
		if(at[chk] == time && chk < n)
		{
			while(at[chk]==time && chk < n)
			{
				enqueue(PQ,cnt,chk,et[chk]);
				chk++;cnt++;
			}
			Sort(PQ,cnt);
		}

		while(time < at[chk] && cnt!=0)
		{
			for(i=1;i<cnt;i++)
			{
				wt[PQ[0][i]]++;
			}
			PQ[1][0]--;
			time++;
			if(PQ[1][0]==0)
			{
				dequeue(PQ,cnt);
				cnt--;
			}
		}
        if(chk<n && cnt==0)
        {
            time = at[chk];
            while(at[chk]==time && chk < n)
			{
				enqueue(PQ,cnt,chk,et[chk]);
				chk++;cnt++;
			}
			Sort(PQ,cnt);

        }

	}
	for(i = 0;i < n;i++)
	{
		tat[i] = wt[i] + et[i];
		avtat += tat[i];
	}
    	avtat = avtat/n;
	printf("process name\tturn around time\ttotal wait time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t\t%d\t\t\t%d\n",i+1,tat[i],wt[i]);

	}
	printf("Average time for process completion was %lf \n",avtat);
	double stdev=0;
	for(i=0;i<n;i++)
	{
	    stdev += pow((avtat-tat[i]),2);
	}
	stdev = stdev/n;
	stdev = sqrt(stdev);
	printf("Standard deviation for process completion was %lf \n",stdev);
	return 0;
}

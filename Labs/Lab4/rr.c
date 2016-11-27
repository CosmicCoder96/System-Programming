#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<math.h>
void circleQ(int PQ[][100],int cnt)
{
	int a,b;
	int i;
	a=PQ[0][0];
	b=PQ[1][0];
	for(i=0;i<cnt-1;i++)
	{
		PQ[0][i] = PQ[0][i+1];
		PQ[1][i]=PQ[1][i+1];
	}
	PQ[0][cnt-1]=a;
	PQ[1][cnt-1]=b;

}
void enqueue(int PQ[][100],int cnt,int a,int b)
{
	PQ[0][cnt]=a;
	PQ[1][cnt]=b;
}
void dequeue(int PQ[][100],int cnt)
{
	int i;
	for(i=0;i<cnt-1;i++)
	{
		PQ[0][i]=PQ[0][i+1];
		PQ[1][i]=PQ[1][i+1];
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
	int i,j,cnt=0,chk=0;
	while(ch[0]!='x')
	{
		fscanf(file,"%d %lf %lf %lf %d",&at[n],&et[n],&intio[n],&proio[n],&priority[n]);
		fscanf(file,"%s",ch);
		n++;
	}
	for(i = 1;i < n;i++)
	{
		at[i] += at[i-1];
	}
	int tat[100],wt[100];
	for(i = 0;i < 100;i++)
		wt[i] = 0;
	int k = 0;
	int PQ[2][100];
	double avtat = 0;
	at[n] = INT_MAX;
	int time = 0;
	while(cnt != 0||time == 0) {
		if(at[chk] == time && chk < n) {
			while(at[chk] == time && chk < n) {
				enqueue(PQ,cnt,chk,et[chk]);
				chk++;
				cnt++;
			}
		}

		while(time < at[chk] && cnt!=0 ) {
			for(i = 1;i < cnt;i++) {
				wt[PQ[0][i]]++;
			}
			PQ[1][0]--;
			time++;
			k++;
			if(PQ[1][0]==0) {
				k=0;
				dequeue(PQ,cnt);
				cnt--;
				if(chk<n && cnt==0) {
                    			time = at[chk];
                    			while(at[chk]==time&& chk < n) {
                        			enqueue(PQ,cnt,chk,et[chk]);
                        			chk++;
                        			cnt++;
                    			}
                		}
				continue;
			}
			if(k == 3) {
				k = 0;
				circleQ(PQ,cnt);
			}
		}


	}
	
	for(i = 0;i < n;i++)
	{
		tat[i] = wt[i] + et[i];
		avtat += tat[i];
	}
    	avtat = avtat/n;
	printf("process name\tturn around time\ttotal wait time\n");
	for(i = 0;i < n;i++) {
		printf("P%d\t\t%d\t\t\t%d\n",i+1,tat[i],wt[i]);
	}
	printf("Average time for process completion was %lf \n",avtat);
	double stdev=0;
	for(i=0;i<n;i++) {
	    stdev += pow((avtat-tat[i]),2);
	}
	stdev = stdev/n;
	stdev = sqrt(stdev);
	printf("Standard deviation for process completion was %lf \n",stdev);
	return 0;
}

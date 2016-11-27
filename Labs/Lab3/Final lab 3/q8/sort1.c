#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	char str[1000];
	int a[1005],n=0,i,j,d;
	FILE *fd=fopen(argv[1],"r+");
	if(fd==NULL)
	{
		printf("Error in opening file\n");
	}
	else
	{
		while(!feof(fd))
		{
			fscanf(fd, "%d ", &d);
			a[n++]=d;
		}
	}
	fclose(fd);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				d=a[j];
				a[j]=a[j+1];
				a[j+1]=d;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}				
	return 0;
}

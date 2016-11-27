#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t mutex;
pthread_t t1,t2,t3;
int b0[1002]={0};
int b1[600]={0};
int n;
void *write1(void *p)
{
	int i;
	pthread_mutex_lock(&mutex);
	for(i=0;i<1000;i++)
		b0[i]=i;
	b0[1000]=0;
	pthread_mutex_unlock(&mutex);

}
void *write2(void *p)
{
	int j=0,r,i;
//	while(b0[0]==0);
	pthread_mutex_lock(&mutex);
	for(i=0;i<1000;i++)
	{
		r=b0[i]%2;
		if(r!=0)
		{
			b1[j++]=b0[i];
		}
	}
	n=j;
	b1[j++]=0;

	pthread_mutex_unlock(&mutex);
}
void *rea(void *p)
{
	int i,r;
//	while(b0[0]==0||b1[0]==0);
	pthread_mutex_lock(&mutex);
	for(i=0;i<n;i++)
	{
		r=b1[i]%3;
		if(r!=0)
			printf("%d\n",b1[i]);
	}
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,write1,NULL);

	pthread_create(&t2,NULL,write2,NULL);

	pthread_create(&t3,NULL,rea,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

}

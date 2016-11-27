#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int read_count=0;
sem_t r,w;
//sem_init(&r,0,1);
//sem_init(&w,0,1);

void *reader(void *p)
{
	int t=(int)p;
	sem_wait(&r);
	read_count++;
	if(read_count==1)
		sem_wait(&w);
	sem_post(&r);
	printf("Reading %d and the count of readers %d\n",t,read_count);
	sem_wait(&r);
	read_count--;
	if(read_count==0)
		sem_post(&w);
	sem_post(&r);



}
void *writer(void *p)
{
	int t=(int *)p;
	sem_wait(&w);
	printf("Writing %d\n",t);
	sem_post(&w);
}
int main()
{
	pthread_t tr[10],tw[10];
//	sem_t r,w;
	sem_init(&r,0,1);
	sem_init(&w,0,1);
	int i,n1,n2;
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1;i++)
		pthread_create(&tr[i],NULL,reader,(void*)i);
	for(i=0;i<n2;i++)
		pthread_create(&tw[i],NULL,writer,(void*)i);
	for(i=0;i<n1;i++)
		pthread_join(tr[i],NULL);
	for(i=0;i<n2;i++)
		pthread_join(tw[i],NULL);
}

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int counter =0;
void* increment ();
int main()
{
	pthread_t threads[10];
	int iret[10],i;
	for(i =0;i<10;i++)
	{
		pthread_create(&threads[i],NULL,increment,NULL);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(threads[i],NULL);
	}
	printf("Final value is : %d \n",counter);

}

void * increment()
{
	counter++;
}

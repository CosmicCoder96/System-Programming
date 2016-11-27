#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t mutex1;
int counter =0;
void* increment ();
void* decrement ();
int main()
{
	pthread_t threads[10];
	int iret[10],i;
	for(i =0;i<10;i++)
	{
		if(i<5)
			pthread_create(&threads[i],NULL,increment,NULL);
		else
			pthread_create(&threads[i],NULL,decrement,NULL);

	}
	for(i=9;i>0;i--)
	{
		printf("%d\n", counter);
		pthread_join(threads[i],NULL);
	}
	printf("Final value is : %d \n",counter);

}
// this experimental piece of code , indicates that join does infacr halt the execution of the main function,
// unless the thread is finished, it won't even move on to the next join statement.'
//The use of mutex here is just to show, the syntax of using a mutex in the pthread library
void * increment()
{
	pthread_mutex_lock(&mutex1);
	counter++;
	pthread_mutex_unlock(&mutex1);
	while(1);
	
}
void * decrement(void * i)
{
	counter--;
	while(1);
}


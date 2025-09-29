#include<stdio.h>
#include<pthread.h>


#define no_of_threads 4
#define no_of_loop 100000

int counter=0;
pthread_mutex_t lock;

void *increment(void * arg)
{
	for(int i=0;i<no_of_loop;i++)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main()
{
	pthread_t threads[no_of_threads];

	
	pthread_mutex_init(&lock,NULL);
	

	for(int j=0;j<no_of_threads;j++)
	{
		pthread_create(&threads[j],NULL,increment,NULL);
	}
	for(int k=0;k<no_of_threads;k++)
	{
		pthread_join(threads[k],NULL);
	}


	printf("Final counter value \t:%d",counter);

	pthread_mutex_destroy(&lock);
	return 0;
}



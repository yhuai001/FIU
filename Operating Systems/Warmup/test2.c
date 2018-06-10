#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define THREADS 5             /*define threads as 5*/

int SharedVarivable = 0;      	

void *SimpleThread(void *threadid) 
{
	long tid;
	tid = (long)threadid;
    	int val;

	val = SharedVarivable;
    	printf("thread #%ld sees value %d\n", tid, val); 
	SharedVarivable = val + 1;
    	pthread_exit(NULL);
}
/* The part was given in guidance */

int main(int argc, char *argv[])
{
	pthread_t threads[THREADS]; 	/* Set the variable pthread_t to */
 	long t; 			/* Define the counter t */
	for(t=0; t<THREADS; t++) 	/* Use t to count threads number */
		{
		printf("Creating thread %ld\n", t); /*Show which thread is being created*/
		pthread_create(&threads[t], NULL, SimpleThread, (void *)t); 
		/*Create threads and let them run the SimpleThread*/
		}
		
   pthread_exit(NULL); /* exit main() */
}




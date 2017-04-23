#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

#define HandleError(s,msg) \
		do { perror(msg); exit(EXIT_FAILURE); }while(0);

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *thread_routine(void *arg)
{
	int loc,j;
	for(j = 0; j < 100000; j++){
		pthread_mutex_lock(&mtx);
		loc = glob;
		loc ++;
		glob = loc;
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int s;
	
	s = pthread_create(&t1, NULL, thread_routine, NULL);
	if(s != 0){
		HandleError(s, "pthread create t1 ...\n ");
	}

	s = pthread_create(&t2, NULL, thread_routine, NULL);
	if(s != 0){
		HandleError(s,"thread create t2 ... \n");
	}

	s = pthread_join(t1, NULL);
	if(s != 0){
		HandleError(s, "thread exit t1 ... \n");
	}

	s = pthread_join(t2, NULL);
	if(s != 0){
		HandleError(s, "thread exit t2 ... \n");
	}

	printf("glob = %d \n",glob);
	exit(EXIT_SUCCESS);
}


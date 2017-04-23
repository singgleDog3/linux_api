#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

#define HandleError(s, msg) \
		do { printf( "Error NO: %d  MSG:%s",s,msg);}while(0);

static int glob = 0;

static void *thread_routine(void *arg)
{
	int loc, j;
	for(j = 0; j < 1000000; j++){
		loc = glob;
		loc++;
		glob = loc;
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int s;

	s = pthread_create(&t1, NULL, thread_routine, NULL);
	if(s != 0){
		HandleError(s, "pthread create ...\n");	
	}

	s = pthread_create(&t2, NULL, thread_routine, NULL);
	if(s != 0){
		HandleError(s, "pthread create ... \n");
	}

	s = pthread_join(t1, NULL);
	if(s != 0){
		HandleError(s, "pthread join ... \n");
	}
	s = pthread_join(t2, NULL);
	if(s != 0){
		HandleError(s, "pthread join t2 ...\n");
	}

	printf("golb = %d \n",glob);
	exit(EXIT_SUCCESS);
}

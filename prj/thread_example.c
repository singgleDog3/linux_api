#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "subFunc.h"

// int thread_create(pthread_t *thread, const pthread_attr_t *attr, void* (*entry)(void *), void *arg);
//
// pthread_t pthread_self(void);
// 
// int pthread_equal(pthread_t t1, pthread_t t2);
// 
// void pthread_exit(void *retval);
//
// int pthread_join(pthread_t thread, void **retval);
// 
//  int pthread_detach(pthread_t thread);
int main(void)
{
	pthread_t ID_1;
	
	if(pthread_create(&ID_1, NULL, thread_routine, NULL) != 0){
		fprintf(stdout, "Creat thread 1 error");
		exit(-1);
	}

	pthread_join(ID_1, NULL );
	fprintf(stdout, "thread 1 termination .... \n");

	pthread_t ID_2;
	uint_32  value = 112;


	if(pthread_create(&ID_2, NULL, thread_routine_2, &value ) != 0){
		fprintf(stdout, "Create Thread 2 Error .... \n");
		exit(-1);	
	}	
	
	fprintf(stdout, "Main thread sleep 3s .... \n");
	sleep(3);

	fprintf(stdout, "main func ...\n");
	
	pthread_exit(NULL);
	fprintf(stdout, "main func never be here .... \n ");
	
	return 0;
}



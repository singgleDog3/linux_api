#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "subfunc.h"

int main(int argc, char *argv[])
{
	pthread_t thr;
	pthread_attr_t attr;
	pthread_attr_t *attr_p;
	int s;

	attr_p = NULL;

	/*if argc > 1  set stack size and ste the new thread is detached*/
	if(argc > 1){
		int stack_size;
		void *sp;

		attr_p = &attr;
		s = pthread_attr_init(&attr);
		if(s != 0){
			HandleError(s, "thread_attr_init ... \n");
		}

		s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED  );
		if(s != 0){
			HandleError(s, "pthread_attr_setdetachState...\n");	
		}
		stack_size = strtoul(argv[1], NULL, 0);
		s = posix_memalign(&sp, sysconf(_SC_PAGESIZE), stack_size);
		if(s != 0){
			HandleError(s, "posix_memalign ... \n");
		}

	}
	
	s = pthread_create(&thr, attr_p, &thread_start, NULL);
	if(s != 0){
		HandleError(s, " pthread_create ...\n");
	}

	if(attr_p != NULL){
		s = pthread_attr_destroy(attr_p);
		if(s != 0){
			HandleError(s, "pthread_attr_destroy ...\n");
		}
	}
	pause();

	
	


}
// int pthread_attr_init(pthread_attr_t *attr);
// int pthread_attr_destroy(pthread_attr_t *attr);
// int pthread_getattr_up(pthread_t thread, pthread_attr_t *attr); // int pthread_setdetachstate(pthread_attr_t *attr, int detachstate); // int pthread_getdetachstate(pthread_attr_t *attr, int *detachstate); // int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize); // int pthread_attr_getstack(pthread_attr_t *attr, void **stackaddr, size_t *stacksize);
//

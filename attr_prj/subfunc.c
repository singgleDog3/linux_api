#include "subfunc.h"

void *thread_start(void *arg)
{
	int s;
	pthread_attr_t gattr;

	s = pthread_getattr_np(pthread_self(), &gattr);
	if(s != 0){
	 HandleError(s, "pthread_getattr_np ...\n");
	}

	printf("thread attributes: \n");
	display_thread_attr(&gattr, "\t");
	exit(EXIT_SUCCESS);

}

void display_thread_attr(pthread_attr_t *attr, char *prefix)
{
	int s,i;
	size_t v;
	void *stkAddr;
	struct sched_param sp;

	s = pthread_attr_getdetachstate(attr, &i);
	if(s != 0){
		HandleError(s, "thread_attr_getdetachatate ... \n");
	}

	s = pthread_attr_getstack(attr, &stkAddr, &v);
	if (s != 0){
	HandleError(s,"pthread_attr_getstack ...\n");
	}

	printf("%s Statck address   = %p\n", prefix, stkAddr);
	printf("%s Stack size       = 0x%x bytes \n", prefix, (unsigned)v);

}



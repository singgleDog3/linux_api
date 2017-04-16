#include "subFunc.h"

void* thread_routine(void *param)
{
	fprintf(stdout, "This thread_routine 1..... \n");
	sleep(1);
	return 0;
}


void* thread_routine_2(void *value)
{
	uint_32 value_1 =  *(uint_32*) (value); 
	fprintf(stdout, "Thread 2 value :%d ....\n",value_1);	
	return 0;
}

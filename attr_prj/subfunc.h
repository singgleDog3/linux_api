#ifndef _subfunc_h
#define _subfunc_h

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define HandleError(s,msg) \
		do { printf("ErrorNo: %d MSG: %s ...\n", s, msg); }while(0);

#define EXIT_SUCCESS 0

void *thread_start(void *arg);

void display_thread_attr();

#endif

#ifndef _thread_h
#define _thread_h

#include <pthread.h>
#include <stdio.h>

typedef unsigned int uint_32;
typedef unsigned short uint_16;
typedef unsigned char uint_8;

void* thread_routine(void *param);
void* thread_routine_2(void* value);

#endif

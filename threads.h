#ifndef THREADS_H
#define THREADS_H

//////////////////////////////////
//
// File:        threads.h
//
// Authors:     Michael Tuchler
//              Abhishek Kosuri
// Included in: reader.c, munch1.c, munch2.c,
// 		writer.c, queue.c, main.h
// Last Edit:   10/12/2018
//
/////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

// global functions, used by the threads
void* reader();
void* munch1();
void* munch2();
void* writer();

// declaration of a Queue struct
// size: max number of strings in queue
// rear: index of last element
// stats: four Counts in listed order
// 	enq, deq, enqBlock, deqBlock
// strings: pointer to string array
// semaphores
typedef struct{
	int size;
	int rear;
	int stats[4];
	char** strings;
	sem_t mutex;
	sem_t empty;
	sem_t full;
}Queue;

// queue functions
extern Queue * CreateStringQueue(int size);
extern void EnqueueString(Queue *q, char *string);
extern char * DequeueString(Queue *q);
extern void PrintQueueStats(Queue *q);

// safe buffer size
static const int BUFF_SIZE = 1024;

// number of items in the queue
static const int queue_size = 10;
// array of queue pointers
Queue *Q[3];

#endif

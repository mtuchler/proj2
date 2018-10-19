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
// Last Edit:   10/19/2018
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
// buff reading test function
void BuffRead(char *buff);

// declaration of a Queue struct
// size: max number of strings in queue
// rear: index of last element
// stats: four Counts in listed order
// 	enq, deq, enqBlock, deqBlock
// strings: pointer to string array
// dqbuff: the most recently dequeued string
// semaphores
typedef struct{
	int size;
	int rear;
	int stats[4];
	char** strings;
	char *dqbuff;
	sem_t mutex;
	sem_t empty;
	sem_t full;
}Queue;

// queue functions
Queue * CreateStringQueue(int size);
void EnqueueString(Queue *q, char *string);
char * DequeueString(Queue *q);
void PrintQueueStats(Queue *q);

// safe buffer size
static const int BUFF_SIZE = 1024;

// number of items in the queue
static const int queue_size = 1;
// array of queue pointers
Queue *Q[3];

// semaphore that blocks main after it creates threads
sem_t main_block;

// string that is our EOF termination token
// NOW DEFUNCT
//static char * TERM_TOKEN = "\0";

#endif

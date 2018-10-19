///////////////////////////////////
//
// File:	queue.c
//
// Authors:	Michael Tuchler
// 		Abhishek Kosuri
// Header:	threads.h
// Last Edit:	10/19/2018
//
//////////////////////////////////

#include "threads.h"

// allocates the queue structure and initializes it 
// with an array of character pointers
Queue *CreateStringQueue(int size) {
	// malloc queue structure and initialize it
	// with an array of character pointers	
	Queue *q;
       	q = malloc(sizeof(Queue));
	q->strings = malloc(sizeof(char*)*size);
	for (int i = 0; i < size; i++) {
		q->strings[i] = malloc(BUFF_SIZE);
	}
	// malloc of dqbuff
	q->dqbuff = malloc(BUFF_SIZE);
	
	// initialize ints
	q->size = size;
	q->rear = -1;

	// initialize stats
	for (int i = 0; i < 4; i++) {
		q->stats[i] = 0;
	}

	// initialize semaphores
	sem_init(&q->mutex,0,1);
        sem_init(&q->full,0,0);
	sem_init(&q->empty,0, queue_size);
	
        return q;
}

//attempts to add a string to the queue
void EnqueueString(Queue *q, char *string) {
	sem_wait(&q->empty);
	sem_wait(&q->mutex);
	// -- critical section --
	
	// if it was blocked
	// add string to the end of the queue
	q->rear++;
	if (string != NULL) {
		strcpy(q->strings[q->rear], string);
		// no increment for EOF token
		q->stats[0]++;
	}
	else {
		q->strings[q->rear] = NULL;
	}

	// -- critical section ends --
	sem_post(&q->mutex);
	sem_post(&q->full);
}

//attempts to remove a string from the queue
char * DequeueString(Queue *q) {
	sem_wait(&q->full);
	sem_wait(&q->mutex);
	// -- critical section --
	
	// this stores the pointer for when we swap stuff
	char *q_swap = q->strings[0];

	// if the dequeued element is NULL, you're done
	if (q->strings[0] == NULL) {
		return NULL;
	}
	// copy the string to the buffer so it doesn't get lost
	strcpy(q->dqbuff, q->strings[0]);

	// shift all the strings forward
	for(int i = 0; i < q->rear; i++){
		q->strings[i] = q->strings[i+1];
	}
	q->strings[q->rear] = q_swap;
	q->rear--;

	// dequeueCount
	q->stats[1]++;

	// -- critical section ends --
	sem_post(&q->mutex);
	sem_post(&q->empty);

	return q->dqbuff;
}

//prints statistics for the queue
void PrintQueueStats(Queue *q){
	printf("enqueueCount: %d\n",q->stats[0]);
	printf("dequeueCount: %d\n",q->stats[1]);
	printf("enqueueBlockCount: %d\n",q->stats[2]);
	printf("dequeueBlockCount: %d\n",q->stats[3]);	
}

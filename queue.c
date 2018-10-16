// queue.c
//
//

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include "threads.h"

//stats to keep track of
int enqueueCount;
int dequeueCount;
int enqueueBlockCount;
int dequeueBlockCount;

//allocates the queue structure and initializes it 
//with an array of character pointers
Queue *CreateStringQueue(int size){
	//initialize semaphores
	sem_t mutex;
	sem_t wait;
	sem_init(&mutex,0,1);
	sem_init(&wait,0,0);

	//malloc queue structure and initialize it
	//with an array of character pointers	
	Queue *q;
       	q = malloc(sizeof(Queue));
	q->strings = malloc(sizeof(char*)*size);
	for (int i = 0; i < size; i++) {
		q->strings[i] = malloc(BUFF_SIZE);
	}
        return q;
//}

//attempts to add a string to the queue
void EnqueueString(Queue *q, char *string){
	sem_post(&mutex);	
	//if queue is full block til space is available
	while(q->rear == q->size - 1){
		enqueueBlockCount++;
		sem_wait(&wait);
	}
	enqueueCount++;
	//places pointer to the string at end of the queue
	q->rear = q->rear+1;

	sem_wait(&mutex);
	sem_post(&wait);
}

//attempts to remove a string from the queue
char * DequeueString(Queue *q){
	sem_post(&mutex);
	while(q->rear == 0){
		dequeueBlockCount++;
		sem_wait(&wait);	
	}
	dequeueCount++;
	
	char* q_front = q->strings[0];
	for(int i = 0; i < q->rear; i++){
		q->strings[i] = q->strings[i+1];
	}
	//remove pointer
	q->rear--;

	sem_wait(&mutex);
	sem_post(&wait);

	return q_front;
}

//prints statistics for the queue
void PrintQueueStats(Queue *q){
	printf("%d\n%d\n%d\n%d\n",enqueueCount,dequeueCount,enqueueBlockCount
			,dequeueBlockCount);	
}
}

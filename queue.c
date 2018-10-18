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

	//malloc queue structure and initialize it
	//with an array of character pointers	
	Queue *q;
       	q = malloc(sizeof(Queue));
	q->strings = malloc(sizeof(char*)*size);

	//initialize semaphores
	sem_init(&(q->mutex),0,1);
        sem_init(&(q->full),0,0);
	sem_init(&(q->empty),0, q_size)
	for (int i = 0; i < size; i++) {
		q->strings[i] = malloc(BUFF_SIZE);
	}
        return q;
//}

//attempts to add a string to the queue
void EnqueueString(Queue *q, char *string){
	sem_wait(&q->empty);
	sem_wait(&q->mutex);
	//if queue is full block til space is available
	while(q->rear == q->size - 1){
		enqueueBlockCount++;
		sem_wait(&q->wait);
	}
	enqueueCount++;
	//places pointer to the string at end of the queue
	q->rear = q->rear+1;

	sem_post(&q->mutex);
	sem_post(&q->full);
}

//attempts to remove a string from the queue
char * DequeueString(Queue *q){
	sem_wait(&q->full);
	sem_wait(&q->mutux);
	while(q->rear == 0){
		dequeueBlockCount++;
		sem_wait(&q->wait);	
	}
	dequeueCount++;
	
	char* q_front = q->strings[0];
	for(int i = 0; i < q->rear; i++){
		q->strings[i] = q->strings[i+1];
	}
	//remove pointer
	q->rear--;

	sem_post(&q->mutex);
	sem_post(&q->empty);

	return q_front;
}

//prints statistics for the queue
void PrintQueueStats(Queue *q){
	if(q->rear == 0 && q->front == 0){
		printf("%d\n%d\n%d\n%d\n",enqueueCount,dequeueCount,
				enqueueBlockCount,dequeueBlockCount);
	}	
}
}

// queue.c
//
//
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//semaphores and initialized semaphores
sem_t mutex;
sem_t wait;
sem_init(mutex,1);
sem_init(wait,0);

//queue structure
typedef struct{
        int size;
        int front;
        int rear;
}Queue;

//stats to keep track of
int enqueueCount;
int dequeueCount;
int enqueueBlockCount;
int dequeueBlockCount;

//allocates the queue structure and initializes it 
//with an array of character pointers
Queue *CreateStringQueue(int size){
	Queue* q = (char*)malloc(sizeof(size));
	q = (char*)malloc(sizeof(size)*10); 
	q->front = 0;
        q->rear = -1;
        return q;
}

//attempts to add a string to the queue
void EnqueueString(Queue *q, char *string){
	sem_post(&mutex);	
	//if queue is full block til space is available
	if(isFull()){
		enqueueBlockCount++;
		sem_wait(&wait);
	}
	enqueueCount++;
	//places pointer to the string at end of the queue
	q->rear = string;

	sem_wait(&mutex);
	sem_post(&wait);
}

//attempts to remove a string from the queue
char * DequeueString(Queue *q){
	sem_post(&mutex);
	if(strlen(q) == 0){
		dequeueBlockCount++;
		sem_wait(&wait);
		
	}
	dequeueCount++;
	sem_wait(&mutex);
	sem_post(&wait);
}

//prints statistics for the queue
void PrintQueueStats(Queue *q){
	
}

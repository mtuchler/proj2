// queue.c
//
//
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int mutex = 1;
int wait = 0;
sem_t mutex;
sem_t wait;

//queue structure
typedef struct{
        int size = 10;
        int front;
        int rear;
}Queue;

Queue *CreateStringQueue(int size){
	Queue* q = (char*)malloc(sizeof(size));
	q->front = 0;
        q->rear = -1;
        return q;

}
void EnqueueString(Queue *q, char *string){
	sem_post(&mutex);	
	//if queue is full block til space is available
	if(isFull()){
		sem_wait(&wait);
	}
	//places pointer to the string at end of the queue
	q->rear = string;
	sem_wait(&mutex);
	sem_post(&wait);
}
char * DequeueString(Queue *q){
	sem_post(&mutex);
	if(!isFull()){
		
	}
	sem_wait(&mutex);
}
void PrintQueueStats(Queue *q){}

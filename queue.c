// queue.c
//
//
typedef struct{
        int size = 10;
        int front;
        int rear;
}Queue;

Queue *CreateStringQueue(int size){
	Queue* q = (Queue*)malloc(sizeof(size));
	q->front = 0;
        q->rear = -1;
        return q;

}
void EnqueueString(Queue *q, char *string){
	if(q
}
char * DequeueString(Queue *q){}
void PrintQueueStats(Queue *q){}

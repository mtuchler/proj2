///////////////////////////////////
//
// File:	main.c
//
// Authors:	Michael Tuchler
// 		Abhishek Kosuri
// Header:	main.h
// Date:	10/12/2018
//
//////////////////////////////////

#include "threads.h"
#include <pthread.h>

// queue maximum sizes
const static int queue_size = 10;
// array of Queue pointers
Queue *Q[3];

int main() {
	// initialize the three queues
	Q[0] = CreateStringQueue(queue_size);
	Q[1] = CreateStringQueue(queue_size);
	Q[2] = CreateStringQueue(queue_size);

	printf("before threads\n");

	// array of the four running thread ids
	pthread_t thread_id[4];
	// thread_create for the four modules
	pthread_create(&thread_id[0], NULL, reader, NULL);
	pthread_create(&thread_id[1], NULL, munch1, NULL);
	pthread_create(&thread_id[2], NULL, munch2, NULL);
	pthread_create(&thread_id[3], NULL, writer, NULL);

	printf("4 threads created\n");

	// join the threads
	for (int i = 0, i < 4, i++) {
		pthread_join(thread_id[i], NULL);
	}

	printf("threads closed\n");
	return 0;
}

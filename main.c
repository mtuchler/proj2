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

int main() {
	// initialize the three queues
	Q[0] = CreateStringQueue(queue_size);
	Q[1] = CreateStringQueue(queue_size);
	Q[2] = CreateStringQueue(queue_size);

	// array of the four running thread ids
	pthread_t thread_id[4];
	// thread_create for the four modules
	pthread_create(&thread_id[0], NULL, reader, NULL);
	pthread_create(&thread_id[1], NULL, munch1, NULL);
	pthread_create(&thread_id[2], NULL, munch2, NULL);
	pthread_create(&thread_id[3], NULL, writer, NULL);

	// semaphore blocks main after threads are created
	// when writer sees EOF, if unblocks main
	sem_init(&main_block,0,0);
	sem_wait(&main_block);	

	// join the threads
	for (int i = 0; i < 4; i++) {
		pthread_join(thread_id[i], NULL);
	}

	// print queue stats
	for (int j = 0; j < 3; j++) {
		fprintf(stderr, "Queue Statistics for Q[%i]:\n", j);
		PrintQueueStats(Q[j]);
	}

	//freeing the memory
	for(int k = 0; k<3; k++){
		free(Q[k]->dqbuff);
		for(int l = 0; l < Q[k]->size; l++){
			free(Q[k]->strings[l]);
		}
		free(Q[k]->strings);
		free(Q[k]);
	}
	return 0;
}

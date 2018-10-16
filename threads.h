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

#ifndef THREADS_H
#define THREADS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// global functions, used by the threads
void* reader();
void* munch1();
void* munch2();
void* writer();

// safe buffer size
const int BUFF_SIZE = 1024;

// declaration of a Queue struct
typedef struct{
        int size;
        int rear;
        char** strings;
}Queue;
// number of items in the queue
const int queue_size = 10;
// array of queue pointers
Queue *Q[3];

#endif

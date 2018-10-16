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

typedef struct{
        int size;
        int front;
        int rear;
}Queue;

#endif

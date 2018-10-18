//////////////////////////////////
//
// File:        munch2.c
//
// Authors:     Michael Tuchler
//              Abhishek Kosuri
// Header:      threads.h
// Last Edit:   10/19/2018
//
//////////////////////////////////

#include "threads.h"
#include <ctype.h>

void* munch2() {

	// buffer for munch2
	char buff[BUFF_SIZE];

	// main while loop
	while(1){
		// grab a string off the queue
		strcpy(buff, DequeueString(Q[1]));
		// check for EOF token
		if(buff == NULL){
			EnqueueString(Q[2], NULL);
			exit(1);
		}
		
		// replace lowercase with uppercase
		for(int i = 0; i < BUFF_SIZE; i++){
			buff[i] = toupper(buff[i]);
		}

		// add to next queue
		EnqueueString(Q[2], buff);
	}

	return NULL;
}

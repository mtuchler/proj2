//////////////////////////////////
//
// File:        writer.c
//
// Authors:     Michael Tuchler
//              Abhishek Kosuri
// Header:      threads.h
// Last Edit:   10/12/2018
//
//////////////////////////////////

#include "threads.h"

void* writer() {

	char buff[BUFF_SIZE];
	char *nullcheck;

	while(1){
		// grab a string off the queue
		nullcheck = DequeueString(Q[2]);

		// EOF handling
		if ( nullcheck == NULL ) {
			sem_post(&main_block);
			return NULL;
		}

		// copy string into buff
		strcpy(buff, nullcheck);

		//write to standard output
		BuffRead(buff);
	}
	return NULL;
}

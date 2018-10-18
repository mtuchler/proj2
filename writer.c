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

	while(1){
		strcpy(buff, DequeueString(Q[2]));
		// EOF handling
		if ( strcmp(buff, TERM_TOKEN) == 0 ) {
//			printf("Wr EOF\n");
			sem_post(&main_block);
			return NULL;
		}
		else {
//			printf("Wr DQ\n");
		}
	
		//write to standard output
		BuffRead(buff);
	}
	return NULL;
}

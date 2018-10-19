//////////////////////////////////
//
// File:        munch1.c
//
// Authors:     Michael Tuchler
//              Abhishek Kosuri
// Header:      threads.h
// Last Edit:   10/12/2018
//
//////////////////////////////////

#include "threads.h"

//this method takes in each line from the file and checks for 
//spaces in each line. It then replaces each space with an asterisk
//symbol.
void* munch1() {

	char buff[BUFF_SIZE];
	char *nullcheck;
	
	// main while loop
	while(1){
		// check for a NULL from queue
		nullcheck = DequeueString(Q[0]);
		printf("M1 DQ\n");

		// EOF handling
		if (nullcheck == NULL) {
			EnqueueString(Q[1], NULL);
			printf("M1 EOF\n");
			return NULL;
		}
		
		// copy dequeued string
		strcpy(buff, nullcheck);
	
		// scan each line
		for(int i = 0; i<BUFF_SIZE; i++){
			if(buff[i] == ' '){
				//replace with * symbols
				buff[i] = '*';		
			}
		}

		EnqueueString(Q[1],buff);
		printf("M1 EQ\n");
	}

	return NULL;
}

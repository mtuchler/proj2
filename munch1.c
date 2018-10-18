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
	
	// main while loop
	while(1){
		// copy a string into the buffer
		strcpy(buff, DequeueString(Q[0]));

		// EOF handling
		// reader passes NULL if EOF is reached
		if (buff == NULL) {
			EnqueueString(Q[1], NULL);
			exit(1);	
		}
	
		//scan each line
		for(int i = 0; i<BUFF_SIZE; i++){
			if(buff[i] == ' '){
				//replace with * symbols
				buff[i] = '*';		
			}
		}

		EnqueueString(Q[1],buff);
	}
	return NULL;
}

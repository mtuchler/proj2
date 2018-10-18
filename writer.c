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
		if(buff == NULL){
			exit(1);
		}
		else{
			//write to standard output

		}
	}
	return NULL;
}

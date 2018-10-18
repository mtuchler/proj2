//////////////////////////////////
//
// File:        munch2.c
//
// Authors:     Michael Tuchler
//              Abhishek Kosuri
// Header:      threads.h
// Last Edit:   10/12/2018
//
//////////////////////////////////

#include "threads.h"
#include <ctype.h>

void* munch2() {
	char buff[BUFF_SIZE];
	while(1){
		strcpy(buff, DequeueString(Q[1]));
		if(buff == NULL){
			buff = EnqueueString(Q[2], NULL)
			exit(1);
		}
		else{
			for(int i = 0; i < BUFF_SIZE; i++){
				buff[i] = toupper(buff[i]);
			}
		}
		EnqueueString(Q[2].buff);
	}
	return NULL;
}

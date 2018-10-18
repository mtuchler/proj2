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
	FILE *file;
	char string[BUFF_SIZE];
	file = fopen("test1.txt", "r");

	if(file == NULL){
		exit(1);
	}

	//scan each line
	while(1){
		for(int i = 0; i<BUFF_SIZE; i++){
			fgets(string, BUFF_SIZE, stdin);		
			//check for spaces
			if(string[i] == ' '){
			//replace with * symbols
				
			}
		}
		if(feof(file)){
			printf("EOF reached\n");
		
		}
	}
	fclose(file);
	printf("munch1\n");
	return NULL;
}

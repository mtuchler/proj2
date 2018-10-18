//////////////////////////////////
//
// File:	reader.c
//
// Authors:	Michael Tuchler
// 		Abhishek Kosuri
// Header:	threads.h
// Last Edit:	10/12/2018
//
//////////////////////////////////

#include "threads.h"
#include <stdio.h>

void* reader() {
	char mybuffer[BUFF_SIZE];
	FILE *fptr;
	fscanf(stdin, "%s", );
	printf("reader\n");
	return NULL;

}

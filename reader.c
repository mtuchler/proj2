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

static int ReadLine(FILE *file, char *buff);

void* reader() {
	// declarations
	char buff[BUFF_SIZE];
	int read_result;

	// file handling
	FILE *file;
	file = fopen("test1.txt", "r");
	if (file == NULL) {
		printf("Error opening file\n");
		exit(1);
	}

	// while loop
	while(1) {
		// reading from file, by line
		// reading happens one char at a time
		read_result = ReadLine(file, buff);
		// successful read
		if (read_result == 0) {
			EnqueueString(Q[0], buff);
		}
		// input line is too long
		else if (read_result == 1) {
			// flush line
			char c;
			while (c != '\n') {
				c = fgetc(file);
				if(feof(file)) {
					c = '\n';
				}	
			}
		}
		// EOF reached
		else { // read_result == 2
			EnqueueString(Q[0], buff);
			// NULL tells Munch1 that EOF is reached
			EnqueueString(Q[0], NULL);
			break;
		}
	}

	// After EOF is reached
	fclose(file);
	exit(1);

	return NULL;

}

// function to read the line from a file into a buffer, char by char
// arguments: the file being read from, and the buffer to read into
// returns: an int describing the success/failure of the read
// 	0 = success
// 	1 = line too long
// 	2 = EOF reached
int ReadLine(FILE *file, char *buff) {
	// read into the buffer
	for ( int i = 0; i < BUFF_SIZE; i++) {
		// get the next char
		buff[i] = fgetc(file);
		// check for newline
		if (buff[i] == '\n') {
			return 0;
		}
		//check for EOF
		if (feof(file)) {
			printf("EOF reached.\n");
			return 2;
		}	
	}

	// if it gets here, it read BUFF_SIZE chars w/o a newline
	// or an EOF, so the line is too long.
	printf("Line Too Long\n");
	return 1;
}

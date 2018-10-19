//////////////////////////////////
//
// File:	reader.c
//
// Authors:	Michael Tuchler
// 		Abhishek Kosuri
// Header:	threads.h
// Last Edit:	10/19/2018
//
//////////////////////////////////

#include "threads.h"

static int ReadLine(char *buff);

void* reader() {
	// declarations
	char buff[BUFF_SIZE];
	int read_result;

	int noEOF = 1;

	// while loop
	while(noEOF) {
		// reading from file, by line
		// reading happens one char at a time
		read_result = ReadLine(buff);
		//BuffRead(buff);
		// successful read
		if (read_result == 0) {
			//fprintf(stderr, "%s", buff);
			EnqueueString(Q[0], buff);
		}
		// input line is too long
		else if (read_result == 1) {
			// flush line
			// set c to something that's NOT a newline
			char c = 'a';
			// read until newline found
			while (c != '\n') {
				c = fgetc(stdin);
				// if EOF found before newline, then you're done
				if(feof(stdin)) {
					EnqueueString(Q[0], NULL);
					return NULL;
				}	
			}
		}
		// EOF reached
		else { // read_result == 2
			// Enqueue the buffer, unless it signals teh EOF
			if (buff[0] != '\0') {
				EnqueueString(Q[0], buff);
			}
			// NULL tells Munch1 that EOF is reached
			EnqueueString(Q[0], NULL);
			noEOF = 0;
		}
	}

	return NULL;

}

// function to read the line from a file into a buffer, char by char
// arguments: the file being read from, and the buffer to read into
// returns: an int describing the success/failure of the read
// 	0 = success
// 	1 = line too long
// 	2 = EOF reached
int ReadLine(char *buff) {
	// read into the buffer
	for ( int i = 0; i < BUFF_SIZE; i++) {
		// get the next char
		buff[i] = fgetc(stdin);
		// check for newline
		if (buff[i] == '\n') {
			buff[i] = '\0';
			return 0;
		}
		//check for EOF
		if (feof(stdin)) {
			buff[i] = '\0';
			return 2;
		}	
	}

	// if it gets here, it read BUFF_SIZE chars w/o a newline
	// or an EOF, so the line is too long.
	fprintf(stderr, "Line exceeds buffer bounds.\n");
	return 1;
}

// testing method for reading the buffer until
// the next newline character
void BuffRead(char * buff) {
	int index = 0;
	while (buff[index] != '\n' && index < BUFF_SIZE) {
		fprintf(stderr, "%c", buff[index]);
		index++;
	}
	fprintf(stderr, "\n");
	return;
}

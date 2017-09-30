//
// Created by Saxton on 9/22/2017.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef CIS343_CREVERSE_FILE_UTILS_H
#define CIS343_CREVERSE_FILE_UTILS_H

//Function for allocating memory, filling it with contents of the file, reversing it, and returning the size
int read_file( char* filename, char **buffer );

//Writes the contents of the already backwards buffer to the given file
int write_file( char* filename, char *buffer, int size);

#endif //CIS343_CREVERSE_FILE_UTILS_H

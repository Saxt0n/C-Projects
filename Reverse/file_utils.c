//
// Created by Saxton Stafford on 9/22/2017.
//

#include "file_utils.h"
#include <sys/stat.h>

//Function for allocating memory, filling it with contents of the file, and returning the size
int read_file( char* filename, char **buffer) {

    FILE* inFile = fopen(filename, "r");

    if (inFile == NULL){
        fprintf(stderr, "File failed to open");
        exit(EXIT_FAILURE);
    }

    //Code provided by instructor for determining size
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    if(size >= 1) {
        //Allocating memory for the buffer
        *buffer = (char*) malloc(size * sizeof(char));

        //Copies contents of file to buffer
        fread(*buffer, size, 1, inFile);

        fclose(inFile);

        return size;
    }
    else {
        fprintf(stderr, "Error, file size incorrectly read.");
        exit(EXIT_FAILURE);
    }
};

//Writes the contents of the buffer into the file backwards
int write_file( char* filename, char *buffer, int size) {

    FILE* outFile = fopen(filename, "w");

    //Sought help from https://stackoverflow.com/questions/42033932/
    //c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
    //for only this particular use of fwrite
    for (int i = size - 1; i >= 0; i--) {
        fwrite(buffer + i, 1, 1, outFile);
    }

    fclose(outFile);
    return size;
};


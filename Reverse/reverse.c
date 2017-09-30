//
// Created by Saxton Stafford on 9/22/2017.
//Sought much help from Stack Overflow for various pointer/buffer examples, TutorialsPoint for C API Documentation,
//as well as my friends Muna Gigowski and Chris Schertenlieb
//
#include "file_utils.h"

int main (int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Argument Error - Please try again with two text files.");
        return -1;
    }
    else {
        char* inFile = argv[1];
        char* outFile = argv[2];
        char* buffer;

        int size = read_file(inFile, &buffer);

        //Used to verify the accuracy of the size
        printf("Size of file is %i bytes.\n", size);

        write_file(outFile, buffer, size);
        free(buffer);
        return 0;
    }
}


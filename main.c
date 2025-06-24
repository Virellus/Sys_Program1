/*
Student Name: Wallace Switzer
Student NetID: wjs291
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){
    if (argv != 5){
        printf("Incorrect number of arguments!")
        return 1;
    }
    char *inFile = argv[1];
    char *outFile = argv[2];
    int fizzNum = atoi(argv[3]);
    int buzzNum = atoi(argv[4]);

    int inFD = open(input_file, O_RDONLY);
    int outFD = open(outFile, O_WRONLY|O_CREAT|O_TRUNC, 0644);

    if (inFD == -1 || outFD == -1) {
        printf("File failed to open!")
        return 1;
    }

    char inBuf[BUF_SIZE];
    int inBufValue

    //Process 
    while true {
        sscanf(inBuf, "%d", &inBufValue);
        char *outFizz = (inBufValue % fizzNum == 0) ? "Divisable by 3\n" : "Not divisable by 3\n";
        char *outBuzz = (inBufValue % buzzNum == 0) ? "Divisable by 5\n" : "Not divisable by 5\n";
        
    }

    close(inFD);
    close(outFD);
    return 0;
}
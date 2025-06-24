/*
Student Name: Wallace Switzer
Student NetID: wjs291
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){   // argc is the count of cli arguments, argv arrary of strings containing the arguments
    //verify
    if (argc != 5){
        printf("Incorrect number of arguments!");
        return 1;
    }
    // declaring variables
    char inBuf[BUF_SIZE];           // stores the raw data file in a box 
    char outBuf[BUF_SIZE];          // stores prepared output in a box
    char line[BUF_SIZE];            // puts the indv lines from the inBuff so they can be processed
    int readLen;                    // used later but will sotre how mnay bytes were read
    int offset = 0;                 // used to recall where in file the program is 
    
    //intitalize the arguments
    char *inFile = argv[1];
    char *outFile = argv[2];
    int fizzNum = atoi(argv[3]);
    int buzzNum = atoi(argv[4]);
    // attempts to open file
    int fd_inFile = open(inFile, O_RDONLY);
    int fd_outFile = open(outFile, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    //Process 
    while ((readLen = pread(fd_inFile, inBuf, BUF_SIZE, offset))> 0){   //loops through the file until over
        // starts at 0 and reads until line is over or buffer is full
        //returns number of bytes actually read
        // find new line char in buffer
        int lineLen = 0;
        for (int i = 0; i < readLen; i ++){ // loops through charcters in the buffer to find end of the line
            if (inBuf[i] == '\n') {
                lineLen = i; 
                break;
            }
        }
        // for the last line, use rest of buffer
        if (lineLen == 0){
            lineLen = readLen;
        }
        // copy the line to the line buffer and terminate it 
        strncpy(line, inBuf, lineLen);
        line[lineLen] = '\0';
        // convert strings to int
        int number = atoi(line);
        // creating a output starting with the number
        int outLen = snprintf(outBuf, BUF_SIZE, "%d", number);
        // fizz check
        if (number % fizzNum == 0){
            outLen += snprintf(outBuf + outLen, BUF_SIZE - outLen, " Fizz");
        }
        if (number % buzzNum == 0){
            outLen += snprintf(outBuf + outLen, BUF_SIZE - outLen, " Buzz");
        }
        // adding new line to end of output
        outLen += snprintf(outBuf + outLen, BUF_SIZE - outLen, "\n");
        // writing results to outfile
        write(fd_outFile, outBuf, outLen);
        offset += lineLen + 1;
    }
    
    close(fd_inFile);
    close(fd_outFile);
    return 0;
}
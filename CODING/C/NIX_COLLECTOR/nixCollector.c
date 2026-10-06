#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int main(int argc, char *argv[])
{
    //USAGE
    printf("USAGE: ./nixCollector -o fileName\n");
    
    char **environPointer = environ;
    FILE *fhDestination = fopen(argv[2], "w");
    
    while(NULL != *environPointer){
        //// Determine the actual string length so we don't just write blindly
        //don't blindly assume the amount of data you're writing. Determine the actual size of the data first.
        size_t bufferSize = strlen(*environPointer);
        fwrite(*environPointer, 1, bufferSize, fhDestination);
        fwrite("\n", 1, 1, fhDestination);
        environPointer++;
    }
    
    fclose(fhDestination);
    return 0;
}

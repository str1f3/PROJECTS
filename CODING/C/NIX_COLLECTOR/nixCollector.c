#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//access the process's environment
extern char **environ;

int main(int argc, char *argv[])
{
  int option = 0;
  char *outfile = NULL;

  char **environPointer = environ;
  FILE *fhDestination = fopen(argv[2], "w");

  if(NULL == fhDestination){
    perror("fopen");
	return 1;
  }

  //check options
  while((option = getopt(argc, argv, "ho:")) != -1){
    switch(option){
	  case 'h':{
	  	printf("USAGE: %s -o filename\n", argv[0]);
		return 0;
	  }
      case 'o':{
	    outfile = optarg;
		break;
	  }
	  case '?':
	    fprintf(stderr, "Invalid option or missing argument\n");
		return 1;
	}
  }

  //validate required options
  if(NULL == outfile || argc != optind){
    fprintf(stderr, "USAGE: %s -o filename\n", argv[0]);
	return 1;
  }

  //collect environment strings
  while(NULL != *environPointer){
    size_t bufferSize = strlen(*environPointer);
	fwrite(*environPointer, 1, bufferSize, fhDestination);
	fwrite("\n", 1, 1, fhDestination);
	environPointer++;
  }

  fclose(fhDestination);
  return 0;
}

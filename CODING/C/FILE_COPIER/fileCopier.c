/*######################################################################################
# Dev: cnd.dev
# Program Name: fileCopier-v1.0.0-linux-x86-64
# Version: 1.0.0
#  - Major.Minor.Update
# Date: 072119AUG25
# Filename: fileCopier.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 fileCopier.c -o fileCopier-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define bufferSize 1024

int main(int argc, char *argv[])
{
  size_t bytesIn = 0;
  size_t bytesOut = 0;
  FILE *fhSource = NULL;
  FILE *fhDestination = NULL;
  size_t readSizeInBytes = 1;
  unsigned char buffer[bufferSize];
  const char *readMode = NULL;
  const char *writeMode = NULL;

  if (argc != 5){
    puts("");
    printf("[+] Usage: %s destinationFilePath sourceFilePath --mode {text | binary}\n", argv[0]);
    printf("[+] Example: ./fileCopier . /etc/passwd --mode text\n");
    puts("");
    exit(1);
  }

  if(strcmp(argv[4], "text") == 0){
    readMode = "r";
    writeMode = "w";
  }
  else if(strcmp(argv[4], "binary") == 0){
    readMode = "rb";
    writeMode = "wb";
  }
  else{
    printf("%s is not a recognized mode\n", argv[4]);
    return 1;
  }

  fhSource = fopen(argv[2], readMode);
  if (fhSource == NULL){
    perror("Failed to open source file.");
    exit(1);
  }

  fhDestination = fopen(argv[1], writeMode);
  if(fhDestination == NULL){
    perror("Failed to open destination file.");
    fclose(fhSource);
    exit(1);
  }

  while((bytesIn = fread(buffer, readSizeInBytes, bufferSize, fhSource)) > 0 ){
    bytesOut = fwrite(buffer, readSizeInBytes, bytesIn, fhDestination);
    if(bytesOut != bytesIn){
      printf("Write error.\n");
      printf("Error code: %d\n", errno);
      fclose(fhSource);
      fclose(fhDestination);
      exit(1);
    }
  }

  fclose(fhSource);
  fclose(fhDestination);

  printf("File copied successfully.\n");
  return 0;
}

/*######################################################################################
# Dev: cnd.dev
# Program Name: cliWriter-v1.0.0-linux-x86-64
# Version: 1.0.0
#  - Major.Minor.Update
# Date: 200106JUL25
# Filename: cliWriter.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 cliWriter.c -o cliWriter-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <errno.h>

#define PATH_SIZE 255

int main(void)
{
  FILE *pFile = NULL;
  int readCharacter;
  char filePath[PATH_SIZE];

  printf("Enter File Path: ");
  if (fgets(filePath, PATH_SIZE, stdin) == NULL){
    perror("Invalid path\n");
    printf("Error code: %d\n", errno);
    return 1;
  }

  //remove trailing newline
  for (int i = 0; i < PATH_SIZE; i++){
    if(filePath[i] == '\n'){
      filePath[i] = '\0';
      break;
    }
    if(filePath[i] == '\0'){
      break;
    }
  }

  pFile = fopen(filePath, "w");

  if (pFile != NULL) {
    printf("File opened successfully\n");
    printf("Press 'CTRL+D' (Linux/macOS) or 'CTRL+Z' (Windows) to end entry\n");

    // Reading one character at a time
    while ((readCharacter = fgetc(stdin)) != EOF) {
      fputc(readCharacter, pFile);
    }

    fclose(pFile);
  }
  else {
    perror("File access failed");
    printf("Error code: %d\n", errno);
  }

  return 0;
}

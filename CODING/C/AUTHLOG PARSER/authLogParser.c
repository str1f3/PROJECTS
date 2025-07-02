/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 291517JUN25
# Filename: authLogParser.c
# Dependency: auth.log
# Compile Cmd: gcc -m64 -O1 authLogParser.c -o authLogParser-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: This tool simulates part of a real-world host-based
#    intrusion detection system by parsing system authentication logs
#    (auth.log) and detecting signs of brute-force login attempts. It
#    integrates basic network context and validates usernames against the
#    system to distinguish between mistyped and malicious logins.
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int selectMode(int *mode) {
  bool selection = true;
  while (selection) {
    printf("MODE: ");
    if (scanf("%d", mode) == 1 && (*mode == 1 || *mode == 2)) {
      break;
    }
    while (getchar() != '\n');  // Clear invalid input
  }
  return 0;
}

FILE* openFile(){
  int flag = 1;
  char filePath[255] = "auth.log";   //full path /var/log/auth.log
  FILE* file = fopen(filePath, "r");
  return file;
}

int main(int argc, char *argv[])
{
  int mode = 0;
  int totalFailedLogins = 0;
  unsigned char lineReadBuffer = 255;
  char readLines[lineReadBuffer];
  //char delimiter[] = " ";
  //char *token = NULL;
  char failedLoginsMarker[] = "Failed password for";
  char successfulLoginsMarker[] = "Accepted password for";


  puts("Select Mode: [1 = Successful Logins] | [2 = Failed logins]");
  selectMode(&mode);
  
  //INPUT
  FILE* file = openFile();
  
    if (file == NULL){
      puts("Error opening file.\n");
      puts("Rerun the program to continue...");
    }
    else{
      puts("File Successfully Opened");
      
      //PROCESS
      //1.FAILED LOGINS - test if accessed file can be read
      while(fgets(readLines, sizeof(readLines), file)){
        if (strstr(readLines, failedLoginsMarker)){
          printf("%s", readLines);
        }
        else{
          continue;
        }
      }
        /*token = strtok(readLines, delimiter);
        while(token != NULL){
          if (strcmp
          //printf("Word: %s\n", token);         //print current word on each line
          token = strtok(NULL, delimiter);     //move to the next word
        }
      
        //this printf is for testing only to see the read contents
        //printf("%s", readLines);
      }*/
      //printf("Total Failed Authentications: %d\n", totalFailedLogins);
      //in auth.log this can be 
      
      
      
      
      
      //2.SUCCESSFUL LOGINS
          
      fclose(file);
    }

  return 0;
}

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
​
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
​
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
​
FILE* openFile(){
  int flag = 1;
  char filePath[255] = "auth.log";   //full path /var/log/auth.log
  FILE* file = fopen(filePath, "r");
  return file;
}
​
int main(int argc, char *argv[])
{
  int mode = 0;
  unsigned int totalFailedLogins = 0;
  unsigned int totalSuccessfulLogins = 0;
  unsigned char lineReadBuffer = 255;
  char readLines[lineReadBuffer];
  //char delimiter[] = " ";
  //char *token = NULL;
  char failedLoginsMarker[] = "Failed password for";
  char successfulLoginsMarker[] = "Accepted password for";
​
​
  puts("Select Mode: ");
  //puts("1. Brute Force Detection: ");
  //puts("2. Command Injection Detection: ");
  puts("1. Failed Logins");
  puts("2. Successful Logins");
​
  selectMode(&mode);
​
  //INPUT
  FILE* file = openFile();
​
  if (file == NULL){
    puts("Error opening file.\n");
    puts("Rerun the program to continue...");
  }
  else{
    puts("File Successfully Opened");
​
    switch (mode) {
      case 1:{
        puts("******* BRUTE FORCE DETECTION MODE *******");
        //PROCESS: 1.FAILED LOGINS
        while(fgets(readLines, sizeof(readLines), file)){
          if(strstr(readLines, failedLoginsMarker)){
            printf("%s", readLines);
            totalFailedLogins++;
          }
        }
        printf("\nTotal Failed Logins: %d", totalFailedLogins);
        break;
      }
      case 2:{
        puts("******* BRUTE FORCE DETECTION MODE *******");
        //PROCESS: 2.SUCCESSFUL LOGINS
        while(fgets(readLines, sizeof(readLines), file)){
          if(strstr(readLines, successfulLoginsMarker)){
            printf("%s", readLines);
            totalSuccessfulLogins++;
          }
        }
        printf("\nTotal Successful Logins: %d", totalSuccessfulLogins);
        break;
      }
      default:{
        puts("Invalid Selection...rerun the program again to continue.");
      }
    }
  }
  fclose(file);
​
  return 0;
}

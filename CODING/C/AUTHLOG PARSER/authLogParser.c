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

/*int selectMode(int *mode) {
  bool selection = true;
  while (selection) {
    printf("MODE: ");
    if (scanf("%d", mode) == 1 && (*mode == 1 || *mode == 2) ) {
      break;
    }
    while (getchar() != '\n');  // Clear invalid input
  }
  return 0;
}*/

//mode selector
int modeSelector(void){
  int mode;
  int inputStatus;

  while (1){
    printf("mode: ");
    inputStatus = scanf("%d", &mode);
    //if input is successfully read...clear the rest of the line including newline
    if (inputStatus == 1){
      while (getchar() != '\n');
        return mode;
    } 
    else {
      printf("Invalid input. Select a number.\n");
      while (getchar() != '\n');
    }
  }
}

FILE* openAuthLogFile(){
  int flag = 1;
  char filePath[255] = "auth.log";   //full path /var/log/auth.log
  FILE* authLogFile = fopen(filePath, "r");
  return authLogFile;
}

//this passwd file is just a helper for identifying usernames that aren't in the system
//when a brute force attack is occurring, actors are typically spraying a bunch of usernames and passwords in a short amount of time
//for password spraying, it is the password that is being sprayed a bunch of times against a single username
FILE* openPasswdFile(){
  int flag = 1;
  char filePath[255] = "passwd";  //full path /etc/passwd
  FILE * passwdFile = fopen(filePath, "r");
  return passwdFile;
}

int main(int argc, char *argv[])
{
  int mode = 0;
  int totalFailedLogins = 0;
  int totalSuccessfulLogins = 0;
  int lineReadBuffer = 255;
  char readLines[lineReadBuffer];
  char failedLoginsMarker[] = "Failed password for";
  char successfulLoginsMarker[] = "Accepted password for";

  //char delimiter[] = " ";
  //char *token = NULL;
  //
  // Pointer to hold each extracted word (token)
  //char *token = strtok(str, delimiter);

//----------------------------------------------------

  puts("Select Mode: ");
  //puts("1. Brute Force Detection: ");
  //puts("2. Command Injection Detection: ");
  puts("1. Failed Logins");
  puts("2. Successful Logins");
  puts("3. Valid Users");

  mode = modeSelector();

  //INPUT
  FILE* authLogFile = openAuthLogFile();
  FILE* passwdFile = openPasswdFile();

  if (authLogFile == NULL || passwdFile == NULL){
    puts("Error opening file.\n");
    puts("Rerun the program to continue...");
  }
  else{
    puts("Files Successfully Opened");

    if (mode == 1){	  
	  //PROCESS: 1.DISPLAY FAILED LOGINS
	  while(fgets(readLines, sizeof(readLines), authLogFile)){
	    if (strstr(readLines, failedLoginsMarker)){
		  printf("%s", readLines);
		  totalFailedLogins++;
		}
	  }
	  printf("\nTotal Failed Logins: %d", totalFailedLogins);
	}
	else if (mode == 2){
	  //PROCESS: 2.DISPLAY SUCCESSFUL LOGINS
	  while(fgets(readLines, sizeof(readLines), authLogFile)){
	    if (strstr(readLines, successfulLoginsMarker)){
		  printf("%s", readLines);
		  totalSuccessfulLogins++;
		}
	  }
	  printf("\nTotal Successful Logins: %d", totalSuccessfulLogins);
	}
	else if (mode == 3){
	  //GET ONLY THE 1st word (usernames) in the passwd file (fullpath /etc/passwd) - 100 usernames total (for now)
	  char usernameDelimiter[] = ":";   //tokenize /etc/passwd
	  char passwdUsernames[100][100];
	  char *token = NULL;
	  int userIndex = 0;
	  
	  while(fgets(readLines, sizeof(readLines), passwdFile) && userIndex < 100){
	    // Pointer to hold each extracted word (token)
	    token = strtok(readLines, usernameDelimiter);    //this grabs the usernames (first column)
	  
	    // Loop to extract and print all tokens
        if (token != NULL) {
		  strncpy(passwdUsernames[userIndex], token, sizeof(passwdUsernames[userIndex]) - 1);
		  passwdUsernames[userIndex][sizeof(passwdUsernames[userIndex]) - 1] = '\0';  // null terminate each usernames
          userIndex++;
        }
	  }	
      for (int i = 0; i < userIndex; i++) {
        printf("Valid User [%d]: %s\n", i, passwdUsernames[i]);
      }
	}
	else{
	  puts("Invalid Selection...rerun the program again to continue.");
	}
  }
  fclose(authLogFile);
  fclose(passwdFile);

  return 0;
}

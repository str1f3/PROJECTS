/*##################################################################
# Dev: cnd.dev
# Program Name: UsernameCollector
# Version: 1.0.0               //Major.Minor.Update
# Date: 101125JUN25
# Filename: usernameCollector.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 BitwiseCalculator.c -o BitwiseCalculator
# Synopsis: ... describes what the program does, 
#               how it works, and its key components
# this will eventually be fed to a database
##################################################################*/


#include <stdio.h>
#include <string.h>

int main(void)
{
  char userName[1000][26];
  int nameCount = 0;
  
  puts("Enter usernames then enter 'quit' once done.");
  
  for (int i = 0; nameCount < 1000; i++){
    printf("Enter username%d : ", nameCount + 1);
	scanf("%25s", userName[i]);
	
	if (strcmp(userName[i], "quit") == 0){
	  break;
	}
	nameCount++;
  }
  
  for (int i = 0; i < nameCount; i++){
    printf("Username%d:  %s\n", i + 1, userName[i]);
  }
  
  return 0;
}

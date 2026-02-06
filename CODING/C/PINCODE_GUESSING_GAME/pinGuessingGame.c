/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 291027JUN25
# Filename: pinGuessingGame.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 pinGuessingGame.c -o pinGuessingGame-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: 
#     - Simple PIN guessing game demonstrating safe integer input handling
#     - Uses scanf with width specifier and manual stdin flushing 
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <stdbool.h>

bool validEntry(int *enteredPIN){
  bool valid = false;

  do{
    printf("Enter PIN to unlock the system: ");
    int result = scanf("%4d", enteredPIN);

    if(result == 1){
      int nextChar = getchar();
      if(nextChar != '\n' && nextChar != EOF){
        while(nextChar != '\n' && nextChar != EOF)
          nextChar = getchar();

        printf("Invalid input...Try again.\n");
        valid = false;
        continue;
      }
      valid = true;
    }
    else if(result == EOF){
      printf("\nEnd of input detected. Exiting...\n");
      return false;
    }
    else{
      //clear invalid input
      int discardChar;
      while(((discardChar = getchar()) != '\n') && discardChar != EOF)
        //NOP
        ;
      printf("Invalid input...Try again.\n");
      valid = false;
    }

  }while(!valid);

  return true;
}

int main() {
  int enteredPIN = 0;
  bool accessGranted = false;

  puts("PIN NUMBER GUESSING GAME");

  if(!validEntry(&enteredPIN)){
    return 1;
  }

  do{
    if (enteredPIN != 1337){
      printf("Incorrect PIN. Try again...");
      puts("HINT: System PIN has four digits\n");
      if(!validEntry(&enteredPIN)){
        return 1;
      }
    }
    else{
      printf("Access granted - System PIN cracked!");
      accessGranted = true;
    }
  } while (!accessGranted);

  return 0;
}

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
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int enteredPIN;
    bool accessGranted = false;
    
    puts("PIN NUMBER GUESSING GAME");
    
    do {
      printf("Enter PIN to unlock the system: ");
      scanf("%4d", &enteredPIN);
      if (enteredPIN != 1337){
          printf("Incorrect PIN. Try again...\n");
          puts("HINT: System PIN has four digits\n");
      }
      else{
          printf("Access granted - System PIN cracked!");
          accessGranted = true;
      }
    } while (!accessGranted);
}

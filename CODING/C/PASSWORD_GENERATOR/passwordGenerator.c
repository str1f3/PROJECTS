/*######################################################################################
# Dev: cnd.dev
# Program Name: PasswordGenerator-v1.0.0-linux-x86-64
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 230900JUN25
# Filename: randomPWGenerator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 passwordGenerator.c charsets.c generator.c -o PasswordGenerator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "charsets.h"
#include "generator.h"

int main()
{
  srand(time(NULL));
  PASSWORD password = {'\0'};

  int passwordLength = 0;
    
    //INPUT
    puts("Password Generator v1.0");
    
    printf("Enter Password Length: ");
    scanf("%32d", &passwordLength);
    
    //PROCESS
    password = passwordGenerator(passwordLength);

    //OUTPUT
    
    printf("Password: %s", password.randomPassword);

    return 0;
}

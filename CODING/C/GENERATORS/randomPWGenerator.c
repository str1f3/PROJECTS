/*######################################################################################
# Dev: cnd.dev
# Program Name: randomPWGenerator-v1.0.0-linux-x86-64
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 230900JUN25
# Filename: randomPWGenerator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 randomPWGenerator.c -o randomPWGenerator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include "charsets.h"

int main()
{

    char uppercaseLetters[27];
    char lowercaseLetters[27];
    char numbers[10];
    char symbols[33];
    //int arrayLength = (sizeof(uppercaseLetters) / sizeof(int));
    
    //populate uppercase letters
    populateUppercase(uppercaseLetters);
    
    //uppercase test display
    for (int i = 0; i < 26; i++){
        printf("%c ", uppercaseLetters[i]);
    }
    
    puts("\n");
    
    //populate lowercase letters
    populateLowercase(lowercaseLetters);
    
    //lowercase test display
    for (int i = 0; i < 26; i++){
        printf("%c ", lowercaseLetters[i]);
    }
    
    puts("\n");
    
    //populate numbers
    populateNumbers(numbers);

    //numbers test display
    for (int i = 0; i < 10; i++){
        printf("%c ", numbers[i]);
    }
    
    puts("\n");
    
    //populate special characters
    populateSymbols(symbols);
    
    //symbols test display
    for (int i = 0; i < 32; i++){
      printf("%c ", symbols[i]);
    }

    return 0;
}

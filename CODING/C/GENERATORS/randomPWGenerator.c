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
​
#include <stdio.h>
​
void populateUppercase(char uppercaseLetters[]){
  for (int i = 0; i < 26; i++){
    uppercaseLetters[i] = i + 65;
  }
}
​
void populateLowercase(char lowercaseLetters[]){
  for (int i = 0; i < 26; i++){
    lowercaseLetters[i] = i + 97;
  }
}
​
void populateNumbers(char numbers[]){
  for (int i = 0; i < 10; i++){
    numbers[i] = i;
  }
}
​
void populateSymbols(char symbols[]){
  /*** Total Symbols = 32 ***/
​
  //ASCII 33–47: ! " # $ % & ' ( ) * + , - . /
  for (int i = 0; i < 15; i++){
    symbols[i] = i + 33;
  }
  
  //ASCII 58–64: : ; < = > ? @
  for (int i = 0; i < 7; i++){
    symbols[i + 15] = i + 58;
  }
  
  
  //ASCII 91–96: [ \ ] ^ _ `
  for (int i = 0; i < 6; i++){
    symbols[i + 22] = i + 91;
  }
  
  
  //ASCII 123–126: { | } ~
  for (int i = 0; i < 4; i++){
    symbols[i + 28] = i + 123;
  } 
}
​
int main()
{
​
    char uppercaseLetters[27];
    char lowercaseLetters[27];
    unsigned char numbers[10];
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
​
    //numbers test display
    for (int i = 0; i < 10; i++){
        printf("%d ", numbers[i]);
    }
    
    puts("\n");
    
    //populate special characters
    populateSymbols(symbols);
    
    //symbols test display
    for (int i = 0; i < 32; i++){
      printf("%c ", symbols[i]);
    }
​
    return 0;
}

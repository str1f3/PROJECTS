/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.1
#  - Major.Minor.Update/BuildNumber
# Date: 181445MAR25
# Filename: bitwise.c
# Dependency: bitwise.h
# Compile Cmd: N/A
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include "bitwise.h"

//INPUT
int selectMode(int* mode){
  while (printf("mode: "), scanf("%d", mode) != 1){
    while (getchar() != '\n');
  }
  return 0;
}

int getData(int* userInput1, int* userInput2){
    char buffer1[33];
    char buffer2[33];

    while (printf("Enter first number (binary): \t"), scanf("%32s", buffer1) != 1)
        while (getchar() != '\n');

    while (printf("Enter second number (binary): \t"), scanf("%32s", buffer2) != 1)
        while (getchar() != '\n');

    *userInput1 = binaryStringToInt(buffer1);
    *userInput2 = binaryStringToInt(buffer2);

    return 0;
}

//PROCESS
int binaryStringToInt(const char* binaryStr) {
    int result = 0;
    
    while (*binaryStr == '0' || *binaryStr == '1') {
        result = result * 2 + (*binaryStr - '0');
        binaryStr++; 
    }
    
    return result;
}
int bitwiseAND(int userInput1, int userInput2){
  return userInput1 & userInput2;
}

int bitwiseOR(int userInput1, int userInput2){
  return userInput1 | userInput2;
}

int bitwiseXOR(int userInput1, int userInput2){
  return userInput1 ^ userInput2;
}

int bitwiseNOT(int userInput1){
  return ~userInput1;
}

//OUTPUT
void printBinary(unsigned int result){
  for (int i = 31; i >= 0; i--) {
    printf("%d", (result >> i) & 1);
      if (i % 8 == 0 && i != 0) {
        printf(" ");  
      }
  }
}

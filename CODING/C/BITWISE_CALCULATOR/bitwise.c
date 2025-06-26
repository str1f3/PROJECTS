/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.1
#  - Major.Minor.Update/BuildNumber
# Date: 181445MAR25
# Filename: bitwise.c
# Dependency: bitwise.h
# Compile Cmd: gcc -m64 -O1 bitwiseCalculator.c -o BitwiseCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

int selectMode(int* mode){
  while (printf("mode: "), scanf("%d", mode) != 1){
    while (getchar() != '\n');
  }
  return 0;
}

int getData(int* userInput1, int* userInput2){
  while (printf("Enter first number: "), scanf("%d", userInput1) != 1){
        while (getchar() != '\n');
  }
  while (printf("Enter second number: "), scanf("%d", userInput2) != 1){
        while (getchar() != '\n');
  }
  return 0;
}


int decimalToBinary(int userInput){
    
  int binaryRepresentation = 0;
  int i = 1;
  int remainder;
    
  while (userInput != 0){
    
    remainder = userInput % 2;
    userInput /= 2;
    binaryRepresentation += remainder * i;
    i *= 10;
  }
  
  return binaryRepresentation;
}

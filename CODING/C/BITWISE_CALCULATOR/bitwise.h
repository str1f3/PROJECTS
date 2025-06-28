/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.1
#  - Major.Minor.Update/BuildNumber
# Date: 181445MAR25
# Filename: bitwise.h
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 bitwiseCalculator.c bitwise.h bitwise.c -o BitwiseCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#ifndef BITWISE_H
#define BITWISE_H

//SELECTION MODE
int selectMode(int* mode);

//GET DATA - AND/OR/XOR
int getData(int* userInput1, int* userInput2);

//PROCESS DATA
int binaryStringToInt(const char* binaryStr);

int bitwiseAND(int userInput1, int userInput2);

int bitwiseOR(int userInput1, int userInput2);

int bitwiseXOR(int userInput1, int userInput2);

int bitwiseNOT(int userInput1);

//OUTPUT
void printBinary(unsigned int result);

#endif

/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 231504JUN25
# Filename: charsets.c
# Dependency: charsets.h
# Compile Cmd: N/A
# Synopsis:
#  - Overview: Used as part of utilities needing predefined character sets such as
#              password generators, encoders, or validation tools.
#  - Technical: Implements character array population functions declared in charsets.h.
#               Each function fills an array with a specific category of ASCII characters.
######################################################################################*/

#include "charsets.h"

void populateUppercase(char uppercaseLetters[]){
  for (int i = 0; i < 26; i++){
    uppercaseLetters[i] = i + 65;
  }
}

void populateLowercase(char lowercaseLetters[]){
  for (int i = 0; i < 26; i++){
    lowercaseLetters[i] = i + 97;
  }
}

void populateNumbers(char numbers[]){
  for (int i = 0; i < 10; i++){
    numbers[i] = i + '0';
  }
}

void populateSymbols(char symbols[]){
  /*** Total Symbols = 32 ***/

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

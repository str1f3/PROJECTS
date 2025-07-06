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

#include <stddef.h>
#include "charsets.h"

PASSWORD populateUppercase(void){
  PASSWORD uppercase = {'\0'};
  size_t arraySize = sizeof(uppercase.uppercaseLetters) / sizeof(uppercase.uppercaseLetters[0]);
  for (int i = 0; i < arraySize - 1; i++){
    uppercase.uppercaseLetters[i] = i + 'A';    // 'A' = 65
  }
  uppercase.uppercaseLetters[arraySize - 1] = '\0';
  
  return uppercase;
}

PASSWORD populateLowercase(void){
  PASSWORD lowercase = {'\0'};
  size_t arraySize = sizeof(lowercase.lowercaseLetters) / sizeof(lowercase.lowercaseLetters[0]);
  for (int i = 0; i < arraySize - 1; i++){
    lowercase.lowercaseLetters[i] = i + 'a';  // 'a' = 97
  }
  lowercase.lowercaseLetters[arraySize - 1] = '\0';
  
  return lowercase;
}
PASSWORD populateNumbers(void){
  PASSWORD number = {'\0'};
  size_t arraySize = sizeof(number.numbers) / sizeof(number.numbers[0]);
  for (int i = 0; i < arraySize - 1; i++){
    number.numbers[i] = i + '0';
  }
  number.numbers[arraySize - 1] = '\0';
  
  return number;
}

PASSWORD populateSymbols(void){
  PASSWORD special = {'\0'};
  size_t arraySize = sizeof(special.symbols) / sizeof(special.symbols[0]);
  
  /*** Total Symbols = 32 ***/

  //ASCII 33–47: ! " # $ % & ' ( ) * + , - . /
  for (int i = 0; i < 15; i++){
    special.symbols[i] = i + 33;
  }
  
  //ASCII 58–64: : ; < = > ? @
  for (int i = 0; i < 7; i++){
    special.symbols[i + 15] = i + 58;
  }
  
  //ASCII 91–96: [ \ ] ^ _ `
  for (int i = 0; i < 6; i++){
    special.symbols[i + 22] = i + 91;
  }
  
  //ASCII 123–126: { | } ~
  for (int i = 0; i < 4; i++){
    special.symbols[i + 28] = i + 123;
  } 
  
  return special;
}

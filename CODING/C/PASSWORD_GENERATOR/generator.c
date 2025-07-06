/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 231504JUN25
# Filename: charsets.h
# Dependency: N/A
# Compile Cmd: N/A
# Synopsis:
#  - Overview: Declares functions for populating arrays with specific character sets 
#              (uppercase, lowercase, digits, symbols) using ASCII values.
#  - Technical: Intended for programs that need predefined character arrays, such as
#               password generators or data format validators.
######################################################################################*/

#include <stdlib.h>
#include "generator.h"
#include "string.h"

PASSWORD passwordGenerator(int passwordLength){
  char generatedPassword[passwordLength];
  PASSWORD password = {'\0'};
  size_t arraySize = sizeof(password.randomPassword) / sizeof(password.randomPassword[0]);
  
  //fill
  //aggregate variable hold all {uppercase} + {lowercase} + {numbers} + {symbols}
  PASSWORD uppercaseCharacters = populateUppercase();
  PASSWORD lowercaseCharacters = populateLowercase();
  PASSWORD digitsCharacters = populateNumbers();
  PASSWORD specialCharacters = populateSymbols();
  
  strcat(password.collection, uppercaseCharacters.uppercaseLetters);
  strcat(password.collection, lowercaseCharacters.lowercaseLetters);
  strcat(password.collection, digitsCharacters.numbers);
  strcat(password.collection,  specialCharacters.symbols);
  
  //Knuth Shuffle Algorithm - use user supplied password length here to only get that specified number of password
  //shuffle the collection then assign user specified passwordLength to retrive from collection
  size_t collectionLength = strlen(password.collection);
  for (int i = collectionLength - 1; i > 0; i--){
    int j = rand() % (i + 1);
    char temp = password.collection[i];
    password.collection[i] = password.collection[j];
    password.collection[j] = temp;
  }
  
  //copy user supplied passwordLength characters to randomPassword
  strncpy(password.randomPassword, password.collection, passwordLength);
  password.randomPassword[passwordLength] = '\0';
  
  return password;
}

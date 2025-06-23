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
​
#ifndef CHARSETS_H
#define CHARSETS_H
​
void populateUppercase(char uppercaseLetters[]);
void populateLowercase(char lowercaseLetters[]);
void populateNumbers(char numbers[]);
void populateSymbols(char symbols[]);
​
#endif

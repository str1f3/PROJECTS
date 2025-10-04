/*######################################################################################
# Dev: cnd.dev
# Program Name: toUpper
# Version: 0.0.1
# Date: 13JUL25
# Filename: toUpper.cpp
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 toUpper.c -o toUpper-v0.0.1-linux-x86-64
# Synopsis:
#  - Overview:
#      This program reads a single character input from the user and converts it to
#      uppercase without using built-in library functions such as toupper() from ctype.h.
#      It demonstrates how to manually manipulate characters using ASCII logic,
#      arrays, and iteration.
#
#  - Technical:
#      The toUpper() function creates two character arrays:
#      one for uppercase letters ('A'–'Z') and another for lowercase letters ('a'–'z').
#      It iterates through the lowercase array to compare each element against
#      the user’s input. When a match is found, the corresponding uppercase letter
#      is selected from the uppercase array and returned.
#
#      If the input character is already uppercase or not alphabetic,
#      the function returns it unchanged. The main() function reads the user input,
#      calls toUpper(), and prints the resulting character to standard output.
######################################################################################*/

#include <stdio.h>

char toUpper(char input){

  char toUppercase = input;

  //populate array of uppercase characters
  char arrayNameUppercase[27];
  for (int i = 0; i < 26; i++){
    arrayNameUppercase[i] = 'A' + i;
  }
  arrayNameUppercase[26] = '\0';

  //populate array of lowercase characters
  char arrayNameLowercase[27];
  for (int i = 0; i < 26; i++){
    arrayNameLowercase[i] = 'a' + i;
  }
  arrayNameLowercase[26] = '\0';

  //iterate through the array of lowercase characters & compare user input
  //if input is NOT uppercase, then make it uppercase

  for (int i = 0; i < 26; i++){
    if (arrayNameLowercase[i] == input){
      toUppercase = arrayNameUppercase[i];
      break;
    }
  }
  return toUppercase;
}

int main(void)
{
  char input;
  scanf(" %c", &input);

  printf("%c", toUpper(input));

  return 0;
}

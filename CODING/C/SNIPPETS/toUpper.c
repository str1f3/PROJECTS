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

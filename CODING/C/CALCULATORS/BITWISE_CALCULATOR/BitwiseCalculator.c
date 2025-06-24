/*######################################################################################
# Dev: cnd.dev
# Program Name: BitwiseCalculator-v1.0.0-linux-x86-64
# Version: 1.0.0
#  - Major.Minor.Update
# Date: 181445MAR25
# Filename: bitwiseCalculator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 bitwiseCalculator.c -o BitwiseCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include "bitwise.h"

int main(int argc, char *argv[]) {

  int mode = 0;
  int userInput1 = 0;
  int userInput2 = 0;
  int decimalResult = 0;
  int binaryResult = 0;
    
  puts("Select mode: [1=&], [2=|], [3=^], [4=~]");
  selectMode(&mode);
  
    
  switch (mode){
    case 1:{
            
      //input
      puts("\nAND MODE");
      getData(&userInput1, &userInput2);
            
      //process
      decimalResult = (userInput1 & userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = decimalToBinary(decimalResult);

            
      //output
      printf("Binary: %d AND %d = %d\n", userInput1Binary, userInput2Binary, binaryResult);
      printf("Decimal: %d AND %d = %d\n", userInput1, userInput2, decimalResult);
            
      break;
    }
       
    case 2:{
      
      //input
      puts("\nOR MODE");
      getData(&userInput1, &userInput2);
            
      //process
      decimalResult = (userInput1 | userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = decimalToBinary(decimalResult);
            
      //output
      printf("Binary: %d OR %d = %d\n", userInput1Binary, userInput2Binary, binaryResult);
      printf("Decimal: %d OR %d = %d\n", userInput1, userInput2, decimalResult);
    
      break;
    }
        
    case 3:{
      //input
      puts("\nXOR MODE");
      getData(&userInput1, &userInput2);
            
      //process
      decimalResult = (userInput1 ^ userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = decimalToBinary(decimalResult);
            
      //output
      printf("Binary: %d XOR %d = %d\n", userInput1Binary, userInput2Binary, binaryResult);
      printf("Decimal: %d XOR %d = %d\n", userInput1, userInput2, decimalResult);
    
      break;
    }
        
    case 4:{
      //input
      puts("\nNOT MODE");
      while (printf("Enter a value to negate: "), scanf("%d", &userInput1) != 1)
        while (getchar() != '\n');
            
      //process
      decimalResult = ~userInput1;
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(~userInput1);
      binaryResult = userInput1Binary;
            
      //output
      printf("Binary: %d = %d\n", userInput1Binary, binaryResult);
      printf("Decimal: %d = %d\n", userInput1, decimalResult);
    
      break;
    }
        
    default:{
      puts("Invalid selection...re-run the program again to continue");
    }
  }

  return 0;
}

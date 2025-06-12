/*##################################################################
# Dev: cnd.dev
# Program Name: BitwiseCalculator
# Version: 1.0.0               //Major.Minor.Update
# Date: 181445MAR25
# Filename: BitwiseCalculator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 BitwiseCalculator.c -o BitwiseCalculator
# Synopsis: ... describes what the program does, 
#               how it works, and its key components
##################################################################*/

#include <stdio.h>

int decimalToBinary(int userInput);

int main(int argc, char *argv[]) {

  int mode = 0;
  int userInput1 = 0;
  int userInput2 = 0;
  int decimalResult = 0;
  int binaryResult = 0;
    
  puts("Select mode: [1=&], [2=|], [3=^], [4=~]");
  while (printf("mode: "), scanf("%d", &mode) != 1){
    while (getchar() != '\n');
  }
    
  switch (mode){
    case 1:{
            
      //input
      puts("\nAND MODE");
      while (printf("Enter first number: "), scanf("%d", &userInput1) != 1)
        while (getchar() != '\n');
            
      while (printf("Enter second number: "), scanf("%d", &userInput2) != 1)
        while (getchar() != '\n');
            
      //process
      decimalResult = (userInput1 & userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = (userInput1Binary & userInput2Binary);
            
      //output
      printf("Binary: %d AND %d = %d\n", userInput1Binary, userInput2Binary, binaryResult);
      printf("Decimal: %d AND %d = %d\n", userInput1, userInput2, decimalResult);
            
      break;
    }
       
    case 2:{
      
      //input
      puts("\nOR MODE");
      while (printf("Enter first number: "), scanf("%d", &userInput1) != 1)
        while (getchar() != '\n');
            
      while (printf("Enter second number: "), scanf("%d", &userInput2) != 1)
        while (getchar() != '\n');
            
      //process
      decimalResult = (userInput1 | userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = (userInput1Binary & userInput2Binary);
            
      //output
      printf("Binary: %d OR %d = %d\n", userInput1Binary, userInput2Binary, binaryResult);
      printf("Decimal: %d OR %d = %d\n", userInput1, userInput2, decimalResult);
    
      break;
    }
        
    case 3:{
      //input
      puts("\nXOR MODE");
      while (printf("Enter first number: "), scanf("%d", &userInput1) != 1)
        while (getchar() != '\n');
            
      while (printf("Enter second number: "), scanf("%d", &userInput2) != 1)
        while (getchar() != '\n');
            
      //process
      decimalResult = (userInput1 ^ userInput2);
            
      //show them in binary as well (future)
      int userInput1Binary = decimalToBinary(userInput1);
      int userInput2Binary = decimalToBinary(userInput2);
      binaryResult = (userInput1Binary ^ userInput2Binary);
            
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
      break;
    }
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

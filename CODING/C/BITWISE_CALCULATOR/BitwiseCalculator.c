/*######################################################################################
# Dev: cnd.dev
# Program Name: BitwiseCalculator-v1.0.0-linux-x86-64
# Version: 1.0.1
#  - Major.Minor.Update
# Date: 181445MAR25
# Filename: bitwiseCalculator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 bitwiseCalculator.c bitwise.h bitwise.c -o BitwiseCalculator-v1.0.0-linux-x86-64
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
  unsigned int andResult = 0;
  unsigned int orResult = 0;
  unsigned int xorResult = 0;
  unsigned int notResult = 0;
    
  puts("Select mode: [1=&], [2=|], [3=^], [4=~]");
  selectMode(&mode);
  
  switch (mode){
    case 1:{
            
      //input
      puts("\n*******AND MODE*******");
      getData(&userInput1, &userInput2);
            
      //process
      andResult = bitwiseAND(userInput1, userInput2);
      
      //output
      printBinary(andResult);
            
      break;
    }
       
    case 2:{
      
      //input
      puts("\n*******OR MODE*******");
      getData(&userInput1, &userInput2);
            
      //process
      orResult = bitwiseOR(userInput1, userInput2);
            
      //output
      printBinary(orResult);
    
      break;
    }
        
    case 3:{
      //input
      puts("\n*******XOR MODE*******");
      getData(&userInput1, &userInput2);
            
      //process
      xorResult = bitwiseXOR(userInput1, userInput2);

            
      //output
      printBinary(xorResult);
    
      break;
    }
        
    case 4:{
      //input
      puts("\n*******NOT MODE*******");
      while (printf("Enter a value to negate: "), scanf("%d", &userInput1) != 1)
        while (getchar() != '\n');
            
      //process
      notResult = bitwiseNOT(userInput1);
            
      //output
      printBinary(notResult);
    
      break;
    }
        
    default:{
      puts("Invalid selection...re-run the program again to continue");
    }
  }

  return 0;
}

/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
#  - Major.Minor.Update/BuildNumber
# Date: 211310NOV25
# Filename: pinGuessingGame.cpp
# Dependency: N/A
# Compile Cmd: g++ -m64 -O1 pinGuessingGame.c -o pinGuessingGame-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv)
{
  int enteredPIN;
  string errorMsg1 = "Incorrect PIN. Try again...\nHINT: System PIN has four digits\n";
  string errorMsg2 = "Invalid entry. Try again...\n";

  cout << "PIN NUMBER GUESSING GAME" << endl;

  do{
    cout << "Enter access PIN to unlock the system: ";
    cin >> enteredPIN;
    
    //check if userInput isn't a four digit pin
    if(enteredPIN < 0000 || enteredPIN > 9999){
        cout << errorMsg2;
    }
    else if(enteredPIN != 1337){
        cout << errorMsg1;
    }
    else{
      cout <<"Access granted!" << endl;
    }
  } while(enteredPIN != 1337);
  
  return 0;
}

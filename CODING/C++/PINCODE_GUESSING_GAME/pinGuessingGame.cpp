
/*######################################################################################
# Dev: cnd.dev
# Program Name: N/A
# Version: 1.0.0
# Date: 211310NOV25
# Filename: pinGuessingGame.cpp
# Dependency: N/A
# Compile Cmd: g++ -m64 -O1 pinGuessingGame.cpp -o pinGuessingGame-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(int argc, char *argv[])
{
  int enteredPIN;
  string errorMsg1 = "Incorrect PIN. Try again...\nHINT: System PIN has four digits\n";
  string errorMsg2 = "Invalid entry. Try again...\n";
  bool accessGranted = false;

  cout << "PIN NUMBER GUESSING GAME" << endl;

  do{
    cout << "Enter access PIN to unlock the system: ";
    cin >> enteredPIN;

    //check immediately if NOT an integer
    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << errorMsg2;
      continue;
    }

    //check userInput against criteria
    if(enteredPIN != 1337){
      cout << errorMsg1;
    }
    //check if userInput isn't a four digit pin
    else if(enteredPIN < 0 || enteredPIN > 9999){
      cout << errorMsg2;
    }
    else{
      cout <<"Access granted!" << endl;
      accessGranted = true;
    }
  } while(!accessGranted);

  return 0;
}

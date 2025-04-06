
/*###################################
# Name: Stephen Razon
# Student ID: 
# Date: 170741SEP24
# Filename: implementation.cpp
# Dependency: clockImplementation.h
###################################*/
​
#include <iostream>
#include "clockImplementation.h"
​
using namespace std;
​
int main()
{
  clockType time1;
  clockType time2(7, 59, 18);
  
  time1.printTime();
  time2.printTime();
  cout << "\n";
  
  time1.setTime(2, 8, 59);
  time1.printTime();
  cout << "\n";
  
  time1.incrementSeconds();
  time1.printTime();
  time2.printTime();
  cout << "\n";
  
  cout << time1.equalTime(time2) << "\n";
  cout << (time1 == time2) << "\n\n";
  
  clockType clock[3];                       //create an array of 3 clockType
  for (int i = 0; i < 3; i++){
    clock[i].printTime();
  }
  
  return 0;
};

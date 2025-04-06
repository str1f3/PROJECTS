
/*#######################################
# Name: Stephen Razon
# Student ID: 
# Date: 170741SEP24
# Filename: clockImplementation.h
# Dependency: clock.h
#######################################*/
​
#include "clock.h"       //this links the clock.h to implementation.h
​
using namespace std;
   
clockType::clockType(){
  selfHours = 0;
  selfMinutes = 0;
  selfSeconds = 0;
}
​
clockType::clockType(int hour, int minute, int second){
  selfHours = hour;
  selfMinutes = minute;
  selfSeconds = second;
}
​
void clockType::setTime(int hour, int minute, int second){
  selfHours = hour;
  selfMinutes = minute;
  selfSeconds = second;
}
​
const void clockType::getTime(int& hour, int& minute, int& second){
  hour = selfHours;
  minute = selfMinutes;
  second = selfSeconds;
}
​
const void clockType::printTime(){
  if (selfHours < 10){
    cout << 0;                 //append leading 0
  }
  cout << selfHours << ":";
  
  if (selfMinutes < 10){
    cout << 0;                 //append leading 0
  }
  cout << selfMinutes << ":";
  
  if (selfSeconds < 10){
    cout << 0;                 //append leading 0
  }
  cout << selfSeconds << "\n";
}
​
void clockType::incrementHours(){
  if (selfHours < 24){
    selfHours++;
  }
  else{
    selfHours = 0;
  }
}
​
void clockType::incrementMinutes(){
  selfMinutes++;
  if (selfMinutes < 60){
    selfMinutes = 0;
    incrementHours();
  }
}
​
void clockType::incrementSeconds(){
  selfSeconds++;
  if (selfSeconds < 60){
    selfSeconds = 0;
    incrementMinutes();
  }
}
​
const bool clockType::equalTime(const clockType& time){
  return (selfHours == time.selfHours) && (selfMinutes == time.selfMinutes) && (selfSeconds == time.selfSeconds);
}
​
bool clockType::operator==(const clockType& time){
  return equalTime(time);
}

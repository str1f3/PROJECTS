/*################################################
# Name: Stephen Razon
# Student ID: 
# Date: 170741SEP24
# Filename: clock.h
# Dependency: N/A
################################################*/

class clockType
{
  private:
    int selfHours, selfMinutes, selfSeconds;
  public:
    //constructors
    clockType();
    clockType(int hour, int minute, int second);
    
    //Functions
    //mutator function (aka setter in Python)
    void setTime(int hour, int minute, int second);
    
    //accessor function (aka getter in Python)
    const void getTime(int& hour, int& minute, int& second);
    
    const void printTime();
    void incrementHours();
    void incrementMinutes();
    void incrementSeconds();
    
    //compares two class objects - overriding/redefinition
    const bool equalTime(const clockType&);
    bool operator==(const clockType&);
};

/*######################################################################################
# Dev: cnd.dev
# Program Name: GeometryCalculator-v1.0.0-linux-x86-64
# Version: 1.0.1
#  - Major.Minor.Update
# Date: 291015JUN25
# Filename: geometryCalculator.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 geometryCalculator.c geometry.h geometry.c -o GeometryCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include <stdio.h>
#include <stdbool.h>
#include "geometry.h"

//mode selector
int modeSelector(void){
    int mode;
    int inputStatus;

    while (1){
        printf("mode: ");
        inputStatus = scanf("%d", &mode);
        //if input is successfully read...clear the rest of the line including newline
        if (inputStatus == 1){
            while (getchar() != '\n');
            return mode;
        } else {
            printf("Invalid input. Select a number.\n");
            while (getchar() != '\n');
        }
    }
}


int main()
{
  int operation;
  int shape;
  bool flag = true;

  while (flag){
    //UI
    puts("\n\nGeometry Calculator v1.0\n");
  
    //main menu
    puts("Choose an operation:");
    puts("1. Area Calculations");
    puts("2. Perimeter/Circumference Calculations");
    puts("3. Surface Area Calculations");
    puts("4. Volume Calculations");
    puts("5. Exit\n\n");
    
    operation = modeSelector();
    
    if (operation == 5){
      printf("Exiting program...\n");
      break;
    }
    
    //clear screen and redisplay options.. future
    puts("\n\nChoose a geometric shape:");
    puts("1. Square");
    puts("2. Rectangle");
    puts("3. Triangle");
    puts("4. Circle\n\n");
    
    shape = modeSelector();
    
    if (operation == 1){
      switch(shape){
        case 1:{
          double side = 0;
      
          printf("\n\nWhat is the measurement of one of the sides? ");
          scanf("%lf", &side);
      
          GEOMETRY square = squareArea(side);
      
          printf("\nFormula: side * side\n");
          printf("Input: %.2lf feet\n", side);
          printf("Calculation: %.2lf * %.2lf\n", side, side);
          printf("Area: %.2lf square feet\n", square.area);
      
          break;
        }
        case 2:{
          double length = 0;
          double width = 0;
      
          printf("Enter Length: ");
          scanf("%lf", &length);
          printf("Enter Width: ");
          scanf("%lf", &width);
      
          GEOMETRY rectangle = rectangleArea(length, width);
      
          printf("\nFormula: length * width\n");
          printf("Inputs: \n Length: %.2lf feet\n Width: %.2lf feet\n", length, width);
          printf("Calculation: %.2lf * %.2lf\n", length, width); 
          printf("Area: %.2lf square feet\n", rectangle.area);
      
          break;
        }
    
        case 3:{
          double base = 0;
          double height = 0;
      
          printf("Enter Base Length: ");
          scanf("%lf", &base);
          printf("Enter Height: ");
          scanf("%lf", &height);
      
          GEOMETRY triangle = triangleArea(base, height);
      
          printf("\nFormula: (base * height) / 2\n");
          printf("Inputs: \n Base Length: %.2lf feet\n Height: %.2lf feet\n", base, height);
          printf("Calculation: (%.2lf * %.2lf) / 2\n", base, height); 
          printf("Area: %.2lf square feet\n", triangle.area);
      
          break;
        }
        case 4:{
          double radius = 0;
          
          printf("Enter Radius: ");
          scanf("%lf", &radius);
          
          GEOMETRY circle = circleArea(radius);
          
          printf("\nFormula: PI * (radius * radius)\n");
          printf("Input: Radius: %.2lf feet\n", radius);
          printf("Calculation: PI * (%.2lf * %.2lf)\n", radius, radius);
          printf("Area: %.2lf square feet\n", circle.area);
          
          break;
        }
        
        default:{
          printf("Invalid Selection! Rerun the program to continue.");
          break;
        }
      }
    }
  }
  return 0;
}

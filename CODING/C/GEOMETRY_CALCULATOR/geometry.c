/*######################################################################################
# Dev: cnd.dev
# Program Name: GeometryCalculator-v1.0.0-linux-x86-64
# Version: 1.0.1
#  - Major.Minor.Update
# Date: 291015JUN25
# Filename: geometry.c
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 geometryCalculator.c geometry.h geometry.c -o GeometryCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#include "geometry.h"

#define PI 3.141592653589793

//AREA: 2D
GEOMETRY squareArea(double sides){
  GEOMETRY square = {0};
  square.area = sides * sides;
  
  return square;
}

GEOMETRY rectangleArea(double length, double width){
  GEOMETRY rectangle = {0};
  rectangle.area = length * width;
  
  return rectangle;
}

GEOMETRY triangleArea(double base, double height){
  GEOMETRY triangle = {0};
  triangle.area = (base * height) / 2.0;
  
  return triangle;
}

GEOMETRY circleArea(double radius){
  GEOMETRY circle = {0};
  circle.area = PI * (radius * radius);
  
  return circle;
}

//PERIMETER: 2D
GEOMETRY squarePerimeter(double sides){
  GEOMETRY square = {0};
  square.perimeter = 4.0 * sides;
  
  return square;
}

GEOMETRY rectanglePerimeter(double length, double width){
  GEOMETRY rectangle = {0};
  rectangle.perimeter = 2.0 * (length + width);
  
  return rectangle;
}

GEOMETRY trianglePerimeter(double sideA, double sideB, double sideC){
  GEOMETRY triangle = {0};
  triangle.perimeter = sideA + sideB + sideC;
  
  return triangle;
}

// Returns the circumference (perimeter) of a circle.
GEOMETRY circleCircumference(double radius){
  GEOMETRY circle = {0};
  circle.perimeter = 2.0 * PI * radius;
  
  return circle;
}

//SURFACE AREA: 3D
GEOMETRY cubeSurfaceArea(double sides){
  GEOMETRY cube = {0};
  cube.surfaceArea = 6.0 * (sides * sides);
  
  return cube;
}

GEOMETRY rectangularPrismSurfaceArea(double length, double width, double height){
  GEOMETRY rectangularPrism = {0};
  rectangularPrism.surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
  
  return rectangularPrism;
}

GEOMETRY sphereSurfaceArea(double radius){
  GEOMETRY sphere = {0};
  sphere.surfaceArea = 4.0 * PI * (radius * radius);
  
  return sphere;
}

GEOMETRY cylinderSurfaceArea(double height, double radius){
  GEOMETRY cylinder = {0};
  cylinder.surfaceArea = 2.0 * PI * radius * (height + radius);
  
  return cylinder;
}

//GEOMETRY PyramidSurfaceArea(...);

//VOLUME: 3D
GEOMETRY cubeVolume(double sides){
  GEOMETRY cube = {0};
  cube.volume = sides * sides * sides;
  
  return cube;
}

GEOMETRY rectangularPrismVolume(double length, double width, double height){
  GEOMETRY rectangularPrism = {0};
  rectangularPrism.volume = length * width * height;
  
  return rectangularPrism;
}

GEOMETRY sphereVolume(double radius){
  GEOMETRY sphere = {0};
  sphere.volume = (4.0/3.0) * PI * (radius * radius * radius);
  
  return sphere;
}

GEOMETRY cylinderVolume(double height, double radius){
  GEOMETRY cylinder = {0};
  cylinder.volume = PI * (radius * radius) * height;
  
  return cylinder;
}

//GEOMETRY PyramidVolume(...);

/*######################################################################################
# Dev: cnd.dev
# Program Name: GeometryCalculator-v1.0.0-linux-x86-64
# Version: 1.0.1
#  - Major.Minor.Update
# Date: 291015JUN25
# Filename: geometry.h
# Dependency: N/A
# Compile Cmd: gcc -m64 -O1 geometryCalculator.c geometry.h geometry.c -o GeometryCalculator-v1.0.0-linux-x86-64
# Synopsis:
#  - Overview: describes what the program does, how it works, and its key components
#  - Technical: ...
######################################################################################*/

#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct{
  double area;
  double perimeter;
  double surfaceArea;
  double volume;

} GEOMETRY;

//AREAS: 2D
GEOMETRY squareArea(double sides);
GEOMETRY rectangleArea(double length, double width);
GEOMETRY triangleArea(double base, double height);
GEOMETRY circleArea(double radius);

//PERIMETER: 2D
GEOMETRY squarePerimeter(double sides);
GEOMETRY rectanglePerimeter(double length, double width);
GEOMETRY trianglePerimeter(double sideA, double sideB, double sideC);
GEOMETRY circleCircumference(double radius);

//SURFACE AREA: 3D
GEOMETRY cubeSurfaceArea(double sides);
GEOMETRY rectangularPrismSurfaceArea(double length, double width, double height);
GEOMETRY sphereSurfaceArea(double radius);
GEOMETRY cylinderSurfaceArea(double height, double radius);
//GEOMETRY PyramidSurfaceArea(...);

//VOLUME: 3D
GEOMETRY cubeVolume(double sides);
GEOMETRY rectangularPrismVolume(double length, double width, double height);
GEOMETRY sphereVolume(double radius);
GEOMETRY cylinderVolume(double height, double radius);
//GEOMETRY PyramidVolume(...);

#endif

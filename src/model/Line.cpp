#include <iostream>
#include <cstdlib>

#include "Line.hpp"

//Default constructor

Line::Line()

{
    x1,y1,x2,y2 = 0;
}

//Constructor

Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;

    this->nbLine++;
}


//Copy constructor

Line::Line(Line& copy)
{
    this->x1 = copy.x1;
    this->x2 = copy.x2;
    this->y1 = copy.y1;
    this->y2 = copy.y2;
}

//SETTERS

void Line::setX1(int x1)
{
    this->x1 = x1;
}

void Line::setX2(int x2)
{
    this->x2 = x2;
}

void Line::setY1(int y1)
{
    this->y1 = y1;
}

void Line::setY2(int y2)
{
    this->y2 = y2;
}

//GETTERS

int Line::getX1()
{
    return this->x1;
}

int Line::getX2()
{
    return this->x2;
}

int Line::getY1()
{
    return this->y1;
}

int Line::getY2()
{
    return this->y2;
}

int Line::getNbLine()
{
    return nbLine;
}

Line Line::getAllCoordinates()
{
    return *this;
}
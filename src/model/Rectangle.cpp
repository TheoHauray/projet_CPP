#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Rectangle.hpp"
#include "Point.hpp"
#include "Forme.hpp"

using namespace std;


Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
    m_label = "Rectangle";
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

Rectangle::Rectangle()
{
    m_label = "Rectangle";
    x1, x2, y1, y2 = 0;
}

Rectangle::Rectangle(const Rectangle& r)
{
    m_label = "Rectangle";
    x1 = r.x1;
    x2= r.x2;
    y1 = r.y1;
    y2 = r.y2;
}

Rectangle& Rectangle::operator=(const Rectangle& r)
{
    m_label = "Rectangle";
    x1 = r.x1;
    x2 = r.x2;
    y1 = r.y1;
    y2 = r.y2;

    return *this;
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(wxDC* dc)
{
    dc->DrawRectangle(x1, y1, x2-x1, y2-y1);
}

void Rectangle::setX1(int x1)
{
    this->x1 = x1;
}

void Rectangle::setX2(int x2)
{
    this->x2 = x2;
}

void Rectangle::setY1(int y1)
{
    this->y1 = y1;
}

void Rectangle::setY2(int y2)
{
    this->y2 = y2;
}

bool Rectangle::isInside(int x, int y)
{
    return ((x >= x1 && x <= x2) && (y >= y1 && y <= y2));
}   
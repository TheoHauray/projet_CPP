#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Point.hpp"

using namespace std;

//---------------------------------------------
//Constructeur / destructeur

Point::Point()
{
    m_label = "Point";
    m_x = 0;
    m_y = 0;
}

Point::Point(int xy)
{
    m_label = "Point";
    m_x = xy;
    m_y = xy;

}

Point::Point(int x, int y)
{
    m_label = "Point";
    m_x = x;
    m_y = y;

}

Point::Point(const Point& point)
{
    m_label = "Point";
    m_x = point.m_x;
    m_y = point.m_y;

}

Point& Point::operator=(const Point& point)
{
    m_x = point.m_x;
    m_y = point.m_y;


    return *this;
}

Point::~Point()
{

}   

//---------------------------------------------
//Méthodes 

void Point::display() const
{   
    cout << "Coordonnées du point : " << endl;
    cout << "x : " << m_x << ", y : " << m_y << endl;
}


void Point::move(int dX, int dY)
{
    m_x = dX;
    m_y = dY;
}

bool Point::XEgalY() const
{
    if(m_x == m_y)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int Point::getX() const
{
    return m_x;
}

int Point::getY() const
{
    return m_y;
}

void Point::setX(int x)
{
    m_x = x;
}

void Point::setY(int y)
{
    m_y = y;
}

float Point::distance(const Point& point) const
{
    return cbrt((point.getX() - m_x)*2 + (point.getY() - m_y)*2);
}


void Point::draw(wxDC* dc)
{
    dc->DrawPoint(m_x, m_y);
}

bool Point::isInside(int x, int y)
{
<<<<<<< HEAD
    return (m_x == x && m_y == y);
=======
    return false;
>>>>>>> 4675f87dfa37c275b7148934e8eb3663c89a8000
}
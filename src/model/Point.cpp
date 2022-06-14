#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Point.hpp"

using namespace std;

//---------------------------------------------
//Constructeur / destructeur

Point::Point()
{
    m_x = 0;
    m_y = 0;

    cout << "appel constructeur Point (vide): " << __func__ << "@" << this << endl;
}

Point::Point(int xy)
{
    m_x = xy;
    m_y = xy;

    cout << "appel constructeur Point (xy): " << __func__ <<  "@" << this << endl;
}

Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;

    cout << "appel constructeur Point (x, y): " << __func__ << "@" << this << endl;
}

Point::Point(const Point& point)
{
    m_x = point.m_x;
    m_y = point.m_y;

    cout << "appel constructeur Point (point): " << __func__ << "@" << this << endl;
}

Point& Point::operator=(const Point& point)
{
    m_x = point.m_x;
    m_y = point.m_y;

    cout << "Point (affectation)" << endl;

    return *this;
}

Point::~Point()
{
    m_PointCount--;

    cout << "appel destructeur Point: " << __func__ << endl;
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

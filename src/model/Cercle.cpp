#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Cercle.hpp"
#include "Point.hpp"
#include "Forme.hpp"

using namespace std;

//---------------------------------------------
//Constructeur / destructeur


Cercle::Cercle(int x, int y, int radius)
{
    m_radius = radius;
    x1 = x;
    y1 = x;
}

Cercle::Cercle()
{
    m_radius = 0;
    x1 = 0;
    y1 = 0;
}

Cercle::~Cercle()
{
}

Cercle::Cercle(const Cercle& c)
{
    m_radius = c.m_radius;
}

Cercle& Cercle::operator=(const Cercle& c)
{
    m_label = c.m_label;
    m_radius = c.m_radius;

    return *this;
}

void Cercle::draw(wxClientDC* dc)
{
    dc->DrawCircle(x1,y1, m_radius);
}

void Cercle::setX1(int x1)
{
    this->x1 = x1;
}
void Cercle::setY1(int y1)
{
    this->y1 = y1;
}
void Cercle::setRadius(int radius)
{
    this->m_radius = radius;
}
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


Cercle::Cercle(int x, int y, int radius, const std::string label)
{
    m_radius = radius;

    Point center(x, y);

    Forme(label, center);
}

Cercle::Cercle()
: Forme()
{
    m_radius = 0;
}

Cercle::~Cercle()
{
}

Cercle::Cercle(const Cercle& c)
{
    m_radius = c.m_radius;

    Point center(c.center);

    Forme(*c.m_label, center);
}

Cercle& Cercle::operator=(const Cercle& c)
{
    center = c.center;
    m_label = c.m_label;
    m_radius = c.m_radius;

    return *this;
}

void Cercle::draw(wxClientDC* dc)
{
    
}

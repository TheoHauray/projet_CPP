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
}

Cercle::Cercle()
{
    m_radius = 0;
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
    
}

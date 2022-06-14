#include "Dessin.hpp"
#include "Forme.hpp"
#include <vector>

Dessin::Dessin()
{}

Dessin::Dessin(const Dessin& dessin)
{
    this.dessins = dessin->dessins;
}

Dessin& Dessin::operator=(const Dessin& dessin)
{
    this.dessins = dessin->dessins;
    return this;
}

Dessin::~Dessin()
{}


Dessin::getVector()
{ 
    return dessins; 
}

Dessin::addVector(Forme forme)
{
    dessins.puck_back(forme);
}
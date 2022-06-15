#include "Dessin.hpp"
#include "Forme.hpp"
#include <vector>

using namespace std;

Dessin::Dessin()
{

}

Dessin::Dessin(const Dessin& dessin)
{
    this->dessins = dessin.dessins;
}

Dessin& Dessin::operator=(const Dessin& dessin)
{
    this->dessins = dessin.dessins;
    return *this;
}

Dessin::~Dessin()
{

}


std::vector<Forme*>& Dessin::getVector()
{ 
    return dessins; 
}


void Dessin::addVector(Forme* forme)
{
    this->dessins.push_back(forme);
}

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "Controler.hpp"

#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"
#include "../model/Dessin.hpp"
#include "../model/Line.hpp"


using namespace std;

//---------------------------------------------
//Constructeur / destructeur


Controler::Controler(MyControlPanel& myControlPanel, MyDrawingPanel& myDrawingPanel, MyFrame& myFrame)
{
    this->myControlPanel = &myControlPanel;
    this->myDrawingPanel = &myDrawingPanel;
    this->myFrame = &myFrame;
    this->clic = 0;
    Dessin dessin;
    this->dessin = new Dessin();
}

Controler::Controler()
{
    this->myControlPanel = NULL;
    this->myDrawingPanel = NULL;
    this->myFrame = NULL;
}

Controler::~Controler()
{
    
}



bool Controler::getBoolLine()
{
    return this->myFrame->GetControlPanel()->GetRadioButtonLineValue() ;
}

void Controler::setCoordinatesLine(int x1, int y1, int x2, int y2)
{
    Line* line = new Line;

    line->setX1(x1);
    line->setY1(y1);
    line->setX2(x2);
    line->setY2(y2);
    this->addForm(line);
}

void Controler::setCoordinatesLineEnd(int x, int y, Line* line)
{
    line->setX2(x);
    line->setY2(y);

    this->addForm(line);


}

int Controler::getClic()
{
    return this->clic;
}

void Controler::setClic(int x)
{
    this->clic = x;
}

Dessin& Controler::getDessin()
{
    return *dessin;
}

void Controler::addForm(Forme *forme)
{
    this->dessin->addVector(forme);
}

void Controler::drawForms(wxClientDC* dc)
{
    for(int i = 0; i < dessin->getVector().size(); i++)
    {
        dessin->getVector().at(i)->draw(dc);
    }
}
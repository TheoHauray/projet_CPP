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
#include "../model/Cercle.hpp"
#include "../model/Rectangle.hpp"



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

bool Controler::getBoolCircle()
{
    return this->myFrame->GetControlPanel()->GetRadioButtonCircleValue() ;
}

bool Controler::getBoolRectangle()
{
    return this->myFrame->GetControlPanel()->GetRadioButtonRectangleValue();
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

void Controler::setCoordinatesCircle(int x1, int y1, int radius)
{
    Cercle* cercle = new Cercle;

    cercle->setX1(x1);
    cercle->setY1(y1);
    cercle->setRadius(radius);


    this->addForm(cercle);
}

void Controler::setCoordinatesRectangle(int x1, int y1, int x2, int y2)
{
    Rectangle* rectangle = new Rectangle;

    rectangle->setX1(x1);
    rectangle->setX2(x2);
    rectangle->setY1(y1);
    rectangle->setY2(y2);

    this->addForm(rectangle);
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

bool Controler::saveImage(wxString fileName, int height, int width)
{
    bool isImageSaved = dessin->saveImage(fileName, height, width);
    return isImageSaved;
}

void Controler::changeBackgroundColor()
{

}
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
    this->dessin = dessin;
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

void Controler::setCoordinatesLine(int x, int y)
{
    Line* lineFinal = new Line;

    if(this->clic==0){
        lineFinal->setX1(x);
        lineFinal->setY1(y);
    }
    else{
        lineFinal->setX2(x);
        lineFinal->setY2(y);

        this->addForm(lineFinal);
    }
}

Line Controler::getLine()
{
    return line;
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
    return dessin;
}

void Controler::addForm(Forme *forme)
{
    this->dessin.addVector(forme);
}
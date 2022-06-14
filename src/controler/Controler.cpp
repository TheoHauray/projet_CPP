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
    Line *line = new Line();

    if(this->clic==0){
        line.setX1(x);
        line.setY1(y);
    }
    else{
        line.setX2(x);
        line.setY2(y);
    }
}

int Controler::getClic()
{
    return this->clic;
}

void Controler::setClic(int x)
{
    this->clic = x;
}

Dessin Controler::getDessin()
{
    return this->dessin;
}

void Controler::drawLine()
{
    this->dessin.addVector(this->line);
}
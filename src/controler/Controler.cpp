#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <wx/colour.h>

#include "Controler.hpp"

#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"
#include "../model/Dessin.hpp"
#include "../model/Line.hpp"
#include "../model/Cercle.hpp"
#include "../model/Rectangle.hpp"
#include "../model/Point.hpp"
#include "../model/Forme.hpp"



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
    this->selectedForm = NULL;
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

bool Controler::getBoolPen()
{
    return this->myFrame->GetControlPanel()->GetRadioButtonPenValue();
}

bool Controler::getBoolSelection()
{
    return this->myFrame->GetControlPanel()->GetRadioButtonSelection();
}

wxColour Controler::getColourPickedFill()
{
    return this->myFrame->GetControlPanel()->getColourPickerColorFill();
}

wxColour Controler::getColourPickedOutline()
{
    return this->myFrame->GetControlPanel()->getColourPickerColorOutline();
}

int Controler::getSliderValue()
{
    return this->myFrame->GetControlPanel()->getSliderValue();
}

unsigned int Controler::getSliderTransparencyValue()
{
    return this->myFrame->GetControlPanel()->getSliderTransparencyValue();
}



void Controler::setCoordinatesLine(int x1, int y1, int x2, int y2, wxColour colorFill, wxColour colorOutline, int width)
{
    Line* line = new Line;

    line->setX1(x1);
    line->setY1(y1);
    line->setX2(x2);
    line->setY2(y2);
    line->setColourContour(colorOutline, width);
    line->setColourFill(colorFill);
    this->addForm(line);
}

void Controler::setCoordinatesCircle(int x1, int y1, int radius, wxColour colorFill, wxColour colorOutline, int width)
{
    Cercle* cercle = new Cercle;

    cercle->setX1(x1);
    cercle->setY1(y1);
    cercle->setRadius(radius);
    cercle->setColourContour(colorOutline, width);
    cercle->setColourFill(colorFill);


    this->addForm(cercle);
}

void Controler::setCoordinatesRectangle(int x1, int y1, int x2, int y2, wxColour colorFill, wxColour colorOutline, int width)
{
    Rectangle* rectangle = new Rectangle;

    rectangle->setX1(x1);
    rectangle->setX2(x2);
    rectangle->setY1(y1);
    rectangle->setY2(y2);
    rectangle->setColourContour(colorOutline, width);
    rectangle->setColourFill(colorFill);

    this->addForm(rectangle);
}

void Controler::setCoordinatesPoint(int x1, int y1, wxColour colorFill, wxColour colorOutline, int width)
{
    Point* point = new Point;

    point->setX(x1);
    point->setY(y1);
    point->setColourContour(colorOutline, width);
    point->setColourFill(colorFill);

    this->addForm(point);
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
        dc->SetBrush(dessin->getVector().at(i)->getBrushFill());
        dc->SetPen(dessin->getVector().at(i)->getPenOutline());

        dessin->getVector().at(i)->draw(dc);
    }
}

bool Controler::saveImage(wxString fileName, int height, int width)
{
    bool isImageSaved = dessin->saveImage(fileName, height, width, backGroundColor);
    return isImageSaved;
}


void Controler::setBackgroundColor()
{
    backGroundColor = myControlPanel->getColourPickerColorBackground();
    myDrawingPanel->SetBackgroundColour(backGroundColor);
}


void Controler::isInside(int x, int y)
{
    bool testIsInside = false;

    for(int i = dessin->getVector().size()-1; i >= 0 && testIsInside == false; i--)
    {
        testIsInside = dessin->getVector().at(i)->isInside(x, y);

        if(testIsInside)
        {
            selectedForm = dessin->getVector().at(i);
        }
    }
}

void Controler::changeColorsSelectedForm()
{
    if(selectedForm != NULL)
    {
        selectedForm->setColourContour(getColourPickedOutline(), 5);
        selectedForm->setColourFill(getColourPickedFill());
    }
}



void Controler::eraseAll()
{
    delete dessin;
    dessin = new Dessin();
}

void Controler::popLastDrawing()
{
    dessin->rmVector();
}

void Controler::redoLastDrawing()
{
    dessin->redoVector();
}

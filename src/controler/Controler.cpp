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

void Controler::setCoordinatesLine(int x1, int y1, int x2, int y2, wxColour colorFill, wxColour colorOutline)
{
    Line* line = new Line;

    line->setX1(x1);
    line->setY1(y1);
    line->setX2(x2);
    line->setY2(y2);
    line->setColourContour(colorOutline);
    line->setColourFill(colorFill);
    this->addForm(line);
}

void Controler::setCoordinatesCircle(int x1, int y1, int radius, wxColour colorFill, wxColour colorOutline)
{
    Cercle* cercle = new Cercle;

    cercle->setX1(x1);
    cercle->setY1(y1);
    cercle->setRadius(radius);
    cercle->setColourContour(colorOutline);
    cercle->setColourFill(colorFill);


    this->addForm(cercle);
}

void Controler::setCoordinatesRectangle(int x1, int y1, int x2, int y2, wxColour colorFill, wxColour colorOutline)
{
    Rectangle* rectangle = new Rectangle;

    rectangle->setX1(x1);
    rectangle->setX2(x2);
    rectangle->setY1(y1);
    rectangle->setY2(y2);
    rectangle->setColourContour(colorOutline);
    rectangle->setColourFill(colorFill);

    this->addForm(rectangle);
}

void Controler::setCoordinatesPoint(int x1, int y1, wxColour colorFill, wxColour colorOutline)
{
    Point* point = new Point;

    point->setX(x1);
    point->setY(y1);
    point->setColourContour(colorOutline);
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
    //dc->SetPen(colorBorder);
    //dc->SetBrush(wxColour(colorToFill));
    for(int i = 0; i < dessin->getVector().size(); i++)
    {
        dc->SetBrush(dessin->getVector().at(i)->getColourFill());
        dc->SetPen(dessin->getVector().at(i)->getColourPen());
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

/*
void Controler::setFormColor(wxColour colorPicked)
{
    colorToFill = colorPicked;
}

void Controler::setBorderColor(wxColour colorPicked)
{
    colorBorder = colorPicked;
}
*/

void Controler::isInside(int x, int y)
{
    for(int i = dessin->getVector().size()-1; i >= 0; i--)
    {
        bool testIsInside = dessin->getVector().at(i)->isInside(x, y);

        if(testIsInside)
        {
            wxMessageBox("Selected");
            selectedForm = dessin->getVector().at(i);
            selectedForm->setColourContour(*wxRED);
        }
    }
}

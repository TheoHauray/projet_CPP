// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <string>

#include "Forme.hpp"
#include "Point.hpp"

using namespace std;

Forme::Forme()
{
    m_label = " ";
    isSelected = false;
}

Forme::Forme(const std::string& s)
{
    m_label = s;
    isSelected = false;
}

Forme::Forme(const Forme& forme)
{
   m_label = forme.getLabel();
   isSelected = false;
}

Forme& Forme::operator=(const Forme& forme)
{
    m_label = forme.getLabel();
    isSelected = false;
    return *this;
}

Forme::~Forme(){   
}

void Forme::setLabel(const::string& s)
{
    m_label = s;
}

string Forme::getLabel() const
{
    return m_label;
}

void Forme::setColourFill(wxColour color)
{
    brushFill.SetColour(color);
}

void Forme::setColourContour(wxColour color, int width)
{
    penOutline.SetColour(color);
    penOutline.SetWidth(width);
}

/*
wxColour Forme::getColourFill()
{
    return colourFill;
}

wxColour Forme::getColourPen()
{
    return colourPen;
}
*/

wxBrush Forme::getBrushFill()
{
    return brushFill;
}

wxPen Forme::getPenOutline()
{
    return penOutline;
}

wxPen Forme::getPrevPen()
{
    return prevPen;
}

void Forme::setPrevPen(wxPen penOutline)
{
    prevPen = penOutline;
}

bool Forme::getIsSelected()
{
    return isSelected;
}

void Forme::setIsSelected(bool val)
{
    isSelected = val;
}
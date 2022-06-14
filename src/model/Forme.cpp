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
: center(0, 0)
{
    m_label = new string("");
}

Forme::Forme(const std::string& s, const Point& point)
: center(point)
{
    m_label = new string(s);
}

Forme::Forme(const Forme& forme)
: center(forme.center)
{
    m_label = new string(forme.getLabel());
}

Forme& Forme::operator=(const Forme& forme)
{
    center = forme.center;
    m_label = new string(forme.getLabel());

    return *this;
}

Forme::~Forme(){   
    delete m_label;
}

void Forme::setLabel(const::string& s)
{
    *m_label = s;
}

string Forme::getLabel() const
{
    return *m_label;
}

void Forme::setCenter(const::Point& point)
{
    center = point;
}

Point Forme::getCenter() const
{
    return center;
}
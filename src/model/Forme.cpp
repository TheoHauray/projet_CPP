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
: m_label(" ")
{
    
}

Forme::Forme(const std::string& s)
: m_label(s)
{
    
}

Forme::Forme(const Forme& forme)
: m_label(forme.getLabel())
{
   
}

Forme& Forme::operator=(const Forme& forme)
{
    m_label = forme.getLabel();
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




// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "Forme.hpp"

Forme::Forme()
{
    xPos = 0;
    yPos = 0;
}

Forme::Forme(const Point& point)
{
    xPos = x;
    yPos = y;
}

Forme::Forme(const Forme& forme)
center
{
    xPos = forme.xPos;
    yPos = forme.yPos;
}

Forme& Forme::operator=(const Forme& f)
{
    xPos = f.xPos;
    yPos = f.yPos;

    return *this;
}

Forme::~Forme(){    
}
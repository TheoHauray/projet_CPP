#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <wx/dcsvg.h>
#include <wx/brush.h>


#include "Dessin.hpp"
#include "Forme.hpp"
#include <vector>

using namespace std;

Dessin::Dessin()
{

}

Dessin::Dessin(const Dessin& dessin)
{
    this->dessins = dessin.dessins;
}

Dessin& Dessin::operator=(const Dessin& dessin)
{
    this->dessins = dessin.dessins;
    return *this;
}

Dessin::~Dessin()
{

}


std::vector<Forme*>& Dessin::getVector()
{ 
    return dessins; 
}

void Dessin::setVector(std::vector<Forme*> forme)
{
    dessins = forme;
}


void Dessin::addVector(Forme* forme)
{
    this->dessins.push_back(forme);
}
void Dessin::rmVector()
{
    if(dessins.size()>0)
    {
    dessinsRedo.push_back(dessins.at(dessins.size()-1));
    dessins.pop_back();
    }
}

void Dessin::redoVector()
{
    if(dessinsRedo.size()>0)
    {
        dessins.push_back(dessinsRedo.at(dessinsRedo.size()-1));
        dessinsRedo.pop_back();
    }
}


bool Dessin::saveImage(wxString fileName, int height, int width, wxColour color)
{
    bool isFileSaved = true;

    wxSVGFileDC dcFile(fileName, width, height);
    dcFile.SetBrush(color);
    dcFile.DrawRectangle(0, 0, width, height);
    dcFile.SetBrush(*wxWHITE_BRUSH);


    for(int i = 0; i < dessins.size(); i++)
    {
        dcFile.SetBrush(dessins[i]->getBrushFill());
        dcFile.SetPen(dessins[i]->getPenOutline());
        dessins[i]->draw(&dcFile);
    }

   return true;
}

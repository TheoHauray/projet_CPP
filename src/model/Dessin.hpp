#ifndef __DESSIN_H__
#define __DESSIN_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "Forme.hpp"
#include <vector>

class Dessin
{

public:

    Dessin();
    Dessin(const Dessin& dessin);
    Dessin& operator=(const Dessin& dessin);
    ~Dessin();

    std::vector<Forme*>& getVector();
    void addVector(Forme* forme);
    bool saveImage(wxString fileName, int height, int width);


private:

    std::vector<Forme*> dessins;

};

#endif //__DESSIN_H__
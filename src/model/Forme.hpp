#ifndef __FORME_H__
#define __FORME_H__

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "Point.hpp"


//------------------------------------------------------------------------
class Forme:
//------------------------------------------------------------------------
{
    protected:
        Point center;

    public:
        Forme();
        Forme(const Point& point);
        Forme(const Forme& f1);
        Forme& operator=(const Forme& f1);

        virtual ~Forme(); 
};

#endif //__FORME_H__
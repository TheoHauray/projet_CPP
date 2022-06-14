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
#include <string>

#include "Point.hpp"


//------------------------------------------------------------------------
class Forme:
//------------------------------------------------------------------------
{
    protected:
        Point center;
        std::string* m_label;

    public:
        Forme();
        Forme(const std::string& s, const Point& point);
        Forme(const Forme& forme);
        Forme& operator=(const Forme& forme);
        virtual ~Forme(); 

        void setLabel(const std::string& s); 
	    std::string getLabel() const;


        void setPoint(const std::string& s); 
	    Point getPoint() const;
};

#endif //__FORME_H__
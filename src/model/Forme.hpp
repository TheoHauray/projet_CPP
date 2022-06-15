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


//------------------------------------------------------------------------
class Forme
//------------------------------------------------------------------------
{
    protected:
        std::string m_label;

    public:
        Forme();
        Forme(const std::string& s);
        Forme(const Forme& forme);
        Forme& operator=(const Forme& forme);
        virtual ~Forme(); 

        void setLabel(const std::string& s); 
	    std::string getLabel() const;

        virtual void draw(wxClientDC* dc) = 0;
};

#endif //__FORME_H__
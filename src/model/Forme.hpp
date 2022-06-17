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

        wxBrush brushFill;
        wxPen penOutline;
        wxPen prevPen;
        bool isSelected;

    public:
        Forme();
        Forme(const std::string& s);
        Forme(const Forme& forme);
        Forme& operator=(const Forme& forme);
        virtual ~Forme(); 

        void setLabel(const std::string& s); 
        void setColourContour(wxColour color, int width);
        void setColourFill(wxColour color);


        /*
        wxColour getColourFill();
        wxColour getColourPen();
        */
        void setPrevPen(wxPen penOutline);
        wxPen getPrevPen();
        wxPen getPenOutline();
        wxBrush getBrushFill();
	    std::string getLabel() const;
        bool getIsSelected();
        void setIsSelected(bool val);

        virtual void draw(wxDC* dc) = 0;
        virtual bool isInside(int x, int y) = 0;
        virtual void move(int x, int y) = 0;
};

#endif //__FORME_H__
#ifndef __CONTROLER_H__
#define __CONTROLER_H__


#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"
#include "../model/Dessin.hpp"
#include "../model/Line.hpp"
#include "../model/Cercle.hpp"
#include "../model/Rectangle.hpp"
#include "../model/Point.hpp"

#include <wx/colour.h>

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



class MyControlPanel ; 
class MyDrawingPanel ; 
class MyFrame ; 

//------------------------------------------------------------------------
class Controler
//------------------------------------------------------------------------
{
    public:
        Controler(MyControlPanel& myControlPanel, MyDrawingPanel& myDrawingPanel, MyFrame& myFrame);
        Controler();
        virtual ~Controler();

        bool getBoolLine();
        bool getBoolCircle();
        bool getBoolRectangle();
        bool getBoolPen();
        bool getBoolSelection();
        wxColour getColourPickedFill();
        wxColour getColourPickedOutline();
        int getSliderValue();
        unsigned int getSliderTransparencyValue();

        void eraseAll();
        void popLastDrawing();
        void redoLastDrawing();

        void setCoordinatesLine(int x1, int y1, int x2, int y2, wxColour colorFill, wxColour colorOutline, int width);
        void setCoordinatesCircle(int x1, int x2, int radius, wxColour colorFill, wxColour colorOutline, int width);
        void setCoordinatesRectangle(int x1, int y1, int width, int height, wxColour colorFill, wxColour colorOutline, int widthTrait);
        void setCoordinatesPoint(int x1, int y1, wxColour colorFill, wxColour colorOutline, int width);

        int getClic();
        void setClic(int x);

        Dessin& getDessin();
        void addForm(Forme* forme);
        void drawForms(wxClientDC* dc);
        bool saveImage(wxString fileName, int heigth, int width);

        void setBackgroundColor();
        void setFormColor(wxColour colorPicked);
        void setBorderColor(wxColour colorPicked);
        void isInside(int x, int y);
        void changeColorsSelectedForm(int x, int y);
        void moveForm(int x, int y);
        
    private:
        MyControlPanel *myControlPanel;
        MyDrawingPanel *myDrawingPanel;
        MyFrame *myFrame;
        int clic;
        Dessin *dessin;

        Line* tempLine;
        Cercle* tempCircle;
        Forme* selectedForm;
        wxColour colorToFill = *wxWHITE;
        wxColour colorBorder = *wxBLACK;
        wxColour backGroundColor = *wxWHITE;

};

#endif //__CONTROLER_H__
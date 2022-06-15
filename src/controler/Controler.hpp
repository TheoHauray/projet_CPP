#ifndef __CONTROLER_H__
#define __CONTROLER_H__


#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"
#include "../model/Dessin.hpp"
#include "../model/Line.hpp"

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
        void setCoordinatesLine(int x1, int y1, int x2, int y2);
        void setCoordinatesLineEnd(int x, int y, Line* line);
        int getClic();
        void setClic(int x);

        Dessin& getDessin();
        void addForm(Forme* forme);
        void drawForms(wxClientDC* dc);


    private:
        MyControlPanel *myControlPanel;
        MyDrawingPanel *myDrawingPanel;
        MyFrame *myFrame;
        int clic;
        Dessin *dessin;

        Line* tempLine;
};

#endif //__CONTROLER_H__
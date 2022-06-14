#ifndef __CONTROLER_H__
#define __CONTROLER_H__


#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"

//------------------------------------------------------------------------
class Controler
//------------------------------------------------------------------------
{
    private:
        MyControlPanel *myControlPanel;
        MyDrawingPanel *myDrawingPanel;
        MyFrame *myFrame;

    public:
        Controler(MyControlPanel *myControlPanel, MyDrawingPanel *myDrawingPanel, MyFrame *myFrame);
        Controler();

        virtual ~Controler();
};

#endif //__CONTROLER_H__
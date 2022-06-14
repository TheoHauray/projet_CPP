#ifndef __MYCONTROLER_H__
#define __MYCONTROLER_H__

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "../view/MyControlPanel.hpp"
#include "../view/MyDrawingPanel.hpp"
#include "../view/MyFrame.hpp"

//------------------------------------------------------------------------
class Controler
//------------------------------------------------------------------------
{
    private:
        MyControlPanel myControlPanel;
        MyDrawingPanel myDrawingPanel;
        MyFrame myFrame;

    public:
        
};

#endif //__MYAPP_H__
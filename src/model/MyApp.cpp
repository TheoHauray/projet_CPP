// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "../view/MyFrame.hpp"

//------------------------------------------------------------------------
// Some constants
//------------------------------------------------------------------------
#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500 
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50
#define APP_NAME "M1102 Skeleton 1.0"


//------------------------------------------------------------------------
class MyApp: public wxApp
//------------------------------------------------------------------------
{
    virtual bool OnInit() ;
};

IMPLEMENT_APP(MyApp) // macro that contains the main() function


//------------------------------------------------------------------------
bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
	frame->Show(true) ;
	SetTopWindow(frame) ;
	return true ;
}
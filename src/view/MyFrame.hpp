#ifndef __MYFRAME_H__
#define __MYFRAME_H__


#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyControlPanel.hpp"
#include "MyDrawingPanel.hpp"
#include "../controler/Controler.hpp"

class Controler ; 
class MyControlPanel ;
class MyDrawingPanel ;


//------------------------------------------------------------------------
class MyFrame: public wxFrame
//------------------------------------------------------------------------
{

protected:
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& WXUNUSED(event) ) ;
	void OnSaveFile(wxCommandEvent & WXUNUSED(event)) ;
	void OnClose(wxCloseEvent& event) ;
	void OnSize(wxSizeEvent &event) ;

	MyControlPanel *m_controlPanel; // the panel with controls
	MyDrawingPanel *m_drawingPanel; // the panel in which we draw
	Controler *controler;

public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
	void RefreshDrawing();
	//void setControler(Controler *controler) ;

} ;

#endif //__MYFRAME_H__
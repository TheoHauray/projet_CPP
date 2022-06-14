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

//------------------------------------------------------------------------
class MyFrame: public wxFrame
//------------------------------------------------------------------------
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	MyControlPanel* GetControlPanel(){return m_controlPanel ;} ;
	void RefreshDrawing(){m_drawingPanel->Refresh() ;} ;
	void setControler(Controler *controler) ;

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
} ;

#endif //__MYFRAME_H__
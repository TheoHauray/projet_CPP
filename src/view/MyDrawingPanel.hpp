#ifndef __MYDRAWINGPANEL_H__
#define __MYDRAWINGPANEL_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <wx/brush.h>

#include "../controler/Controler.hpp"

class Controler ; 

class MyDrawingPanel: public wxPanel
{


private:
	void OnMouseMove(wxMouseEvent &event) ;
	void OnMouseLeftDown(wxMouseEvent &event) ;
	void OnMouseLeftUp(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event) ;
	
	wxPoint m_mousePoint ;
	wxPoint m_onePoint ;
	Controler *controler;
	bool dragging;
	
public:
	MyDrawingPanel( wxWindow *parent ) ;
	void OpenFile(wxString fileName) ;
	void SaveFile(wxString fileName) ;
	void setControler(Controler *controler) ;
	int clic;

	void setBackgroundColor();
};

#endif // __MYDRAWINGPANEL_H__
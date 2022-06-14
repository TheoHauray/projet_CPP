// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyControlPanel.hpp"
#include "MyFrame.hpp"
#include "../model/Line.hpp"

#include "Constant.hpp"
#include "../controler/Controler.hpp"


//------------------------------------------------------------------------
// Some enums for widgets
//------------------------------------------------------------------------
enum
{
	ID_QUIT = 1,
	ID_ABOUT,
	ID_LOAD,
	ID_SAVE,
	ID_BUTTON1,
	ID_SLIDER1,
	ID_CHECKBOX1,
	ID_CHECKBOX2,

	ID_RADIOBUTTONLINE,
	ID_RADIOBUTTONCERCLE

};

//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{

//	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ; trouvé perdu au milieu de nul part jsp ou ça va


	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(*wxLIGHT_GREY) ;

	y = WIDGET_Y0 ;
	m_button = new wxButton(this, ID_BUTTON1, wxT("Click me"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_BUTTON1) ;
	
	y+= WIDGET_Y_STEP ;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Radius"), wxPoint(10, y)) ;
	
	y+= 15 ;
	m_slider = new wxSlider(this, ID_SLIDER1, 10, 2, 100, wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;	
	
	y+= WIDGET_Y_STEP ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;	


//Ajout de boutons radio pour test, voir à quelle méthode ils peuvent être liés

	y+= 2* WIDGET_Y_STEP ;
	m_radioButtonLine = new wxRadioButton(this, ID_RADIOBUTTONLINE, "Ligne", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, 	ID_RADIOBUTTONLINE);
		y+= WIDGET_Y_STEP ;
	m_radioButtonCircle = new wxRadioButton(this, ID_RADIOBUTTONCERCLE, "Cercle", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONCERCLE);
		y+= WIDGET_Y_STEP ;

}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
//------------------------------------------------------------------------
{
//	char* s = GetCString() ;
//	wxMessageBox(wxString::FromAscii(s)) ; // call a C function located in the sample.cp module
//	free(s) ;
	wxMessageBox(wxT("You just pressed the button!")) ;
}

void MyControlPanel::OnCheckBoxLine(wxCommandEvent &event)

{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;

}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::setControler(Controler *controler)
//------------------------------------------------------------------------
{
	this->controler = controler;
}
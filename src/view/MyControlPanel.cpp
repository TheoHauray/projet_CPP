// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <wx/clrpicker.h>
#include <wx/colour.h>

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
	
	ID_SLIDER1,
	ID_CHECKBOX1,
	ID_CHECKBOX2,

	ID_RADIOBUTTONLINE,
	ID_RADIOBUTTONCERCLE,
	ID_RADIOBUTTONRECTANGLE,
	ID_RADIOBUTTONSELECTION,

	ID_RADIOBUTTONSELECTCOLOR,
	ID_RADIOBUTTONSELECTPOSITION,

	ID_RADIOBUTTONPEN,
	ID_COLORPICKERFILL,
	ID_COLORPICKEROUTLINE,
	ID_COLORPICKERBACKGROUND,

	ID_SLIDERWIDTH,
	ID_SLIDERTRANSPARENCY,

	ID_DELETEALLBUTTON,
	ID_UNDOBUTTON,
	ID_REDOBUTTON

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
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;	


	//Radio button pour dessiner

	y+= WIDGET_Y_STEP ;
    m_radioButtonLine = new wxRadioButton(this, ID_RADIOBUTTONLINE, "Ligne", wxPoint(10, y), wxSize(100,20), wxRB_GROUP) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, 	ID_RADIOBUTTONLINE);
	y+= WIDGET_Y_STEP ;
	m_radioButtonCircle = new wxRadioButton(this, ID_RADIOBUTTONCERCLE, "Cercle", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONCERCLE);
	y+= WIDGET_Y_STEP ;
	m_radioButtonRectangle = new wxRadioButton(this, ID_RADIOBUTTONRECTANGLE, "Rectangle", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONRECTANGLE);
	y+= WIDGET_Y_STEP ;
	m_radioButtonPen = new wxRadioButton(this, ID_RADIOBUTTONPEN, "Pen", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONPEN);
	y+= WIDGET_Y_STEP ;
	m_radioButtonSelection = new wxRadioButton(this, ID_RADIOBUTTONSELECTION, "Selection", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONSELECTION);

	y+= 25 ;
	m_radioButtonSelectColor = new wxRadioButton(this, ID_RADIOBUTTONSELECTCOLOR, "Color", wxPoint(20, y), wxSize(100,20), wxRB_GROUP) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONSELECTCOLOR);
	y+= 25 ;
	m_radioButtonSelectPosition = new wxRadioButton(this, ID_RADIOBUTTONSELECTPOSITION, "Position", wxPoint(20, y), wxSize(100,20)) ;
	Bind(wxEVT_RADIOBUTTON, &MyControlPanel::OnCheckBox, this, ID_RADIOBUTTONSELECTPOSITION);

	//Radio button pour sélectionner les couleurs

	y+=WIDGET_Y_STEP;
	wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Fill color"), wxPoint(10, y)) ;
	y+= 20;
	m_colourPickerFill = new wxColourPickerCtrl(this, ID_COLORPICKERFILL, *wxWHITE, wxPoint(10, y), wxDefaultSize, wxCLRP_DEFAULT_STYLE, wxDefaultValidator, "Pick a filling color") ;

	y+=WIDGET_Y_STEP;
	wxStaticText* text2 = new wxStaticText(this, wxID_ANY, wxT("Outline color"), wxPoint(10, y)) ;
	y+= 20;
	m_colourPickerOutline = new wxColourPickerCtrl(this, ID_COLORPICKEROUTLINE, *wxBLACK, wxPoint(10, y), wxDefaultSize, wxCLRP_DEFAULT_STYLE, wxDefaultValidator, "Pick an outline color") ;

	y+=WIDGET_Y_STEP;
	wxStaticText* text3 = new wxStaticText(this, wxID_ANY, wxT("Background color"), wxPoint(10, y)) ;
	
	y+= 20;
	m_colourPickerBackground = new wxColourPickerCtrl(this, ID_COLORPICKERBACKGROUND, *wxWHITE, wxPoint(10, y), wxDefaultSize, wxCLRP_DEFAULT_STYLE, wxDefaultValidator, "Pick a background color") ;
	Bind(wxEVT_COMMAND_COLOURPICKER_CHANGED, &MyControlPanel::onColourPicker, this, ID_COLORPICKERBACKGROUND) ;


	//Sliders pour transparence et épaisseur du trait


	y+= WIDGET_Y_STEP ;
	wxStaticText* text4 = new wxStaticText(this, wxID_ANY, wxT("Outline Thickness"), wxPoint(10, y)) ;
	y+= 15 ;
	m_sliderWidth = new wxSlider(this, ID_SLIDERWIDTH, 1, 1, 20, wxPoint(10, y), wxSize(100,20)) ;	

	y+= WIDGET_Y_STEP ;
	wxStaticText* text5 = new wxStaticText(this, wxID_ANY, wxT("Transparency"), wxPoint(10, y)) ;
	y+= 15 ;
	m_sliderTransparency = new wxSlider(this, ID_SLIDERTRANSPARENCY, 255, 0, 255, wxPoint(10, y), wxSize(100,20)) ;


	//Undo, redo, erase all

	y+= 2*WIDGET_Y_STEP ;
	m_buttonEraseAll = new wxButton(this, ID_UNDOBUTTON, wxT("Undo"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonUndo, this, ID_UNDOBUTTON) ;
	y+= WIDGET_Y_STEP ;
	m_buttonRedo = new wxButton(this, ID_REDOBUTTON, wxT("Redo"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButtonRedo, this, ID_REDOBUTTON) ;
	y+= WIDGET_Y_STEP ;
	m_buttonUndo = new wxButton(this, ID_DELETEALLBUTTON, wxT("Erase all"), wxPoint(10, y)) ;
	Bind(wxEVT_BUTTON, &MyControlPanel::OnButton, this, ID_DELETEALLBUTTON) ;

}

//------------------------------------------------------------------------
void MyControlPanel::OnButton(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	controler->eraseAll();
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

void MyControlPanel::OnButtonUndo(wxCommandEvent &event)
{
	controler->popLastDrawing();
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

void MyControlPanel::OnButtonRedo(wxCommandEvent &event)
{
	controler->redoLastDrawing();
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}



void MyControlPanel::onColourPicker(wxCommandEvent &event)
{
	controler->setBackgroundColor();
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
	controler->setClic(0);
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::setControler(Controler *controler)
//------------------------------------------------------------------------
{
	this->controler = controler;
}

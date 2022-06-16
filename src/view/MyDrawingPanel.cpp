#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <wx/brush.h>
#include <wx/clrpicker.h>
#include <wx/colour.h>

#include "MyDrawingPanel.hpp"
#include "MyFrame.hpp"
#include "../model/Line.hpp"
#include "../model/Dessin.hpp"
#include "../model/Cercle.hpp"



#include <vector>
#include "Constant.hpp"

#include <cmath>

#include "../controler/Controler.hpp"

using namespace std;

MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;

	m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
	m_onePoint.y = h/2 ;
	m_mousePoint = m_onePoint ;

	dragging = false;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	m_mousePoint.x = event.m_x ;
	m_mousePoint.y = event.m_y ;
	wxColour colourFill = controler->getColourPickedFill();
	wxColour colourOutline = controler->getColourPickedOutline();
	int width = controler->getSliderValue();
	unsigned int transparency = controler->getSliderTransparencyValue();
	wxColour transparencyFillColor = wxColour(colourFill.Red(), colourFill.Green(), colourFill.Blue(), transparency);
	wxColour transparencyOutlineColor = wxColour(colourOutline.Red(), colourOutline.Green(), colourOutline.Blue(), transparency);

	if (dragging){
		int x1 = m_mousePoint.x;
		int y1 = m_mousePoint.y;
		controler->setCoordinatesPoint(x1, y1, transparencyFillColor, transparencyOutlineColor, width);

	}
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	m_onePoint.x = event.m_x ; //Récupère les coordonnées x et y de la souris dès qu'un clic gauche est réalisé
	m_onePoint.y = event.m_y ;

	static int x1, x2, y1, y2 = 0;
		
	bool line = controler->getBoolLine(); //Faire les méthodes pour savoir quel bouton de dessin est activé
	bool circle = controler->getBoolCircle();
	bool rectangle = controler->getBoolRectangle();
	bool pen = controler->getBoolPen();
	wxColour colourFill = controler->getColourPickedFill();
	wxColour colourOutline = controler->getColourPickedOutline();
	int width = controler->getSliderValue();
	unsigned int transparency = controler->getSliderTransparencyValue();
	wxColour transparencyFillColor = wxColour(colourFill.Red(), colourFill.Green(), colourFill.Blue(), transparency);
	wxColour transparencyOutlineColor = wxColour(colourOutline.Red(), colourOutline.Green(), colourOutline.Blue(), transparency);
	
	//wxColour test = test.SetRGBA(colourFill.Red(), colourFill.Green(), colourFill.Blue(), transparency);


	controler->testIsInside(m_onePoint.x, m_onePoint.y);

	
	//Dans le cas de la ligne :

	if (controler->getClic()==0 && line)
	{
		x1 = m_onePoint.x;
		y1 = m_onePoint.y;
		controler->setClic(1); //Indique au controleur que le prochain clic permettra de placer le deuxième point de la ligne
		//Le premier point est posé
	}
	else if (line && controler->getClic()==1)
	{
		controler->setCoordinatesLine(x1, y1, m_onePoint.x, m_onePoint.y, transparencyFillColor, transparencyOutlineColor, width); //Donne au controleur les coordonnées de la souris pour avoir le second point de la ligne
		controler->setClic(0); //Indique au controleur que le prochain clic réinitialise la séquence et sera donc pour une nouvelle ligne
		x1, y1 = 0;
		//La ligne est posée
	}

	if (controler->getClic()==0 && circle)
	{
		x1 = m_onePoint.x;
		y1 = m_onePoint.y;
		controler->setClic(1); //Indique au controleur que le prochain clic permettra de placer le deuxième point de la ligne
		//Le premier point est posé
	}

	else if(circle && controler->getClic()==1)
	{	
		int disX = abs(x1 - m_onePoint.x);
		int disY = abs(y1 - m_onePoint.y);
		int radius = sqrt(pow(disX, 2) + pow(disY, 2));
		controler->setCoordinatesCircle(x1, y1, radius,transparencyFillColor, transparencyOutlineColor, width);
		controler->setClic(0);
	}	

	if (controler->getClic()==0 && rectangle)
	{
		x1 = m_onePoint.x;
		y1 = m_onePoint.y;
		controler->setClic(1); //Indique au controleur que le prochain clic permettra de placer le deuxième point de la ligne
		//Le premier point est posé
	}

	else if(rectangle && controler->getClic()==1)
	{
		controler->setCoordinatesRectangle(x1, y1, m_onePoint.x, m_onePoint.y,transparencyFillColor, transparencyOutlineColor,width);
		controler->setClic(0);
	}

	if (pen && dragging)
	{
		dragging = false;
	}
	else if (pen && !dragging)
	{
		dragging = true;
	}
	Refresh() ; // send an event that calls the OnPaint method
}


//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	// read the control values
	MyFrame* frame =  (MyFrame*)GetParent() ;
	//int radius = frame->GetControlPanel()->GetSliderValue() ;
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
	bool line = controler->getBoolLine();
	bool circle = controler->getBoolCircle();
	bool rectangle = controler->getBoolRectangle();
	bool pen = controler->getBoolPen();
	wxColour colourFill = controler->getColourPickedFill();
	wxColour colourOutline = controler->getColourPickedOutline();
	int width = controler->getSliderValue();
	unsigned int transparency = controler->getSliderTransparencyValue();
	wxColour transparencyFillColor = wxColour(colourFill.Red(), colourFill.Green(), colourFill.Blue(), transparency);
	wxColour transparencyOutlineColor = wxColour(colourOutline.Red(), colourOutline.Green(), colourOutline.Blue(), transparency);



	Dessin dessin = controler->getDessin();

	// then paint
	wxPaintDC dc(this);	
	
	if (check)
	{
		wxString coordinates ;
		coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y);
		dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20));
	}
	
	controler->drawForms(&dc);

	dc.SetPen(wxPen(transparencyOutlineColor, width));
	dc.SetBrush(transparencyFillColor);

	if(controler->getClic()==1 && line){
		dc.DrawLine(m_mousePoint, m_onePoint) ;
	}
	if(controler->getClic()==1 && circle)
	{
		int disX = abs(m_mousePoint.x - m_onePoint.x);
		int disY = abs(m_mousePoint.y - m_onePoint.y);
		int radius = sqrt(pow(disX, 2) + pow(disY, 2)); 
		dc.DrawCircle(wxPoint(m_onePoint), radius);
	}
	if(controler->getClic()==1 && rectangle){
		dc.DrawRectangle(m_mousePoint.x, m_mousePoint.y, m_onePoint.x-m_mousePoint.x, m_onePoint.y-m_mousePoint.y) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to open (and close) any file 
	FILE* f = fopen(fileName, "r") ;
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed")) ;
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	bool isImageSaved = controler->saveImage(fileName, APPLICATION_HEIGHT, APPLICATION_WIDTH);

	if (isImageSaved == false)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		wxMessageBox(wxT("The file was saved")) ;
	}
}

void MyDrawingPanel::setControler(Controler *controler)
//------------------------------------------------------------------------
{
	this->controler = controler;
}

void MyDrawingPanel::setBackgroundColor()
{
	
}
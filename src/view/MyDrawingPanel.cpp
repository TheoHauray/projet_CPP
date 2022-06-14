#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "MyDrawingPanel.hpp"
#include "MyFrame.hpp"
#include "../model/Line.hpp"
#include "../model/Dessin.hpp"

#include "Constant.hpp"


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
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	m_mousePoint.x = event.m_x ;
	m_mousePoint.y = event.m_y ;
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	m_onePoint.x = event.m_x ; //Récupère les coordonnées x et y de la souris dès qu'un clic gauche est réalisé
	m_onePoint.y = event.m_y ;

	bool line = controler.getBoolLine(); //Faire les méthodes pour savoir quel bouton de dessin est activé
	//bool circle = controler.getBoolCircle();

	clic = controler.getClic(); //Permet de savoir si on est sur le clic numéro 1 pour placer l'origine de la forme, ou bien sur le clic numéro 2 pour placer la forme


	//Dans le cas de la ligne :

	if (line && clic==0)
	{
		controler.setCoordinatesLineStart(m_onePoint.x, m_onePoint.y); //Donne au controler les coordonnées de la souris pour avoir le premier point de la ligne
		controler.setClic(1) //Indique au controleur que le prochain clic permettra de placer le deuxième point de la ligne
		//Le premier point est posé
	}
	else if (line && clic==1)
	{
		controler.setCoordinatesLineEnd(m_onePoint.x, m_onePoint.y); //Donne au controleur les coordonnées de la souris pour avoir le second point de la ligne
		controler.drawLine(); //Dessine la ligne entre le premier point et le second point.
		controler.setClic(0); //Indique au controleur que le prochain clic réinitialise la séquence et sera donc pour une nouvelle ligne
		//La ligne est posée
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
	int radius = frame->GetControlPanel()->GetSliderValue() ;
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
	Dessin dessin = controler.getDessin();
	int vecLen = dessin.getVector().size();




	// then paint
	wxPaintDC dc(this);	
		
	dc.DrawLine(m_mousePoint, m_onePoint) ;
	dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
	dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;


	
	if (check)
	{
		wxString coordinates ;
		coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
		dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
	}

  /*
	vecLen = dessin.size();
	for(int i = 0; i<vecLen; i++){
		dc.DrawLine(dessin[i]->x1, dessin[i]->y1, dessin[i]->x2, dessin[i]->y2);
	}


	*/

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
	// just to create a tiny file
	FILE* f = fopen(fileName, "w") ;
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		fprintf(f, "S1102 software can create and write a file") ;
		wxMessageBox(wxT("The file was saved")) ;
		fclose(f) ;
	}
}

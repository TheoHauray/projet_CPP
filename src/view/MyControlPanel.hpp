#ifndef __MYCONTROLPANEL_H__
#define __MYCONTROLPANEL_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "../controler/Controler.hpp"

class Controler ; 

//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyControlPanel( wxWindow *parent ) ;
	int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
	bool GetRadioButtonLineValue() {return m_radioButtonLine->GetValue();} ;
	bool GetRadioButtonCircleValue() {return m_radioButtonCircle->GetValue();} ;
	bool GetRadioButtonRectangleValue() {return m_radioButtonRectangle->GetValue();} ;
	bool GetRadioButtonPenValue() {return m_radioButtonPen->GetValue();} ;



	bool GetLineValue() {return m_line->GetValue();} ; 
	void setControler(Controler *controler) ;

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	void OnCheckBoxLine(wxCommandEvent &event) ;

	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
	wxCheckBox* m_line ;
	wxRadioButton* m_radioButtonLine;
	wxRadioButton* m_radioButtonCircle;
	wxRadioButton* m_radioButtonRectangle;
	wxRadioButton* m_radioButtonPen;

	Controler *controler;
};

#endif //__MYCONTROLPANEL_H__
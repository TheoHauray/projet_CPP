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
#include <wx/clrpicker.h>
#include <wx/colour.h>

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
	bool getRadioButtonBackgroundColor() {return m_radioButton_Background->GetValue();} ;
	bool getRadioButtonFormColor() {return m_radioButton_Form->GetValue();} ;
	bool GetRadioButtonPenValue() {return m_radioButtonPen->GetValue();} ;
	wxColour getColourPickerColor() {return m_colourPicker->GetColour();} ;

	bool GetLineValue() {return m_line->GetValue();} ; 
	void setControler(Controler *controler) ;

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	void OnCheckBoxLine(wxCommandEvent &event) ;
	void onColourPicker(wxCommandEvent &event) ;

	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
	wxCheckBox* m_line ;
	wxRadioButton* m_radioButtonLine;
	wxRadioButton* m_radioButtonCircle;
	wxRadioButton* m_radioButtonRectangle;
	wxButton* m_button_applyColor ;
	wxRadioButton* m_radioButton_Background;
	wxRadioButton* m_radioButton_Form;
	wxColourPickerCtrl* m_colourPicker ;
	wxRadioButton* m_radioButtonPen;


	Controler *controler;
};

#endif //__MYCONTROLPANEL_H__
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
	//int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
	bool GetRadioButtonLineValue() {return m_radioButtonLine->GetValue();} ;
	bool GetRadioButtonCircleValue() {return m_radioButtonCircle->GetValue();} ;
	bool GetRadioButtonRectangleValue() {return m_radioButtonRectangle->GetValue();} ;
	bool GetRadioButtonPenValue() {return m_radioButtonPen->GetValue();} ;
	bool GetRadioButtonSelection() {return m_radioButtonSelection->GetValue();} ;
	bool GetRadioButtonSelectColor() {return m_radioButtonSelectColor->GetValue();} ;
	bool GetRadioButtonSelectPosition() {return m_radioButtonSelectPosition->GetValue();} ;
	bool GetRadioButtonSelectPositionFront() {return m_radioButtonPushFront->GetValue();} ;
	bool GetRadioButtonSelectPositionBack() {return m_radioButtonPushBack->GetValue();} ;




	wxColour getColourPickerColorFill() {return m_colourPickerFill->GetColour();} ;
	wxColour getColourPickerColorOutline() {return m_colourPickerOutline->GetColour();} ;
	wxColour getColourPickerColorBackground() {return m_colourPickerBackground->GetColour();} ;

	int getSliderValue() {return m_sliderWidth->GetValue() ;} ;
	unsigned char getSliderTransparencyValue() {return m_sliderTransparency->GetValue() ;} ;

	bool GetLineValue() {return m_line->GetValue();} ; 
	void setControler(Controler *controler) ;

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
	void OnCheckBoxLine(wxCommandEvent &event) ;
	void onColourPicker(wxCommandEvent &event) ;
	void OnButtonUndo(wxCommandEvent &event);
	void OnButtonRedo(wxCommandEvent &event);


	wxCheckBox* m_checkBox ;
	wxCheckBox* m_line ;
	wxRadioButton* m_radioButtonLine;
	wxRadioButton* m_radioButtonCircle;
	wxRadioButton* m_radioButtonRectangle;
	wxRadioButton* m_radioButtonSelection;

	wxColourPickerCtrl* m_colourPickerFill ;
	wxColourPickerCtrl* m_colourPickerOutline ;
	wxColourPickerCtrl* m_colourPickerBackground ;
	wxRadioButton* m_radioButtonPen;
	wxSlider* m_sliderWidth;
	wxSlider* m_sliderTransparency;
	wxButton* m_buttonEraseAll ;
	wxButton* m_buttonUndo;
	wxButton* m_buttonRedo;
	wxRadioButton* m_radioButtonSelectColor;
	wxRadioButton* m_radioButtonSelectPosition;
	wxRadioButton* m_radioButtonPushFront;
	wxRadioButton* m_radioButtonPushBack;




	Controler *controler;
};

#endif //__MYCONTROLPANEL_H__
/***************************************************************
 * Name:      date_class_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Andres Berejnoi (berejnoibejaranoc@berea.edu)
 * Created:   2014-11-28
 * Copyright: Andres Berejnoi ()
 * License:
 **************************************************************/

#ifndef DATE_CLASS_GUIMAIN_H
#define DATE_CLASS_GUIMAIN_H

//(*Headers(date_class_GUIFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class date_class_GUIFrame: public wxFrame
{
    public:

        date_class_GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~date_class_GUIFrame();

    private:

        //(*Handlers(date_class_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void Onmonth_inputText(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void Onday_inputText(wxCommandEvent& event);
        void OnMenuItem3Selected(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(date_class_GUIFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT4;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT14;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuHowToUse;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(date_class_GUIFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxTextCtrl* compare_year;
        wxTextCtrl* day_input;
        wxButton* Button4;
        wxStaticText* StaticText2;
        wxTextCtrl* year_input;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxTextCtrl* compare_month;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxStaticText* result_Label;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* compare_day;
        wxButton* Button2;
        wxMenuItem* MenuItem3;
        wxStaticText* difference_Label;
        wxButton* Button3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText12;
        wxTextCtrl* change_days_input;
        wxTextCtrl* month_input;
        wxStaticText* StaticText4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DATE_CLASS_GUIMAIN_H

/***************************************************************
 * Name:      date_class_GUIMain.cpp
 * Purpose:   Code for Application Frame. Implementation of a GUI for a data calculator using the date class
 * Author:    Andres Berejnoi (berejnoibejaranoc@berea.edu)
 * Created:   2014-11-28
 * Copyright: Andres Berejnoi ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "date_class_GUIMain.h"
#include <wx/msgdlg.h>
#include "Date.h"

//(*InternalHeaders(date_class_GUIFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(date_class_GUIFrame)
const long date_class_GUIFrame::ID_TEXTCTRL1 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL2 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL3 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT3 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT2 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT1 = wxNewId();
const long date_class_GUIFrame::ID_BUTTON1 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT4 = wxNewId();
const long date_class_GUIFrame::ID_BUTTON2 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL4 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT5 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL7 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL6 = wxNewId();
const long date_class_GUIFrame::ID_TEXTCTRL5 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT6 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT7 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT8 = wxNewId();
const long date_class_GUIFrame::ID_BUTTON3 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT9 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT11 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT10 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT13 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT12 = wxNewId();
const long date_class_GUIFrame::ID_STATICTEXT14 = wxNewId();
const long date_class_GUIFrame::ID_BUTTON4 = wxNewId();
const long date_class_GUIFrame::ID_PANEL1 = wxNewId();
const long date_class_GUIFrame::idMenuQuit = wxNewId();
const long date_class_GUIFrame::idMenuHowToUse = wxNewId();
const long date_class_GUIFrame::idMenuAbout = wxNewId();
const long date_class_GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(date_class_GUIFrame,wxFrame)
    //(*EventTable(date_class_GUIFrame)
    //*)
END_EVENT_TABLE()

date_class_GUIFrame::date_class_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(date_class_GUIFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(555,349));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,32), wxSize(400,280), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    month_input = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(48,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    day_input = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(48,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    year_input = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(48,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Enter Year:"), wxPoint(48,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Enter Day:"), wxPoint(48,144), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Enter Month:"), wxPoint(48,88), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Calculate"), wxPoint(168,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    result_Label = new wxStaticText(Panel1, ID_STATICTEXT4, wxEmptyString, wxPoint(168,160), wxSize(100,40), 0, _T("ID_STATICTEXT4"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Show Curr. Date"), wxPoint(432,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    change_days_input = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxPoint(48,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Change in Days:"), wxPoint(48,256), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    compare_year = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxPoint(312,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    compare_day = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxPoint(312,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    compare_month = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxPoint(312,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Enter a Month:"), wxPoint(312,88), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Enter a Day:"), wxPoint(312,144), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Enter a Year:"), wxPoint(312,200), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Get Days"), wxPoint(432,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Date Calculator"), wxPoint(224,8), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont StaticText8Font = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    if ( !StaticText8Font.Ok() ) StaticText8Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText8Font.SetPointSize(14);
    StaticText8->SetFont(StaticText8Font);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Calculate what date it will be after a certain amount of days."), wxPoint(160,72), wxSize(120,45), 0, _T("ID_STATICTEXT11"));
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Enter a date to calculate the days in between this and the 1st date."), wxPoint(424,72), wxSize(120,45), 0, _T("ID_STATICTEXT10"));
    StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Start Date"), wxPoint(48,48), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT12, _("End Date"), wxPoint(312,48), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    difference_Label = new wxStaticText(Panel1, ID_STATICTEXT14, wxEmptyString, wxPoint(432,160), wxSize(100,40), 0, _T("ID_STATICTEXT14"));
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Is Leap\?"), wxPoint(168,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu2, idMenuHowToUse, _("How to Use\tF1"), _("Explain how to use the application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF2"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&date_class_GUIFrame::Onmonth_inputText);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&date_class_GUIFrame::Onday_inputText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&date_class_GUIFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&date_class_GUIFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&date_class_GUIFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&date_class_GUIFrame::OnButton4Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&date_class_GUIFrame::OnQuit);
    Connect(idMenuHowToUse,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&date_class_GUIFrame::OnMenuItem3Selected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&date_class_GUIFrame::OnAbout);
    //*)
}

date_class_GUIFrame::~date_class_GUIFrame()
{
    //(*Destroy(date_class_GUIFrame)
    //*)
}

void date_class_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}


void date_class_GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg + (_("\nProgram designed by Andres Berejnoi.")), _("Welcome to..."));
}

void date_class_GUIFrame::OnClose(wxCloseEvent& event)
{
}

void date_class_GUIFrame::OnButton1Click(wxCommandEvent& event)
{
}

void date_class_GUIFrame::OnButton1Click1(wxCommandEvent& event)
//This code is executed when the button labeled "Calculate" is pressed.
//A dialog box will pop up displaying the final calculated date in a  mm/dd/yy format
{
    result_Label->SetLabel(_(""));                  //Every time the button is clicked, the previous  value in the result label is erased.

//-----------------------------------------------------------------
    wxString month, day, year, change;                          //initializing wxString variables that take the value of a textbox
    month = month_input->GetValue();                        //getting the value of the first textbox
    day = day_input->GetValue();                            //getting the value of the second textbox
    year = year_input->GetValue();                          //getting the value of the third textbox
    change = change_days_input->GetValue();                 //getting the value of the fourth textbox

//----------------------------------------------------------------------
 //Converting wxString into integers with the wxAtoi function.
    int month_int_input, day_int_input, year_int_input, days_change_int;

    month_int_input = wxAtoi(month);    //The argument for Atoi function is a wxString object, and returns an integer
    day_int_input = wxAtoi(day);
    year_int_input = wxAtoi(year);
    days_change_int = wxAtoi(change);
//----------------------------------------------------------------------

    Date user_Input(month_int_input, day_int_input, year_int_input);            //Creating an instance of the Date class. It is initialized with the values entered in the textboxes

    Date newDate = user_Input.finalDate(days_change_int);       //Creates a new instance of the Date class. The finalDate function returns a Date object and takes an integer as parameter

    int month_final, day_final, year_final;               //initializing int objects to store the values of the instance variables of the class newDate
    month_final = newDate.getMonth();
    day_final = newDate.getDay();
    year_final = newDate.getYear();
//--------------------------------------------------------------------
 //Here, integers are being converted into wxString objects.
    wxString newMonth, newDay, newYear;
    newMonth<<month_final;          //This makes the integer month_final be stored as a wxString in newMonth
    newDay<<day_final;
    newYear<<year_final;
//--------------------------------------------------------------------

//------Displaying the result in a dialog box-------------------------
    wxString messageHeader = (_("The date will be: "));             //a wxString that contains the header for the dialog box that pops up when pressing the button
    wxMessageBox(_(newMonth+"/"+newDay+"/"+newYear), messageHeader);        //Opens a dialog box with the calculated date in mm/dd/yy format. The second parameter is the header of the window

    result_Label->SetLabel(_("The resulting date is:\n")+newMonth+"/"+newDay+"/"+newYear);         //The GUI label object changes its value to the final calculated date
}


void date_class_GUIFrame::OnButton2Click(wxCommandEvent& event)
/*Opens a dialog box displaying the current date.
It creates a Date object with its default constructor,
which is set to the operating system's internal time*/
{
    Date currentDate;

    wxString currenMonth, currentDay, currentYear;
    currenMonth<<currentDate.getMonth();
    currentDay<<currentDate.getDay();
    currentYear<<currentDate.getYear();

    wxString headerMessage = (_("Current Date: "));
    wxMessageBox(_(currenMonth+"/"+currentDay+"/"+currentYear), headerMessage);
}


void date_class_GUIFrame::OnButton3Click(wxCommandEvent& event)
/*Takes input from 6 text-boxes corresponding to two Date objects
and calculates how many days are in between them.
The result is shown in a pop up message box.*/
{
    difference_Label->SetLabel(_(""));                      //Resets the label value when the button is clicked so that the previous information is deleted.

    wxString firstMonth, secondMonth, firstDay, secondDay, firstYear, secondYear;
    firstMonth = month_input->GetValue();
    firstDay = day_input->GetValue();
    firstYear = year_input->GetValue();

    secondMonth = compare_month->GetValue();
    secondDay = compare_day->GetValue();
    secondYear = compare_year->GetValue();

//------------------Converting wxStrings into integers----------------------------
    int month_int, day_int, year_int, month_second_int, day_second_int, year_second_int;

    month_int = wxAtoi(firstMonth);
    day_int = wxAtoi(firstDay);
    year_int = wxAtoi(firstYear);

    month_second_int = wxAtoi(secondMonth);
    day_second_int = wxAtoi(secondDay);
    year_second_int = wxAtoi(secondYear);
//---------------------------------------------------------------------------------
    Date firstDate(month_int, day_int, year_int);                                       //Instance of Date class for start date
    Date secondDate(month_second_int, day_second_int, year_second_int);                 //Creating an instance of the Date class for the end date

    int days_in_between;

    days_in_between = firstDate.differenceInDays(secondDate);                           //Here, the start date calls the method to calculate the days in between

//---------------------------------------Displaying the information---------------------------------------------------------------
    wxString Days_difference, msgHeader;

    difference_Label->SetLabel(_("Days in between:\n")+Days_difference);                //Displays the difference in days using a label under the button.

    Days_difference<<days_in_between;
    msgHeader = (_("Days in between:"));

    wxMessageBox(_("There are ")+Days_difference+" days in between\nthe two dates.\n(Not including end day)", msgHeader);            //Opens a message box with the same information as

}

void date_class_GUIFrame::Onday_inputText(wxCommandEvent& event)
{
}

void date_class_GUIFrame::OnMenuItem3Selected(wxCommandEvent& event)
//This is the code for the help menu. It explains to the user how
  //  to correctly use the program and provides examples.
{
    wxString msgHeader, help_info;                                  //Declaring wxStrings for the header and the help information
    msgHeader = (_("How to Use This Program:"));
    help_info = (_("This program is a date calculator.\n"                               //This is the help information or instructions for the program
                   "The functions supported at the moment are:\n"
                   "- Calculate the date after some days.\n"
                   "- Calculate the number of days between two dates.\n"
                   "\nTo Calculate what date it will be after some time,\n"
                   "just fill the 4 text-boxes on the left. The first 3\n"
                   "are for the date you want to start. The forth box is the\n"
                   "number of days you want to count from the starting date.\n"
                   "Once you have all entered, pressed the button 'Calculate'\n"
                   "placed right next to the left boxes.\n"
                   "Example:\n    Date Entered: 10/10/2014; Change in days: 10\n"
                   "    Based on this, the program will calculate what date it\n"
                   "    will be after 10 days. The result will be 10/20/2014.\n"
                   "    Remember that 'Change in Days' can be positive or negative.\n"
                   "\nThe second functionality allows you to calculate the number\n"
                   "of days that are in between two dates. Start by entering the\n"
                   "month, day, and year for your starting date on the left boxes;\n"
                   "on the right side, you will find a second set of boxes for\n"
                   "you to enter your end date. You need not worry about the\n"
                   "'Change in days' box here. Once you have your two dates\n"
                   "entered, click on the button 'Get Days' to calculate.\n"
                   "You can even use this program to know how old things are!"));

    wxMessageBox(help_info, msgHeader);                                 //Opens a message box with the info text and the window header
}

void date_class_GUIFrame::Onmonth_inputText(wxCommandEvent& event)
{
}

void date_class_GUIFrame::OnButton4Click(wxCommandEvent& event)
/*When the "Is Leap" button is clicked, a message box pops up
saying if the year entered is a leap year or not.
Pre: a valid year is entered into the correct text box, which is located on the left of the button
Post: A message box opens and displays the answer with a text message.
*/
{
    wxString year_text;
    year_text = year_input->GetValue();

    int year_int;
    year_int = wxAtoi(year_text);

    bool leap_bool;
    leap_bool = isLeap(year_int);

    wxString header_msg, answer;
    header_msg = (_("Result"));

    if (leap_bool==true){
        answer = (_("The year is a leap year"));
    }
    else{
        answer = (_("The year is not a leap year"));
    }

    wxMessageBox(answer, header_msg);

}

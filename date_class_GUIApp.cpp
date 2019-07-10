/***************************************************************
 * Name:      date_class_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Andres Berejnoi (berejnoibejaranoc@berea.edu)
 * Created:   2014-11-28
 * Copyright: Andres Berejnoi ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "date_class_GUIApp.h"

//(*AppHeaders
#include "date_class_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(date_class_GUIApp);

bool date_class_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	date_class_GUIFrame* Frame = new date_class_GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

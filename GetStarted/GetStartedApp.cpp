/***************************************************************
 * Name:      GetStartedApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Sanjula ()
 * Created:   2019-08-20
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "GetStartedApp.h"

//(*AppHeaders
#include "GetStartedMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GetStartedApp);

bool GetStartedApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GetStartedDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}

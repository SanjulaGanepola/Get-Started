/***************************************************************
 * Name:      GetStartedMain.h
 * Purpose:   Defines Application Frame
 * Author:    Sanjula ()
 * Created:   2019-08-20
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#ifndef GETSTARTEDMAIN_H
#define GETSTARTEDMAIN_H

//(*Headers(GetStartedDialog)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/bmpbuttn.h>
//*)

class GetStartedDialog: public wxDialog
{
    public:

        GetStartedDialog(wxWindow* parent,wxWindowID id = -1);

    private:

        //(*Handlers(GetStartedDialog)
		void OnEditClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(GetStartedDialog)
        static const long ID_NAMETEXT;
        static const long ID_OPENRECENTTEXT;
        static const long ID_GETSTARTED;
        static const long ID_STARTBITMAP;
		static const long ID_EDITBITMAP;
        static const long ID_STARTNAMETEXT;
        static const long ID_STARTDESCRIPTIONTEXT;
        //*)

        //(*Declarations(GetStartedDialog)
		wxPanel* Recent1;
        wxPanel* Recent2;
        wxPanel* Recent3;
        wxPanel* Recent4;
		wxPanel* Start1;
		wxPanel* Start2;
		wxPanel* Start3;
		wxPanel* Start4;
        wxStaticBitmap* RecentProfileBitmap;
        wxStaticBitmap* StartBitmap;
		wxBitmapButton* EditProfileBitmap;
        wxStaticText* DateText;
        wxStaticText* GetStarted;
        wxStaticText* LinkText;
        wxStaticText* NameText;
        wxStaticText* OpenRecentText;
        wxStaticText* RecentNameText;
        wxStaticText* StartDescriptionText;
        wxStaticText* StartNameText;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GETSTARTEDMAIN_H

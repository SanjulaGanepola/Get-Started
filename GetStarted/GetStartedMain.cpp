/***************************************************************
 * Name:      GetStartedMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sanjula ()
 * Created:   2019-08-20
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "GetStartedMain.h"
#include <wx/msgdlg.h>
#include "RecentPanel.h"
#include "StartPanel.h"
#include "Profile.h"

//(*InternalHeaders(GetStartedDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
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

//(*IdInit(GetStartedDialog)
const long GetStartedDialog::ID_NAMETEXT = wxNewId();
const long GetStartedDialog::ID_OPENRECENTTEXT = wxNewId();
const long GetStartedDialog::ID_GETSTARTED = wxNewId();
const long GetStartedDialog::ID_EDITBITMAP = wxNewId();
//*)

BEGIN_EVENT_TABLE(GetStartedDialog,wxDialog)
    //(*EventTable(GetStartedDialog)
    //*)
END_EVENT_TABLE()

GetStartedDialog::GetStartedDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GetStartedDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("GetStarted"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(51, 50, 50, 1));
    FlexGridSizer1 = new wxFlexGridSizer(4, 3, 0, 0);
	wxFont NameTextFont(27, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT);
    NameText = new wxStaticText(this, ID_NAMETEXT, _("Multi-Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_NAMETEXT"));
	NameText->SetFont(NameTextFont);
    NameText->SetForegroundColour(wxColour(255, 255, 255));
    FlexGridSizer1->Add(NameText, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 45);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	
	
	wxString editBitmap = wxStandardPaths::Get().GetResourcesDir() + wxT("/Edit.png");
	EditProfileBitmap = new wxBitmapButton(this, ID_EDITBITMAP, wxBitmap(wxImage(editBitmap)), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_EDITBITMAP"));
	EditProfileBitmap->SetBackgroundColour(wxColour(51, 50, 50, 1));
	FlexGridSizer1->Add(EditProfileBitmap, 1, wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 45);	
	
	
	
	wxFont RecentStartFont(15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT);
	OpenRecentText = new wxStaticText(this, ID_OPENRECENTTEXT, _("Open Recent"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_OPENRECENTTEXT"));
	OpenRecentText->SetFont(RecentStartFont);
	OpenRecentText->SetForegroundColour(wxColour(255, 255, 255));
    FlexGridSizer1->Add(OpenRecentText, 1, wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 45);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GetStarted = new wxStaticText(this, ID_GETSTARTED, _("Get Started"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_GETSTARTED"));
	GetStarted->SetFont(RecentStartFont);
	GetStarted->SetForegroundColour(wxColour(255, 255, 255));
    FlexGridSizer1->Add(GetStarted, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);   
	wxString recentBitmapLink1 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Temp.png");
	wxString recentBitmapLink2 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Temp.png");
	wxString recentBitmapLink3 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Temp.png");
	wxString recentBitmapLink4 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Temp.png");
	RecentPanel* Recent1 = new RecentPanel(this, wxID_ANY, _("FilterDialog.sln"), _("2019-05-28 8:45am"), "C:\\Users\\HP\\Desktop\\Project Menu\\Visual Studio\\ProjectMenu\Update\New", recentBitmapLink1);
	RecentPanel* Recent2 = new RecentPanel(this, wxID_ANY, _("CommentTool.sln"), _("2019-04-12 1:24pm"), "C:\\Users\\HP\\Desktop\\Project Menu\\Visual Studio\\ProjectMenu", recentBitmapLink2);
	RecentPanel* Recent3 = new RecentPanel(this, wxID_ANY, _("GetStarted.sln"), _("2019-02-05 5:19pm"), "C:\Users\HP\Desktop\Comment Tool\Visual Studio\Comment", recentBitmapLink3);
	RecentPanel* Recent4 = new RecentPanel(this, wxID_ANY, _("Login.sln"), _("2019-07-21 2:27pm"), "C:\Users\HP\Desktop\Project Menu\Visual Studio\ProjectMenu\x64", recentBitmapLink4);
	BoxSizer1->Add(Recent1, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5);
	BoxSizer1->Add(Recent2, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5);
    BoxSizer1->Add(Recent3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5);
    BoxSizer1->Add(Recent4, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5);	
	FlexGridSizer1->Add(BoxSizer1, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 45);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    BoxSizer2 = new wxBoxSizer(wxVERTICAL);    
	wxString startBitmapLink1 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Import.png");
	wxString startBitmapLink2 = wxStandardPaths::Get().GetResourcesDir() + wxT("/New.png");
	wxString startBitmapLink3 = wxStandardPaths::Get().GetResourcesDir() + wxT("/Duplicate.png");
	StartPanel* Start1 = new StartPanel(this, wxID_ANY, startBitmapLink1, _("Load an existing project       "), _("Open a local Multi-Label project"));
	StartPanel* Start2 = new StartPanel(this, wxID_ANY, startBitmapLink3, _("Create a new project            "), _("Start fresh with a blank template"));
	StartPanel* Start3 = new StartPanel(this, wxID_ANY, startBitmapLink2, _("Duplicate an existing project"), _("Begin with a copy of an existing project"));
	BoxSizer2->Add(Start1, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND, 5);
	BoxSizer2->Add(Start2, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND, 5);
	BoxSizer2->Add(Start3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND, 5);
	FlexGridSizer1->Add(BoxSizer2, 1, wxBOTTOM | wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 45);

    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    //*)

	EditProfileBitmap->Connect(wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GetStartedDialog::OnEditClick);
	
}

void GetStartedDialog::OnEditClick(wxCommandEvent& event){
	//Edit Profile
	Profile temp_profile(this);
	int profiledlg = temp_profile.ShowModal();
}


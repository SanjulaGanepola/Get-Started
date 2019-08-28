#include "Profile.h"
#include "UpdatePassword.h"

//(*InternalHeaders(Profile)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
//*)

//(*IdInit(Profile)
const long Profile::ID_PROFILETEXT = wxNewId();
const long Profile::ID_INSTRUCTIONTEXT = wxNewId();
const long Profile::ID_USERNAMEBITMAP = wxNewId();
const long Profile::ID_USERNAMECTRL = wxNewId();
const long Profile::ID_USERNAMEPANEL = wxNewId();
const long Profile::ID_EMAILBITMAP = wxNewId();
const long Profile::ID_EMAILCTRL = wxNewId();
const long Profile::ID_EMAILPANEL = wxNewId();
const long Profile::ID_PASSWORDHYPERLINK = wxNewId();
const long Profile::ID_EDITBUTTON = wxNewId();
const long Profile::ID_SAVEBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(Profile,wxDialog)
	//(*EventTable(Profile)
	//*)
END_EVENT_TABLE()

Profile::Profile(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Profile)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, wxID_ANY, _("Update Profile"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(51, 50, 50, 1));
	FlexGridSizer1 = new wxFlexGridSizer(6, 1, 0, 0);
	
	/*wxFont RecentNameTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	RecentNameText = new wxStaticText(Panel, ID_RECENTNAMETEXT, fileName, wxDefaultPosition, wxDefaultSize, 0, _T("ID_RECENTNAMETEXT"));
	RecentNameText->SetFont(RecentNameTextFont);
	RecentNameText->SetForegroundColour(wxColour(255,255,255));
	*/
	
	wxFont ProfileTextFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	ProfileText = new wxStaticText(this, ID_PROFILETEXT, _("Update Profile"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_PROFILETEXT"));
	ProfileText->SetFont(ProfileTextFont);
	ProfileText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(ProfileText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);	
	wxFont InstructionTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Click Edit Profile or Change Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_INSTRUCTIONTEXT"));
	InstructionText->SetFont(InstructionTextFont);
	InstructionText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(InstructionText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	UsernamePanel = new wxPanel(this, ID_USERNAMEPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_USERNAMEPANEL"));
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	wxString usernameLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Username.png");
	UsernameBitmap = new wxStaticBitmap(UsernamePanel, ID_USERNAMEBITMAP, wxBitmap(wxImage(usernameLocation)), wxDefaultPosition, wxSize(wxImage(usernameLocation).GetWidth() + 2, wxImage(usernameLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_USERNAMEBITMAP"));
	UsernameBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer2->Add(UsernameBitmap, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	UsernameCtrl = new wxTextCtrl(UsernamePanel, ID_USERNAMECTRL, wxEmptyString, wxDefaultPosition, wxSize(220, wxImage(usernameLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_USERNAMECTRL"));
	UsernameCtrl->Disable();
	UsernameCtrl->SetLabelText("User1");
	FlexGridSizer2->Add(UsernameCtrl, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	UsernamePanel->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(UsernamePanel);
	FlexGridSizer2->SetSizeHints(UsernamePanel);
	FlexGridSizer1->Add(UsernamePanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	EmailPanel = new wxPanel(this, ID_EMAILPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_EMAILPANEL"));
	FlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
	wxString emailLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Email.png");
	EmailBitmap = new wxStaticBitmap(EmailPanel, ID_EMAILBITMAP, wxBitmap(wxImage(emailLocation)), wxDefaultPosition, wxSize(wxImage(emailLocation).GetWidth() + 2, wxImage(emailLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_EMAILBITMAP"));
	EmailBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(EmailBitmap, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	EmailCtrl = new wxTextCtrl(EmailPanel, ID_EMAILCTRL, wxEmptyString, wxDefaultPosition, wxSize(220, wxImage(emailLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_EMAILCTRL"));
	EmailCtrl->Disable();
	EmailCtrl->SetLabelText("email1@email.ca");
	FlexGridSizer3->Add(EmailCtrl, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);	
	wxFont UsernameEmailCtrlTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	UsernameCtrl->SetFont(UsernameEmailCtrlTextFont);
	EmailCtrl->SetFont(UsernameEmailCtrlTextFont);
	EmailPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(EmailPanel);
	FlexGridSizer3->SetSizeHints(EmailPanel);
	FlexGridSizer1->Add(EmailPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	PasswordHyperLink = new wxHyperlinkCtrl(this, ID_PASSWORDHYPERLINK, _("Change Password"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_PASSWORDHYPERLINK"));
	PasswordHyperLink->SetFont(InstructionTextFont);
	FlexGridSizer1->Add(PasswordHyperLink, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 8);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	EditButton = new wxButton(this, ID_EDITBUTTON, _("Edit Profile"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_EDITBUTTON"));
	EditButton->SetBackgroundColour(wxColour(65, 65, 65, 1));
	EditButton->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer4->Add(EditButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	SaveButton = new wxButton(this, ID_SAVEBUTTON, _("Save"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_SAVEBUTTON"));
	SaveButton->SetBackgroundColour(wxColour(65, 65, 65, 1));
	SaveButton->SetForegroundColour(wxColour(255, 255, 255));
	SaveButton->Disable();
	wxFont EditSaveButtonFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	EditButton->SetFont(EditSaveButtonFont);
	SaveButton->SetFont(EditSaveButtonFont);
	FlexGridSizer4->Add(SaveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_PASSWORDHYPERLINK, wxEVT_HYPERLINK, (wxObjectEventFunction)&Profile::OnPasswordHyperLinkClick);
	Connect(ID_EDITBUTTON, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Profile::OnEditButtonClick);
	Connect(ID_SAVEBUTTON, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Profile::OnSaveButtonClick);
	//*)
}


void Profile::OnPasswordHyperLinkClick(wxCommandEvent& event)
{
	UpdatePassword temp_update(this);
	int updatedlg = temp_update.ShowModal();
}

void Profile::OnEditButtonClick(wxCommandEvent& event)
{
	UsernameCtrl->Enable();
	EmailCtrl->Enable();
	SaveButton->Enable();
	EditButton->Disable();
	InstructionText->SetLabelText("Update Username or Email and Save");
}

void Profile::OnSaveButtonClick(wxCommandEvent& event)
{
	if (!(UsernameCtrl->IsEmpty() || EmailCtrl->IsEmpty()) && (EmailCtrl->GetValue()).Contains("@") && ((EmailCtrl->GetValue()).Contains(".com") || (EmailCtrl->GetValue()).Contains(".ca"))) {
		/***************************************************************
		*INSERT CODE FOR USERNAME AND EMAIL
		**************************************************************/
		//this->Close();

		UsernameCtrl->Disable();
		EmailCtrl->Disable();
		SaveButton->Disable();
		EditButton->Enable();
		InstructionText->SetLabelText("New Username and Email Updated");
	}
	else {
		InstructionText->SetLabelText("Invalid Username or Email");
	}
}
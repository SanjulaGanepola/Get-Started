#include "UpdatePassword.h"

//(*InternalHeaders(UpdatePassword)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
//*)

//(*IdInit(UpdatePassword)
const long UpdatePassword::ID_UPDATEPASSWORDTEXT = wxNewId();
const long UpdatePassword::ID_INSTRUCTIONTEXT = wxNewId();
const long UpdatePassword::ID_CURRENTPASSWORDBITMAP = wxNewId();
const long UpdatePassword::ID_CURRENTPASSWORDCTRL = wxNewId();
const long UpdatePassword::ID_CURRENTPASSWORDPANEL = wxNewId();
const long UpdatePassword::ID_NEWPASSWORDBITMAP = wxNewId();
const long UpdatePassword::ID_NEWPASSWORDCTRL = wxNewId();
const long UpdatePassword::ID_NEWPASSWORDPANEL = wxNewId();
const long UpdatePassword::ID_SAVEBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(UpdatePassword,wxDialog)
	//(*EventTable(UpdatePassword)
	//*)
END_EVENT_TABLE()

UpdatePassword::UpdatePassword(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(UpdatePassword)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, wxID_ANY, _("Update Password"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(51, 50, 50, 1));
	FlexGridSizer1 = new wxFlexGridSizer(5, 0, 0, 0);
	wxFont UpdatePasswordTextFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	UpdatePasswordText = new wxStaticText(this, ID_UPDATEPASSWORDTEXT, _("Update Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_UPDATEPASSWORDTEXT"));
	UpdatePasswordText->SetForegroundColour(wxColour(255, 255, 255));
	UpdatePasswordText->SetFont(UpdatePasswordTextFont);
	FlexGridSizer1->Add(UpdatePasswordText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	wxFont InstructionTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Enter Current and New Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_INSTRUCTIONTEXT"));
	InstructionText->SetForegroundColour(wxColour(255, 255, 255));
	InstructionText->SetFont(InstructionTextFont);
	FlexGridSizer1->Add(InstructionText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString CurrentPasswordLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Current_Password.jpg");
	wxString newPasswordLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Password.png");
	CurrentPasswordPanel = new wxPanel(this, ID_CURRENTPASSWORDPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_CURRENTPASSWORDPANEL"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	CurrentPasswordBitmap = new wxStaticBitmap(CurrentPasswordPanel, ID_CURRENTPASSWORDBITMAP, wxBitmap(wxImage(CurrentPasswordLocation)), wxDefaultPosition, wxSize(wxImage(CurrentPasswordLocation).GetWidth() + 2, wxImage(CurrentPasswordLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_CURRENTPASSWORDBITMAP"));
	CurrentPasswordBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(CurrentPasswordBitmap, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	CurrentPasswordCtrl = new wxTextCtrl(CurrentPasswordPanel, ID_CURRENTPASSWORDCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(CurrentPasswordLocation).GetHeight() + 6), wxTE_PASSWORD, wxDefaultValidator, _T("ID_CURRENTPASSWORDCTRL"));
	CurrentPasswordCtrl->SetHint("Current Password");
	FlexGridSizer3->Add(CurrentPasswordCtrl, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	CurrentPasswordPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(CurrentPasswordPanel);
	FlexGridSizer3->SetSizeHints(CurrentPasswordPanel);
	FlexGridSizer1->Add(CurrentPasswordPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	NewPasswordPanel = new wxPanel(this, ID_NEWPASSWORDPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_NEWPASSWORDPANEL"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	NewPasswordBitmap = new wxStaticBitmap(NewPasswordPanel, ID_NEWPASSWORDBITMAP, wxBitmap(wxImage(newPasswordLocation)), wxDefaultPosition, wxSize(wxImage(newPasswordLocation).GetWidth() + 2, wxImage(newPasswordLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_NEWPASSWORDBITMAP"));
	NewPasswordBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer4->Add(NewPasswordBitmap, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	NewPasswordCtrl = new wxTextCtrl(NewPasswordPanel, ID_NEWPASSWORDCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(newPasswordLocation).GetHeight() + 6), wxTE_PASSWORD, wxDefaultValidator, _T("ID_NEWPASSWORDCTRL"));
	NewPasswordCtrl->SetHint("New Password");	
	wxFont CurrentNewTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	CurrentPasswordCtrl->SetFont(CurrentNewTextFont);
	NewPasswordCtrl->SetFont(CurrentNewTextFont);
	FlexGridSizer4->Add(NewPasswordCtrl, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	NewPasswordPanel->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(NewPasswordPanel);
	FlexGridSizer4->SetSizeHints(NewPasswordPanel);
	FlexGridSizer1->Add(NewPasswordPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	SaveButton = new wxButton(this, ID_SAVEBUTTON, _("Save"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_SAVEBUTTON"));
	SaveButton->SetBackgroundColour(wxColour(65, 65, 65, 1));
	SaveButton->SetForegroundColour(wxColour(255, 255, 255));
	wxFont SaveButtonFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	SaveButton->SetFont(SaveButtonFont);
	FlexGridSizer1->Add(SaveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_SAVEBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UpdatePassword::OnSaveButtonClick);
	//*)
}

void UpdatePassword::OnSaveButtonClick(wxCommandEvent& event)
{
	if (!(CurrentPasswordCtrl->IsEmpty() || NewPasswordCtrl->IsEmpty())) {
		/***************************************************************
		 *INSERT CODE FOR CHECKING IF CURRENT PASSWORD IS VALID
		 *INSERT CODE FOR UPDATING PASSWORD
		 **************************************************************/
		this->Close();
	}
	else {
		InstructionText->SetLabelText("Invalid Current or New Password");
	}	
}

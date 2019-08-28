#include "StartPanel.h"

const long StartPanel::ID_STARTBITMAP = wxNewId();
const long StartPanel::ID_STARTNAMETEXT = wxNewId();
const long StartPanel::ID_STARTDESCRIPTIONTEXT = wxNewId();


StartPanel::StartPanel(wxWindow *parent, int winid, wxString bitmapLink, wxString StartName, wxString description
) : wxPanel(parent, winid, wxDefaultPosition, wxDefaultSize)
{
	wxPanel* Panel = new wxPanel(this, winid);
	Panel->SetBackgroundColour(wxColour(65, 65, 65, 1));
	wxFlexGridSizer* FlexGridSizer2;
	FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
	StartBitmap = new wxStaticBitmap(Panel, ID_STARTBITMAP, wxBitmap(wxImage(bitmapLink)), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, _T("ID_STARTBITMAP"));
	FlexGridSizer2->Add(StartBitmap, 1, wxLEFT | wxTOP | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 30);	
	StartNameText = new wxStaticText(Panel, ID_STARTNAMETEXT, StartName, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STARTNAMETEXT"));
	wxFont StartNameTextFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT);
	StartNameText->SetFont(StartNameTextFont);
	StartNameText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer2->Add(StartNameText, 1, wxLEFT | wxTOP | wxRIGHT | wxALIGN_LEFT | wxALIGN_TOP, 30);
	FlexGridSizer2->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	wxFont StartDescriptionTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT);
	StartDescriptionText = new wxStaticText(Panel, ID_STARTDESCRIPTIONTEXT, description, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STARTDESCRIPTIONTEXT"));
	StartDescriptionText->SetFont(StartDescriptionTextFont);
	StartDescriptionText->SetForegroundColour(wxColour(255, 255, 255));	
	FlexGridSizer2->Add(StartDescriptionText, 1, wxRIGHT | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 30);
	Panel->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(Panel);
	FlexGridSizer2->SetSizeHints(Panel);
	
	Panel->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&StartPanel::OnStartPanelMouseEnter, 0, this);
	Panel->Connect(wxEVT_LEAVE_WINDOW, (wxObjectEventFunction)&StartPanel::OnStartPanelMouseLeave, 0, this);
	Panel->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&StartPanel::OnStartPanelLeftDown, 0, this);

	StartNameText->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&StartPanel::OnStartPanelLeftDown, 0, this);
	StartDescriptionText->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&StartPanel::OnStartPanelLeftDown, 0, this);
	StartBitmap->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&StartPanel::OnStartPanelLeftDown, 0, this);	
	
	StartNameText->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&StartPanel::OnStartPanelChildEnter, 0, this);
	StartDescriptionText->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&StartPanel::OnStartPanelChildEnter, 0, this);
	StartBitmap->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&StartPanel::OnStartPanelChildEnter, 0, this);
}

void StartPanel::OnStartPanelMouseEnter(wxMouseEvent& event)
{
	isOnStartPanelChild = false;
	StartNameText->SetForegroundColour(wxColour(*wxBLUE));
	StartNameText->Refresh();

}

void StartPanel::OnStartPanelMouseLeave(wxMouseEvent& event)
{
	if (isOnStartPanelChild == false) {
		StartNameText->SetForegroundColour(wxColour(255, 255, 255));
		StartNameText->Refresh();
	}
}

void StartPanel::OnStartPanelLeftDown(wxMouseEvent& event) {
	StartNameText->SetLabelText("OPEN NEXT WINDOW");
	/***************************************************************
	*INSERT CODE FOR OPENING NEXT WINDOW
	**************************************************************/
}

void StartPanel::OnStartPanelChildEnter(wxMouseEvent& event) {
	isOnStartPanelChild = true;
	StartNameText->SetForegroundColour(wxColour(*wxBLUE));
	StartNameText->Refresh();
}



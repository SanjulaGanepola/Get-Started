#include "RecentPanel.h"

const long RecentPanel::ID_RECENTBITMAP = wxNewId();
const long RecentPanel::ID_RECENTNAMETEXT = wxNewId();
const long RecentPanel::ID_DATETEXT = wxNewId();
const long RecentPanel::ID_LINKTEXT = wxNewId();


RecentPanel::RecentPanel(wxWindow *parent, int winid, wxString fileName, wxString date, wxString link, wxString bitmapLink
) : wxPanel(parent, winid, wxDefaultPosition, wxDefaultSize)
{
	Panel = new wxPanel(this, winid,wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	wxFlexGridSizer* FlexGridSizer3;
	//Panel->SetBackgroundColour(wxColour(65, 65, 65, 1));
	
	FlexGridSizer3 = new wxFlexGridSizer(2, 3, 0, 0);
	RecentBitmap = new wxStaticBitmap(Panel, ID_RECENTBITMAP, wxBitmap(wxImage(bitmapLink)), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, _T("ID_RECENTBITMAP"));
	FlexGridSizer3->Add(RecentBitmap, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	wxFont RecentNameTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	RecentNameText = new wxStaticText(Panel, ID_RECENTNAMETEXT, fileName, wxDefaultPosition, wxDefaultSize, 0, _T("ID_RECENTNAMETEXT"));
	RecentNameText->SetFont(RecentNameTextFont);
	RecentNameText->SetForegroundColour(wxColour(255,255,255));
	FlexGridSizer3->Add(RecentNameText, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
	wxFont DateLinkFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);	
	DateText = new wxStaticText(Panel, ID_DATETEXT, date, wxDefaultPosition, wxDefaultSize, 0, _T("ID_DATETEXT"));
	DateText->SetFont(DateLinkFont);
	DateText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer3->Add(DateText, 1, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	LinkText = new wxStaticText(Panel, ID_LINKTEXT, adjustRecentLink(link), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LINKTEXT"));
	LinkText->SetToolTip(link);
	LinkText->SetFont(DateLinkFont);
	LinkText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer3->Add(LinkText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	Panel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel);
	FlexGridSizer3->SetSizeHints(Panel);

	Panel->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelMouseEnter, 0, this);
	Panel->Connect(wxEVT_LEAVE_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelMouseLeave, 0, this);
	Panel->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&RecentPanel::OnRecentPanelLeftDown, 0, this);

	RecentNameText->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&RecentPanel::OnRecentPanelLeftDown, 0, this);
	DateText->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&RecentPanel::OnRecentPanelLeftDown, 0, this);
	LinkText->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&RecentPanel::OnRecentPanelLeftDown, 0, this);
	RecentBitmap->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&RecentPanel::OnRecentPanelLeftDown, 0, this);

	RecentNameText->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelChildEnter, 0, this);
	DateText->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelChildEnter, 0, this);
	LinkText->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelChildEnter, 0, this);
	RecentBitmap->Connect(wxEVT_ENTER_WINDOW, (wxObjectEventFunction)&RecentPanel::OnRecentPanelChildEnter, 0, this);
}

void RecentPanel::OnRecentPanelMouseEnter(wxMouseEvent& event)
{
	isOnRecentPanelChild = false;
	RecentNameText->SetForegroundColour(wxColour(*wxBLUE));
	RecentNameText->Refresh();
}

void RecentPanel::OnRecentPanelMouseLeave(wxMouseEvent& event)
{
	if (isOnRecentPanelChild == false) {
		RecentNameText->SetForegroundColour(wxColour(255, 255, 255));
		RecentNameText->Refresh();
	}
}

void RecentPanel::OnRecentPanelLeftDown(wxMouseEvent& event) {
	RecentNameText->SetLabelText("OPEN NEXT WINDOW");
	/***************************************************************
	*INSERT CODE FOR OPENING NEXT WINDOW
	**************************************************************/
}

void RecentPanel::OnRecentPanelChildEnter(wxMouseEvent& event) {
	isOnRecentPanelChild = true;
	RecentNameText->SetForegroundColour(wxColour(*wxBLUE));
	RecentNameText->Refresh();
}

wxString RecentPanel::adjustRecentLink(wxString link) {
	wxString shortLink = link;
	if (link.Len() > 60) {
		shortLink = link.SubString(0, 59) + "...";
	}
	return shortLink;
}
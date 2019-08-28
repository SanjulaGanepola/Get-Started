#ifndef RECENTPANEL_H
#define RECENTPANEL_H

//(*Headers(FilterDialog)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)


class RecentPanel : public wxPanel
{
public:
	RecentPanel(wxWindow *parent, int winid, wxString fileName, wxString date, wxString link, wxString bitmapLink);

private:
	bool isOnRecentPanelChild = false;

	void OnRecentPanelMouseEnter(wxMouseEvent& event);
	void OnRecentPanelMouseLeave(wxMouseEvent& event);
	void OnRecentPanelLeftDown(wxMouseEvent& event);
	void OnRecentPanelChildEnter(wxMouseEvent& event);
	wxString adjustRecentLink(wxString link);
	//*)

	//(*Identifiers(GetStartedDialog)
	static const long ID_RECENTBITMAP;
	static const long ID_RECENTNAMETEXT;
	static const long ID_DATETEXT;
	static const long ID_LINKTEXT;
	//*)

	//(*Declarations(GetStartedDialog)
	wxPanel* Panel;
	wxStaticBitmap* RecentBitmap;
	wxStaticText* DateText;
	wxStaticText* LinkText;
	wxStaticText* RecentNameText;
	//*)
};

#endif
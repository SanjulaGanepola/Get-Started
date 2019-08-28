#ifndef STARTPANEL_H
#define STARTPANEL_H

//(*Headers(FilterDialog)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)


class StartPanel : public wxPanel
{
public:
	StartPanel(wxWindow *parent, int winid, wxString bitmapLink, wxString StartName, wxString description);

private:
	bool isOnStartPanelChild = false;

	void OnStartPanelMouseEnter(wxMouseEvent& event);
	void OnStartPanelMouseLeave(wxMouseEvent& event);
	void OnStartPanelChildEnter(wxMouseEvent& event);
	void OnStartPanelLeftDown(wxMouseEvent& event);
	//*)

	//(*Identifiers(GetStartedDialog)
	static const long ID_STARTBITMAP;
	static const long ID_STARTNAMETEXT;
	static const long ID_STARTDESCRIPTIONTEXT;
	//*)

	//(*Declarations(GetStartedDialog)
	wxStaticBitmap* StartBitmap;
	wxStaticText* StartDescriptionText;
	wxStaticText* StartNameText;
	//*)
};

#endif
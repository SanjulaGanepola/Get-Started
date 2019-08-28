#ifndef PROFILE_H
#define PROFILE_H

//(*Headers(Profile)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Profile: public wxDialog
{
public:

	Profile(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);


private:

	//(*Handlers(Profile)
	void OnPasswordHyperLinkClick(wxCommandEvent& event);
	void OnEditButtonClick(wxCommandEvent& event);
	void OnSaveButtonClick(wxCommandEvent& event);
	//*)

	//(*Identifiers(Profile)
	static const long ID_PROFILETEXT;
	static const long ID_INSTRUCTIONTEXT;
	static const long ID_USERNAMEBITMAP;
	static const long ID_USERNAMECTRL;
	static const long ID_USERNAMEPANEL;
	static const long ID_EMAILBITMAP;
	static const long ID_EMAILCTRL;
	static const long ID_EMAILPANEL;
	static const long ID_PASSWORDHYPERLINK;
	static const long ID_EDITBUTTON;
	static const long ID_SAVEBUTTON;
	//*)
		
	//(*Declarations(Profile)
	wxButton* EditButton;
	wxButton* SaveButton;
	wxHyperlinkCtrl* PasswordHyperLink;
	wxPanel* EmailPanel;
	wxPanel* UsernamePanel;
	wxStaticBitmap* EmailBitmap;
	wxStaticBitmap* UsernameBitmap;
	wxStaticText* ProfileText;
	wxStaticText* InstructionText;
	wxTextCtrl* EmailCtrl;
	wxTextCtrl* UsernameCtrl;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif

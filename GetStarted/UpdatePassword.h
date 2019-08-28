#ifndef UPDATEPASSWORD_H
#define UPDATEPASSWORD_H

//(*Headers(UpdatePassword)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class UpdatePassword: public wxDialog
{
	public:

		UpdatePassword(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		//(*Declarations(UpdatePassword)
		wxButton* SaveButton;
		wxPanel* CurrentPasswordPanel;
		wxPanel* NewPasswordPanel;
		wxStaticBitmap* CurrentPasswordBitmap;
		wxStaticBitmap* NewPasswordBitmap;
		wxStaticText* InstructionText;
		wxStaticText* UpdatePasswordText;
		wxTextCtrl* CurrentPasswordCtrl;
		wxTextCtrl* NewPasswordCtrl;
		//*)

	protected:

		//(*Identifiers(UpdatePassword)
		static const long ID_UPDATEPASSWORDTEXT;
		static const long ID_INSTRUCTIONTEXT;
		static const long ID_CURRENTPASSWORDBITMAP;
		static const long ID_CURRENTPASSWORDCTRL;
		static const long ID_CURRENTPASSWORDPANEL;
		static const long ID_NEWPASSWORDBITMAP;
		static const long ID_NEWPASSWORDCTRL;
		static const long ID_NEWPASSWORDPANEL;
		static const long ID_SAVEBUTTON;
		//*)

	private:

		//(*Handlers(UpdatePassword)
		void OnSaveButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

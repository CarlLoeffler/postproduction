///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/splitter.h>
#include <wx/listbox.h>
#include <wx/editlbox.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/log.h>

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();
	
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void onOpenProject(wxCommandEvent& event);
	void onOpen(wxCommandEvent& event);
	void onSave(wxCommandEvent& event);
	void onSaveAs(wxCommandEvent& event);
	void onAddImage(wxCommandEvent& event);

	void onImgListRightClick(wxMouseEvent& event);
	void onImgListRenameImg(wxCommandEvent& event);
	void onImgListDeleteImg(wxCommandEvent& event);
	void onImgListOpenFileLocationImg(wxCommandEvent& event);

	void updateImageList();

protected:
	wxMenuBar* m_menubar1;
	wxMenu* fileMenu;
	wxMenu* editMenu;
	wxMenu* viewMenu;
	wxMenu* toolsMenu;
	wxToolBar* m_toolBar1;
	wxToolBarToolBase* m_tool1;
	wxToolBarToolBase* m_tool3;
	wxToolBarToolBase* m_tool2;
	wxStatusBar* m_statusBar1;
	wxSplitterWindow* topSplitter;
	wxPanel* leftPanel;
	wxSplitterWindow* leftSplitter;
	wxPanel* topLeftPanel;
	wxNotebook* mainDisplayNotebook;
	wxPanel* m_panel16;
	wxPanel* botLeftPanel;
	wxNotebook* stateNoteBook;
	wxPanel* nodeEditorPanel;
	wxPanel* logPanel;
	wxTextCtrl* logTextCtrl;
	wxPanel* rightPanel;
	wxSplitterWindow* rightSplitter;
	wxPanel* topRightPanel;
	wxListBox* imgListBox;
	wxPanel* botRightPanel;
	wxNotebook* controlsNotebook;
	wxPanel* nodePropPanel;
	wxPanel* displayOptPanel;
	wxLogTextCtrl* logCtrl;
	wxMenu *leftClickPopupMenu;

public:
	MainFrame(const wxString& title);
	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrame();

	void topSplitterOnIdle(wxIdleEvent&)
	{
		topSplitter->SetSashPosition(0);
		topSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::topSplitterOnIdle), NULL, this);
	}

	void leftSplitterOnIdle(wxIdleEvent&)
	{
		leftSplitter->SetSashPosition(0);
		leftSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::leftSplitterOnIdle), NULL, this);
	}

	void rightSplitterOnIdle(wxIdleEvent&)
	{
		rightSplitter->SetSashPosition(0);
		rightSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::rightSplitterOnIdle), NULL, this);
	}

};

// IDs for the controls and the menu commands
enum
{
	// menu items
	Open_Project = wxID_OPEN,
	Open_File = 2000,
	Save_File = wxID_SAVE,
	Save_As_File = wxID_SAVEAS,
	//Minimal_Quit = wxID_EXIT,
	Add_Image = 2001,
	imgListPopup_DeleteImg,
	imgListPopup_RenameImg,
	imgListPopup_OpenFileLocationImg

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	//Minimal_About = wxID_ABOUT
};


#endif //__NONAME_H__

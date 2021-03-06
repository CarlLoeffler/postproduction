/////////////////////////////////////////////////////////////////////////////
// Name:        main.cpp
// Purpose:     main file, I guess
// Author:      Carl Loeffler
// Created:     sometime before 7/26/2017
/////////////////////////////////////////////////////////////////////////////


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#include "ui_generated.h"

//My hacky bullshit
#include "state.h"
#include "uiLogic.h"

UIState* uiState;

// Define a new application type, each program should derive a class from wxApp
class MyApp : public wxApp
{
public:
	// override base class virtuals
	// ----------------------------

	// this one is called on application startup and is a good place for the app
	// initialization (doing it here and not in the ctor allows to have an error
	// return: if OnInit() returns false, the application terminates)
	virtual bool OnInit();
};

// Define a new frame type: this is going to be our main frame
class MyFrame : public wxFrame
{
public:
	// ctor(s)
	MyFrame(const wxString& title);

	// event handlers (these functions should _not_ be virtual)
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

private:
	// any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();
};

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------


// IDs for the controls and the menu commands
enum
{
	// menu items
	Minimal_Quit = wxID_EXIT,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	Minimal_About = wxID_ABOUT
};

// ----------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// ----------------------------------------------------------------------------

// the event tables connect the wxWidgets events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(Minimal_Quit, MyFrame::OnQuit)
	EVT_MENU(Minimal_About, MyFrame::OnAbout)

wxEND_EVENT_TABLE()

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP(MyApp)

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
	// call the base class initialization method, currently it only parses a
	// few common command-line options but it could be do more in the future
	if (!wxApp::OnInit())
		return false;

	// create the main application window
	//MyFrame *frame = new MyFrame("Postproduction");
	MainFrame *frame = new MainFrame("Postproduction");

	//Initialize my state objects
	uiState = new UIState();

	// and show it (the frames, unlike simple controls, are not shown when
	// created initially)
	frame->Show(true);

	// success: wxApp::OnRun() will be called which will enter the main message
	// loop and the application will run. If we returned false here, the
	// application would exit immediately.
	return true;
}

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// set the frame icon
	SetIcon(wxICON(sample));

	// create a menu bar
	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");

	// now append the freshly created menu to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	// create a status bar just for fun (by default with 1 pane only)
	CreateStatusBar(2);
	SetStatusText("Welcome to wxWidgets!");
}


// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxString::Format
		(
			"Welcome to %s!\n"
			"\n"
			"This is the minimal wxWidgets sample\n"
			"running under %s.",
			wxVERSION_STRING,
			wxGetOsDescription()
			),
		"About wxWidgets minimal sample",
		wxOK | wxICON_INFORMATION,
		this);
}
///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#include "ui_generated.h"

//Yep, doing this.
#include "state.h"

///////////////////////////////////////////////////////////////////////////
MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title){

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	m_menubar1 = new wxMenuBar(0);
	fileMenu = new wxMenu();

	wxMenuItem* newProjectMenuItem;
	newProjectMenuItem = new wxMenuItem(fileMenu, Open_Project, wxString(wxT("New Project")), wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(newProjectMenuItem);

	wxMenuItem* openMenuItem;
	openMenuItem = new wxMenuItem(fileMenu, Open_File, wxString(wxT("Open...")), wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(openMenuItem);

	wxMenuItem* saveMenuItem;
	saveMenuItem = new wxMenuItem(fileMenu, Save_File, wxString(wxT("Save")), wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(saveMenuItem);

	wxMenuItem* saveAsMenuItem;
	saveAsMenuItem = new wxMenuItem(fileMenu, Save_As_File, wxString(wxT("Save As...")), wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(saveAsMenuItem);

	wxMenuItem* addImageMenuItem;
	addImageMenuItem = new wxMenuItem(fileMenu, Add_Image, wxString(wxT("Add Image")), wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(addImageMenuItem);

	m_menubar1->Append(fileMenu, wxT("File"));

	editMenu = new wxMenu();
	m_menubar1->Append(editMenu, wxT("Edit"));

	viewMenu = new wxMenu();
	m_menubar1->Append(viewMenu, wxT("View"));

	toolsMenu = new wxMenu();
	m_menubar1->Append(toolsMenu, wxT("Tools"));

	this->SetMenuBar(m_menubar1);

	m_toolBar1 = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	
	//m_tool1 = m_toolBar1->AddTool(wxID_UNDO, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
	//m_tool3 = m_toolBar1->AddTool(wxID_REDO, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
	//m_tool2 = m_toolBar1->AddTool(wxID_SAVE, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	m_toolBar1->Realize();

	m_statusBar1 = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer(wxVERTICAL);

	topSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
	topSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::topSplitterOnIdle), NULL, this);

	leftPanel = new wxPanel(topSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* leftSizer;
	leftSizer = new wxBoxSizer(wxHORIZONTAL);

	leftSplitter = new wxSplitterWindow(leftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
	leftSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::leftSplitterOnIdle), NULL, this);

	topLeftPanel = new wxPanel(leftSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* topLeftSizer;
	topLeftSizer = new wxBoxSizer(wxVERTICAL);

	mainDisplayNotebook = new wxNotebook(topLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	m_panel16 = new wxPanel(mainDisplayNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer(wxVERTICAL);


	m_panel16->SetSizer(bSizer17);
	m_panel16->Layout();
	bSizer17->Fit(m_panel16);
	mainDisplayNotebook->AddPage(m_panel16, wxT("a page"), false);

	topLeftSizer->Add(mainDisplayNotebook, 1, wxEXPAND | wxALL, 5);


	topLeftPanel->SetSizer(topLeftSizer);
	topLeftPanel->Layout();
	topLeftSizer->Fit(topLeftPanel);
	botLeftPanel = new wxPanel(leftSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* botLeftSizer;
	botLeftSizer = new wxBoxSizer(wxVERTICAL);

	//state is bottom left segment of UI, currently holds node editor and log
	stateNoteBook = new wxNotebook(botLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	nodeEditorPanel = new wxPanel(stateNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	stateNoteBook->AddPage(nodeEditorPanel, wxT("Node Editor"), false);
	
	//Set up log display section
	logPanel = new wxPanel(stateNoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* logSizer;
	logSizer = new wxBoxSizer(wxVERTICAL);

	logTextCtrl = new wxTextCtrl(logPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	logTextCtrl->SetEditable(false);
	logCtrl = new wxLogTextCtrl(logTextCtrl);
	wxLog::SetActiveTarget(logCtrl);
	wxLogMessage("Starting log");

	logSizer->Add(logTextCtrl, 1, wxEXPAND, 5);

	logPanel->SetSizer(logSizer);
	logPanel->Layout();
	logSizer->Fit(logPanel);
	stateNoteBook->AddPage(logPanel, wxT("Log"), false);

	botLeftSizer->Add(stateNoteBook, 1, wxEXPAND | wxALL, 5);

	

	botLeftPanel->SetSizer(botLeftSizer);
	botLeftPanel->Layout();
	botLeftSizer->Fit(botLeftPanel);
	leftSplitter->SplitHorizontally(topLeftPanel, botLeftPanel, 0);
	leftSizer->Add(leftSplitter, 1, wxEXPAND, 5);


	leftPanel->SetSizer(leftSizer);
	leftPanel->Layout();
	leftSizer->Fit(leftPanel);
	rightPanel = new wxPanel(topSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* rightSizer;
	rightSizer = new wxBoxSizer(wxHORIZONTAL);

	rightSplitter = new wxSplitterWindow(rightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
	rightSplitter->Connect(wxEVT_IDLE, wxIdleEventHandler(MainFrame::rightSplitterOnIdle), NULL, this);

	topRightPanel = new wxPanel(rightSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* topRightSizer;
	topRightSizer = new wxBoxSizer(wxVERTICAL);

	imgListBox = new wxListBox(topRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	topRightSizer->Add(imgListBox, 1, wxALL | wxEXPAND, 5);


	topRightPanel->SetSizer(topRightSizer);
	topRightPanel->Layout();
	topRightSizer->Fit(topRightPanel);
	botRightPanel = new wxPanel(rightSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* botRightSizer;
	botRightSizer = new wxBoxSizer(wxVERTICAL);

	controlsNotebook = new wxNotebook(botRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	nodePropPanel = new wxPanel(controlsNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* propertiesSizer;
	propertiesSizer = new wxBoxSizer(wxVERTICAL);


	nodePropPanel->SetSizer(propertiesSizer);
	nodePropPanel->Layout();
	propertiesSizer->Fit(nodePropPanel);
	controlsNotebook->AddPage(nodePropPanel, wxT("Properties"), false);
	displayOptPanel = new wxPanel(controlsNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* displayOptSizer;
	displayOptSizer = new wxBoxSizer(wxVERTICAL);


	displayOptPanel->SetSizer(displayOptSizer);
	displayOptPanel->Layout();
	displayOptSizer->Fit(displayOptPanel);
	controlsNotebook->AddPage(displayOptPanel, wxT("Display"), false);

	botRightSizer->Add(controlsNotebook, 1, wxEXPAND | wxALL, 5);


	botRightPanel->SetSizer(botRightSizer);
	botRightPanel->Layout();
	botRightSizer->Fit(botRightPanel);
	rightSplitter->SplitHorizontally(topRightPanel, botRightPanel, 0);
	rightSizer->Add(rightSplitter, 1, wxEXPAND, 5);


	rightPanel->SetSizer(rightSizer);
	rightPanel->Layout();
	rightSizer->Fit(rightPanel);
	topSplitter->SplitVertically(leftPanel, rightPanel, 0);
	topSizer->Add(topSplitter, 1, wxEXPAND, 5);


	this->SetSizer(topSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

MainFrame::~MainFrame()
{
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	//	EVT_MENU(Minimal_Quit, MainFrame::OnQuit)
	//	EVT_MENU(Minimal_About, MainFrame::OnAbout)
	EVT_MENU(Open_Project, MainFrame::onOpenProject)
	EVT_MENU(Open_File, MainFrame::onOpen)
	EVT_MENU(Save_File, MainFrame::onSave)
	EVT_MENU(Save_As_File, MainFrame::onSaveAs)
	EVT_MENU(Add_Image, MainFrame::onAddImage)
wxEND_EVENT_TABLE()

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(
		wxString::Format(
			"Welcome to %s!\n"
			"\n"
			"This is the minimal wxWidgets sample\n"
			"running under %s.",
			wxVERSION_STRING,
			wxGetOsDescription()
		),
		"About wxWidgets minimal sample",
		wxOK | wxICON_INFORMATION,
		this
	);
}

void MainFrame::onOpenProject(wxCommandEvent& event) {
	wxLogMessage("New Project event");
}

void MainFrame::onOpen(wxCommandEvent& event) {
	wxLogMessage("Open event");
}

void MainFrame::onSave(wxCommandEvent& event) {
	wxLogMessage("Save event");
}

void MainFrame::onSaveAs(wxCommandEvent& event) {
	wxLogMessage("Save As event");
}

void MainFrame::onAddImage(wxCommandEvent& event) {
	wxLogMessage("Add Image event");
	uiState->addImage(new PPImg());
	updateImageList();
}

//This is a bit shitty, but it's a consequence of me not just using the wx classes to hold my data
//Clears the contents of the listBox and rebuilds it using the backend state object
void MainFrame::updateImageList() {
	imgListBox->Clear();
	std::vector<PPImg*>* state = uiState->getImageList();
	for (int i = 0; i < state->size(); i++) {
		if ((*state)[i] != NULL) {
			imgListBox->Append(wxString((*state)[i]->getName()));
		}
	}
}
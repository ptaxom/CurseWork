#include "MainFrame.h"
#include "../VideoPane/VideoCanvas.h"

namespace Frame {

    MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Webcam Handler")
    {
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H",
            "Help string shown in status bar for this menu item");

        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);

        wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        menuFile->AppendSeparator();
        menuHelp->Append(ID_INFO, "&Show info\tCtrl-Y");


        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");

        SetMenuBar(menuBar);
        CreateStatusBar();
        SetStatusText("Welcome to WebcamHandler!");

        VideoCanvas *canvas = new VideoCanvas(this);


        Bind(wxEVT_MENU, &Frame::MainFrame::OnHello, this, ID_HELLO);
        Bind(wxEVT_MENU, &Frame::MainFrame::OnAbout, this, wxID_ABOUT);
        Bind(wxEVT_MENU, &Frame::MainFrame::OnExit, this, wxID_EXIT);
        Bind(wxEVT_MENU, &Frame::MainFrame::OnShowInfo, this, ID_INFO);

    }

    void MainFrame::OnHello(wxCommandEvent & event)
    {
        wxLogMessage("Hello world from wxWidgets!");
    }

    void MainFrame::OnExit(wxCommandEvent & event)
    {
        Close(true);
    }

    void MainFrame::OnAbout(wxCommandEvent & event)
    {
        wxMessageBox("This is a wxWidgets Hello World example",
            "About Hello World", wxOK | wxICON_INFORMATION);
    }

    void MainFrame::OnShowInfo(wxCommandEvent & event)
    {
        wxMessageBox("Info",
            "About Info", wxOK | wxICON_INFORMATION);
    }


}

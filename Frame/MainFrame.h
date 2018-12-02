#pragma once
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

namespace Frame {

    enum
    {
        ID_HELLO = 1,
        ID_EXIT = 2,
        ID_ABOUT = 3,
        ID_INFO = 4
    };

    class MainFrame : public wxFrame
    {
    public:
        MainFrame();

    private:
        void OnHello(wxCommandEvent &event);
        void OnExit(wxCommandEvent &event);
        void OnAbout(wxCommandEvent &event);
        void OnShowInfo(wxCommandEvent &event);
    };



}

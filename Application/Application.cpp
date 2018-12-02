//Don't change
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif


#include "Frame/MainFrame/MainFrame.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Frame::MainFrame *frame = new Frame::MainFrame();
    frame->Show(true);
    return true;
}

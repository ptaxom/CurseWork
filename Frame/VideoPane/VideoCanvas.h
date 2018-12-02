#pragma once
#include <wx/wx.h>


class VideoCanvas : public wxWindow
{
public:
    VideoCanvas(wxWindow *parent);

    void OnPaint(wxPaintEvent &event);

private:

    void Render(wxDC &dc);

    
    wxDECLARE_EVENT_TABLE();
};

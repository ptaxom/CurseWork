#include "VideoCanvas.h"

wxBEGIN_EVENT_TABLE(VideoCanvas, wxWindow)
    EVT_PAINT(VideoCanvas::OnPaint)
wxEND_EVENT_TABLE()

VideoCanvas::VideoCanvas(wxWindow *parent)
    : wxWindow(parent, wxID_ANY, wxPoint(0, 0), wxSize(300, 200), wxSUNKEN_BORDER)
{}

void VideoCanvas::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    Render(dc);
}


void VideoCanvas::Render(wxDC&  dc)
{
    dc.DrawText(wxT("Testing"), 40, 60);

    dc.SetBrush(*wxGREEN_BRUSH); 
    dc.SetPen(wxPen(wxColor(255, 0, 0), 5)); 
    dc.DrawCircle(wxPoint(200, 100), 25 );

    dc.SetBrush(*wxBLUE_BRUSH); 
    dc.SetPen(wxPen(wxColor(255, 175, 175), 10)); 
    dc.DrawRectangle(300, 100, 400, 200);


    dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); 
    dc.DrawLine(300, 100, 700, 300); 


}

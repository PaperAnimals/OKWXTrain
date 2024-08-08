#pragma once

#include <wx/wx.h>

class BottomPanel : public wxPanel {
public:
  explicit BottomPanel(wxWindow* parent);
private:
  wxBoxSizer* bottom_sizer = new wxBoxSizer(wxHORIZONTAL);
};

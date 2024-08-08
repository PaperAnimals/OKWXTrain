#pragma once

#include "UITools/UIHelpers/UIConstants.h"

#include <wx/wx.h>

class Bar : public wxPanel {
public:
  Bar(bool vertical, wxWindow* parent, wxWindowID ID=wxID_ANY, const wxPoint& pos=wxDefaultPosition) : wxPanel(parent, ID, pos) {
    SetBackgroundColour(CONSTS::StyleConsts::Colours::BAR_COLOUR);
    setOrientation(vertical);
  }
  
private:
  void setOrientation(bool vertical) {
    namespace CSS = CONSTS::SizingConsts::Sizes;
    if (vertical) {
      SetMinSize(wxSize(CSS::BAR_WIDTH, CSS::MAIN_PANEL_HEIGHT));
      SetMaxSize(wxSize(CSS::BAR_WIDTH, CSS::MAIN_PANEL_HEIGHT));
    } else {
      SetMinSize(wxSize(CSS::FRAME_WIDTH, CSS::BAR_WIDTH));
      SetMaxSize(wxSize(CSS::FRAME_WIDTH, CSS::BAR_WIDTH));
    }
  }
};

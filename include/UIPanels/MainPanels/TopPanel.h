#pragma once

#include "UITools/UIHelpers/UIConstants.h"
#include "UITools/UIControllers/TopPanelSelector.h"

#include <wx/wx.h>
#include <string>

class TopPanel : public wxPanel {
private:
  wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* top_grid = new wxGridSizer(1,5,
    CONSTS::SizingConsts::Sizes::TOP_PANEL_HEIGHT/2,0);
  std::string headers_arr[5] = {"BRD", "MAP", "THR", "FOR", "FIV"};
  wxStaticText* header_win_arr[5] = {};
  std::unique_ptr<Selector> selector_ptr = nullptr;
  
  void onKeyDown(wxKeyEvent& event);
  void createHeaderText();
  void receiveFocus(wxFocusEvent& event);
public:
  explicit TopPanel(wxWindow* parent);
  wxStaticText** getHeaderWinArr() {return header_win_arr;}
};

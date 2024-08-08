#include "UIPanels/MainPanels/LeftPanel.h"

LeftPanel::LeftPanel(wxWindow* parent) : wxPanel(parent) {
  namespace CSS = CONSTS::SizingConsts::Sizes;
  SetMaxSize(wxSize(CSS::LEFT_PANEL_WIDTH, CSS::MAIN_PANEL_HEIGHT));
  SetMinSize(wxSize(CSS::LEFT_PANEL_WIDTH, CSS::MAIN_PANEL_HEIGHT));
  SetBackgroundColour(CONSTS::StyleConsts::Colours::LEFT_PANEL_BLACK);
  left_sizer->Add(user_prim_book, 1, wxEXPAND, 0);
  SetSizer(left_sizer);
}

UserPrimaryBook* LeftPanel::getUserPrimBook() {
  return user_prim_book;
}

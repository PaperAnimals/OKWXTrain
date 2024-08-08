#include "UIPanels/MainPanels/RightPanel.h"
#include "UITools/UIHelpers/UIConstants.h"

RightPanel::RightPanel(wxWindow* parent) : wxPanel(parent) {
  namespace CSS = CONSTS::SizingConsts::Sizes;
  SetMaxSize(wxSize(CSS::RIGHT_PANEL_WIDTH, CSS::MAIN_PANEL_HEIGHT));
  SetMinSize(wxSize(CSS::RIGHT_PANEL_WIDTH, CSS::MAIN_PANEL_HEIGHT));
  SetBackgroundColour(CONSTS::StyleConsts::Colours::RIGHT_PANEL_BLUE);
  right_sizer->Add(info_sec_book, 1, wxEXPAND, 0);
  SetSizer(right_sizer);
}

InfoSecondBook* RightPanel::getInfoBook() {
  return info_sec_book;
}

#include "UIPanels/MainPanels/BottomPanel.h"
#include "UITools/UIHelpers/UIConstants.h"

BottomPanel::BottomPanel (wxWindow* parent) : wxPanel(parent) {
  namespace CSS = CONSTS::SizingConsts::Sizes;
  SetMaxSize(wxSize(CSS::FRAME_WIDTH, CSS::BOTTOM_PANEL_HEIGHT));
  SetMinSize(wxSize(CSS::FRAME_WIDTH, CSS::BOTTOM_PANEL_HEIGHT));
  SetBackgroundColour(CONSTS::StyleConsts::Colours::BOTTOM_PANEL_GREY);
  SetSizer(bottom_sizer);
}

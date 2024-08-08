#pragma once

#include "UIPanels/MainPanels/TopPanel.h"
#include "UIPanels/MainPanels/LeftPanel.h"
#include "UIPanels/MainPanels/RightPanel.h"
#include "UIPanels/MainPanels/BottomPanel.h"
#include "UIPanels/MainPanels/Bar.h"
#include "UITools/UIControllers/SwitchboardOperator.h"

#include <wx/wx.h>


class MainScreen : public wxFrame {
private:
  wxBoxSizer* page_sizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* centre_sizer = new wxBoxSizer(wxHORIZONTAL);
  LeftPanel* left_panel = new LeftPanel(this);
  RightPanel* right_panel = new RightPanel(this);
  TopPanel* top_panel = new TopPanel(this);
  BottomPanel* bottom_panel = new BottomPanel(this);
  Bar* top_bar = new Bar(false, this);
  Bar* mid_bar = new Bar(true, this);
  Bar* bot_bar = new Bar(false, this); // Move all this to the constructor
  SwitchboardOperator switchboard_op {};
  
  void onKeyPropagation(wxCommandEvent& event);
  void onNavigatePropagation(wxCommandEvent& event);
  void onSimplePageChange(wxBookCtrlEvent& event);
  void onSelectPage(const wxCommandEvent& event);
  
public:
  MainScreen();
};

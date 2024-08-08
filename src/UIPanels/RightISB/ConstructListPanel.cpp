#include "UIPanels/RightISB/ConstructListPanel.h"
#include "UITools/UIHelpers/UIConstants.h"
#include <string>

ConstructListPanel::ConstructListPanel(wxWindow* parent) : wxPanel(parent) {
  createBuildingItems();
  SetSizer(construct_sizer);
  constr_lis_sel = std::make_unique<ConstructListSelector>(getBuildPanels());
  Bind(wxEVT_CHAR, &ConstructListPanel::onKeyPress, this);
}

void ConstructListPanel::createBuildingItems() {
  int i = 0;
  do {
    auto* panel = new wxPanel(this);
    auto* box_sizer = new wxBoxSizer(wxVERTICAL);
    auto* cost_txt = new wxStaticText(panel, wxID_ANY, std::to_string(build_item->cost),
      wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    cost_txt->SetFont(CONSTS::StyleConsts::Text::MAIN_HEAD_FONT);
    box_sizer->Add(cost_txt, 0, wxALIGN_LEFT, 5);
    auto* item_txt = new wxStaticText(panel, wxID_ANY, build_item->name, wxDefaultPosition,
      wxDefaultSize, wxALIGN_LEFT);
    item_txt->SetFont(CONSTS::StyleConsts::Text::MAIN_HEAD_FONT);
    box_sizer->Add(item_txt, 0, wxALIGN_LEFT, 5);
    panel->SetSizer(box_sizer);
    construct_sizer->Add(panel, 0,
      wxEXPAND | wxALIGN_CENTRE_VERTICAL | wxRIGHT | wxLEFT | wxTOP, 15);
    panel_arr[i] = panel;
    ++i;
    ++build_item;
  } while (build_item->name != nullptr);
}
                
void ConstructListPanel::onKeyPress(wxKeyEvent& event) {
  constr_lis_sel->onKeyPress(event);
  Layout();
}

std::unique_ptr<std::vector<wxPanel*>> ConstructListPanel::getBuildPanels() {
  return std::make_unique<std::vector<wxPanel*>>(panel_arr, panel_arr+4);
}

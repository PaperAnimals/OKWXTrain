#include "UIPanels/RightISB/BoardDataPanel.h"
#include "UITools/UIHelpers/UIConstants.h"

#include <string>

BoardDataPanel::BoardDataPanel(wxWindow* parent) : wxPanel(parent) {
  data_grid->SetFlexibleDirection(wxHORIZONTAL);
  createGridItems();
  SetSizer(data_grid);
}

void BoardDataPanel::createGridItems() {
  for (int i=1; i<11; ++i) {
    auto* text = new wxStaticText(this, wxID_ANY, std::to_string(i) + ".", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    text->SetFont(CONSTS::StyleConsts::Text::MAIN_HEAD_FONT);
    data_grid->Add(text, 0, wxALIGN_LEFT | wxALIGN_CENTRE_VERTICAL);
    text = new wxStaticText(this, wxID_ANY, "TRAINS", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    text->SetFont(CONSTS::StyleConsts::Text::MAIN_HEAD_FONT);
    data_grid->Add(text, 1, wxALIGN_LEFT | wxALIGN_CENTRE_VERTICAL);
  }
}

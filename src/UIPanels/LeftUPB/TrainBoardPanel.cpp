#include "UIPanels/LeftUPB/TrainBoardPanel.h"
#include "UITools/UIHelpers/UIConstants.h"
#include "UITools/UIHelpers/CustomEvent.h"

TrainBoardPanel::TrainBoardPanel(wxWindow* parent) : wxPanel(parent) {
  createHeaders();
  SetSizer(train_board);
  Bind(wxEVT_CHAR_HOOK, &TrainBoardPanel::propagateNavigation, this);
}

void TrainBoardPanel::createHeaders() {
  for (const wxString& header_txt : board_headers) {
    auto* header = new wxStaticText(this, wxID_ANY, header_txt, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    header->SetFont(CONSTS::StyleConsts::Text::MAIN_HEAD_FONT);
    header->SetForegroundColour(CONSTS::StyleConsts::Colours::LEFT_TEXT_YELLOW);
    train_board->Add(header, 1, wxALIGN_CENTRE, 0);
  }
}

std::optional<std::reference_wrapper<std::array<wxStaticText*, 4>>> TrainBoardPanel::getGridRow(const int index) {
  if (0 <= index && index < grid_items.size()) {
    return grid_items[index];
  } else {
    return std::nullopt;
  }
}

void TrainBoardPanel::propagateNavigation(wxKeyEvent& event) {
  if (event.GetKeyCode()==WXK_ESCAPE) {
    wxCommandEvent new_evt(EVT_NAVIGATE_TOP);
    ProcessEvent(new_evt);
  }
}

#include "UIPanels/MainPanels/MainScreen.h"
#include "UITools/UIHelpers/UIConstants.h"
#include "UITools/UIHelpers/CustomEvent.h"

#include <optional>

MainScreen::MainScreen()
  : wxFrame(nullptr, wxID_ANY, "Hello, World!") {
    SetSize(CONSTS::SizingConsts::Sizes::FRAME_WIDTH, CONSTS::SizingConsts::Sizes::FRAME_HEIGHT);
    Centre();
    page_sizer->Add(top_panel, 0, wxEXPAND);
    page_sizer->Add(top_bar, 0, wxEXPAND);
    centre_sizer->Add(left_panel, 1, wxEXPAND, 0);
    centre_sizer->Add(mid_bar, 1, wxEXPAND, 0);
    centre_sizer->Add(right_panel);
    page_sizer->Add(centre_sizer, 1, wxEXPAND, 0);
    page_sizer->Add(bot_bar, 1, wxEXPAND);
    page_sizer->Add(bottom_panel, 1, wxEXPAND, 0);
    SetSizer(page_sizer);
    top_panel->SetFocus();
    Bind(EVT_PROPAGATE_CHAR, &MainScreen::onKeyPropagation, this);
    Bind(EVT_NAVIGATE_TOP, &MainScreen::onNavigatePropagation, this);
    Bind(EVT_CHANGE_PAGE, &MainScreen::onSelectPage, this);
}

void MainScreen::onKeyPropagation(wxCommandEvent& event) {
  if (const std::optional<wxKeyEvent> new_evt = switchboard_op.handleKeyPropagation(event)) {
    wxPostEvent(right_panel->getInfoBook()->GetPage(1), *new_evt);
  }
}

void MainScreen::onNavigatePropagation(wxCommandEvent& event) {
  switchboard_op.updateActiveFocus();
  switchboard_op.navigateTopSelector(top_panel);
  event.Skip();
}

void MainScreen::onSelectPage(const wxCommandEvent& event) {
  switchboard_op.changePage(event.GetInt(), left_panel->getUserPrimBook(), right_panel->getInfoBook());
}

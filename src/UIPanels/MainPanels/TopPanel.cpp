#include "UIPanels/MainPanels/TopPanel.h"

TopPanel::TopPanel(wxWindow* parent) : wxPanel(parent) {
  namespace CSS = CONSTS::SizingConsts::Sizes;
  SetMaxSize(wxSize(CSS::FRAME_WIDTH, CSS::TOP_PANEL_HEIGHT));
  SetMinSize(wxSize(CSS::FRAME_WIDTH, CSS::TOP_PANEL_HEIGHT));
  SetBackgroundColour(CONSTS::StyleConsts::Colours::TOP_PANEL_BLUE);
  createHeaderText();
  SetSizer(top_sizer);
  selector_ptr = std::make_unique<Selector>(getHeaderWinArr());
  Bind(wxEVT_KEY_DOWN, &TopPanel::onKeyDown, this);
  Bind(wxEVT_SET_FOCUS, &TopPanel::receiveFocus, this);
}

void TopPanel::createHeaderText() {
  int ind {0};
  for (auto& header_text : headers_arr) {
    auto* header = new wxStaticText(this, wxID_ANY, header_text, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    header->SetFont(CONSTS::StyleConsts::Text::MENU_FONT);
    header->SetForegroundColour(CONSTS::StyleConsts::Colours::MENU_TEXT_GREY);
    header->SetMinSize(wxSize(CONSTS::StyleConsts::Text::MENU_TEXT_SIZE*3+5,CONSTS::StyleConsts::Text::MENU_TEXT_SIZE+7));
    top_grid->Add(header, 1, wxALIGN_CENTRE | wxALL, CONSTS::SizingConsts::Sizes::TOP_PANEL_HEIGHT/2);
    header_win_arr[ind++] = header;
  }
  top_sizer->Add(top_grid, 0, wxEXPAND, 0);
}

void TopPanel::onKeyDown(wxKeyEvent& event) {
  int key_code = event.GetKeyCode();
  switch (key_code) {
    case WXK_RETURN:
      selector_ptr->changePage(this);
      break;
    case WXK_LEFT:
    case WXK_RIGHT:
      selector_ptr->onDirectionKeyPress(key_code);
      break;
    default:
      break;
  }
  event.Skip();
}

void TopPanel::receiveFocus(wxFocusEvent& event) {
  selector_ptr->updateCurrentSelection();
  event.Skip();
}

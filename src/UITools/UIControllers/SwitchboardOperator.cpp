#include "UITools/UIControllers/SwitchboardOperator.h"

SwitchboardOperator::SwitchboardOperator() = default;

std::optional<wxKeyEvent> SwitchboardOperator::handleKeyPropagation(wxCommandEvent& event) {
  switch (current_pan) {
    case ActiveFocus::LEFT_MAP: {
      wxKeyEvent new_evt(wxEVT_CHAR);
      new_evt.SetId(event.GetInt());
      return new_evt;
    }
    case ActiveFocus::TOP:
      return std::nullopt;
    default:
      return std::nullopt;
  }
}

void SwitchboardOperator::updateActiveFocus() {
  switch (current_pan) {
    case ActiveFocus::TOP:
      current_pan = ActiveFocus::LEFT_MAP;
      break;
    case ActiveFocus::LEFT_MAP:
      current_pan = ActiveFocus::TOP;
      break;
  }
}

void SwitchboardOperator::navigateTopSelector(wxWindow* window) { // consider making a template
  window->SetFocus();
}

void SwitchboardOperator::changePage(int key_code, wxSimplebook* left_book, wxSimplebook* right_book) {
  updateActiveFocus();
  left_book->SetSelection(key_code);
  right_book->SetSelection(key_code);
  left_book->SetFocus();
}

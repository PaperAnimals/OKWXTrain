#include "UITools/UIControllers/TopPanelSelector.h"
#include "UITools/UIHelpers/UIConstants.h"
#include "UITools/UIHelpers/CustomEvent.h"

Selector::Selector(wxStaticText** selections_init) {
  selections = selections_init;
}

void Selector::onDirectionKeyPress(int key_code) {
  switch (key_code) {
    case WXK_LEFT:
      moveCursorLeft();
      break;
    case WXK_RIGHT:
      moveCursorRight();
      break;
    default:
      break;
  }
}

void Selector::moveCursorLeft() {
  if (selection_focus != 0) {
    resetPreviousSelection();
    --selection_focus;
    updateCurrentSelection();
    selections[selection_focus]->Refresh();
  }
}

void Selector::moveCursorRight() {
  if (selection_focus!=selections_max) {
    resetPreviousSelection();
    ++selection_focus;
    updateCurrentSelection();
    selections[selection_focus]->Refresh();
  }
}

void Selector::resetPreviousSelection() {
  selections[selection_focus]->SetBackgroundColour(CONSTS::StyleConsts::Colours::TOP_PANEL_BLUE);
  selections[selection_focus]->SetForegroundColour(CONSTS::StyleConsts::Colours::MENU_TEXT_GREY);
}

void Selector::updateCurrentSelection() {
  selections[selection_focus]->SetBackgroundColour(*wxBLACK);
  selections[selection_focus]->SetForegroundColour(CONSTS::StyleConsts::Colours::TOP_SEL_TEXT_RED);
}

void Selector::changePage(wxWindow* parent) {
  selections[selection_focus]->SetBackgroundColour(CONSTS::StyleConsts::Colours::TOP_SEL_TEXT_RED);
  selections[selection_focus]->SetForegroundColour(*wxBLACK);
  if (selection_focus < 2) {
    wxCommandEvent new_evt(EVT_CHANGE_PAGE);
    new_evt.SetInt(selection_focus);
    wxPostEvent(parent, new_evt);
  }
}

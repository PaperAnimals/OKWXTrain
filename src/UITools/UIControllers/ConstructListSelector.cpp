#include "UITools/UIControllers/ConstructListSelector.h"
#include "UITools/UIHelpers/UIConstants.h"

ConstructListSelector::ConstructListSelector(std::unique_ptr<std::vector<wxPanel*>> panel_arr) : build_panels_ptr(std::move(panel_arr)), build_ref(*build_panels_ptr) {
  build_ref[index]->SetBackgroundColour(CONSTS::StyleConsts::Colours::CONSTR_HIGHLIGHT_YELLOW);
}

void ConstructListSelector::updatePanelVec(std::unique_ptr<std::vector<wxPanel*>> panel_arr) {
  build_panels_ptr = std::move(panel_arr);
}

void ConstructListSelector::onKeyPress(wxKeyEvent& event) {
  int key_code = event.GetId();
  switch (key_code) {
    case WXK_LEFT:
      if (index % 2) {
        updateIndex(-1);
      }
      break;
    case WXK_RIGHT:
      if (!(index % 2)) {
        updateIndex(1);
      }
      break;
    case WXK_DOWN:
      updateIndex(2);
      break;
    case WXK_UP:
      updateIndex(-2);
      break;
    case WXK_RETURN:
      onReturnPress();
      break;
    case WXK_BACK:
      onBackPress();
      break;
    default:
      break;
  }
}

void ConstructListSelector::updateIndex(int d_index) {
  if (index + d_index >= 0 && index + d_index <= build_ref.size()-1) {
    resetPanel();
    index += d_index;
    updatePanel();
  }
}

void ConstructListSelector::resetPanel() {
  build_ref[index]->SetBackgroundColour(CONSTS::StyleConsts::Colours::RIGHT_PANEL_BLUE);
  for (auto& window : build_ref[index]->GetSizer()->GetChildren()) {
    window->GetWindow()->SetForegroundColour(*wxBLACK);
  }
  build_ref[index]->Refresh();
}

void ConstructListSelector::updatePanel() {
  build_ref[index]->SetBackgroundColour(CONSTS::StyleConsts::Colours::CONSTR_HIGHLIGHT_YELLOW);
  for (auto& window : build_ref[index]->GetSizer()->GetChildren()) {
    window->GetWindow()->SetForegroundColour(wxColour(CONSTS::StyleConsts::Colours::CONSTR_HIGH_TEXT_RED));
  }
  build_ref[index]->Refresh();
}

void ConstructListSelector::onReturnPress() {
  if (!is_selected) {
    build_ref[index]->SetBackgroundColour(CONSTS::StyleConsts::Colours::CONSTR_SELECTION_RED);
    for (auto& window : build_ref[index]->GetSizer()->GetChildren()) {
      window->GetWindow()->SetForegroundColour(wxColour(CONSTS::StyleConsts::Colours::CONSTR_SEL_TEXT_YELLOW));
    }
    is_selected = !is_selected;
    build_ref[index]->Refresh();
  }
}

void ConstructListSelector::onBackPress() {
  if (is_selected) {
    build_ref[index]->SetBackgroundColour(CONSTS::StyleConsts::Colours::CONSTR_HIGHLIGHT_YELLOW);
    for (auto& window : build_ref[index]->GetSizer()->GetChildren()) {
      window->GetWindow()->SetForegroundColour(wxColour(CONSTS::StyleConsts::Colours::CONSTR_HIGH_TEXT_RED));
    }
    is_selected = !is_selected;
    build_ref[index]->Refresh();
  }
}

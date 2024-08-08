#include "UITools/UIControllers/HexGridManager.h"
#include "UIPanels/Dialogs/CreationDialog.h"

HexGridManager::HexGridManager(std::unique_ptr<std::vector<std::vector<HexagonalPair*>>> hex_vec) : hex_vec(std::move(hex_vec)) {
  hex_ref[y_index][x_index]->getHexBorder()->setBrushColour(basic_colour);

}

void HexGridManager::onKeyPressSelection(int key_code) {
  switch (key_code) {
    case 'W':
      setSelection(0, -2);
      break;
    case 'A':
      setSelection(y_index % 2 ? 0 : -1, y_index % 2 ? -1 : 1);
      break;
    case 'S':
      setSelection(0, 2);
      break;
    case 'D':
      setSelection(y_index % 2 ? 1 : 0, y_index % 2 ? -1 : 1);
      break;
    default:
      break;
  }
}

void HexGridManager::setSelection(int dx, int dy) {
  bool inbound_value {false};
  if (dx) {
    inbound_value = isValidXMove(dx);
  } else {
    inbound_value = isValidYMove(dy);
  }
  if (inbound_value) {
    resetPrevSelection();
    y_index += dy;
    x_index += dx;
    hex_ref[y_index][x_index]->getHexBorder()->setBrushColour(current_colour);
  }
}

void HexGridManager::resetPrevSelection() {
  hex_ref[y_index][x_index]->getHexBorder()->setBrushColour(wxTRANSPARENT_BRUSH);
}

bool HexGridManager::isValidXMove(int d_value) const {
  return (x_index+d_value >= 0 && x_index+d_value < X_MAX);
}

bool HexGridManager::isValidYMove(int d_value) const {
  return (y_index+d_value >= 0 && y_index+d_value < Y_MAX);
}

void HexGridManager::onReturnPress() {
  current_colour = highlight_colour;
  hex_ref[y_index][x_index]->getHexBorder()->setBrushColour(current_colour);
}

void HexGridManager::onBackPress() {
  current_colour = basic_colour;
  hex_ref[y_index][x_index]->getHexBorder()->setBrushColour(current_colour);
}

void HexGridManager::onReturnCreate(wxWindow* parent) {
  wxString stri {"Station"};
  auto* create_dia = new CreationDialog(stri, parent);
  create_dia->ShowModal();
}

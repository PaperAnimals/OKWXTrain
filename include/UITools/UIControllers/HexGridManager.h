#pragma once

#include "UIPanels/LeftUPB/HexagonalGrid.h"
#include "UITools/UIHelpers/UIConstants.h"
#include <wx/wx.h>
#include <vector>

class HexGridManager {
  const int X_MAX {CONSTS::SizingConsts::Sizes::HexGrid::NUM_COLS};
  const int Y_MAX {CONSTS::SizingConsts::Sizes::HexGrid::NUM_ROWS};
  int x_index {};
  int y_index {};
  const wxBrush* basic_colour {&CONSTS::StyleConsts::Colours::HEX_HIGHLIGHT_YELLOW_BRUSH};
  const wxBrush* highlight_colour {&CONSTS::StyleConsts::Colours::HEX_SELECTION_RED_BRUSH};
  const wxBrush* current_colour {basic_colour};
  
  std::unique_ptr<std::vector<std::vector<HexagonalPair*>>> hex_vec {};
  std::vector<std::vector<HexagonalPair*>>& hex_ref = *hex_vec;
public:
  explicit HexGridManager(std::unique_ptr<std::vector<std::vector<HexagonalPair*>>> hex_vec);
  void onKeyPressSelection(int key_code);
  void setSelection(int dx, int dy);
  void resetPrevSelection();
  bool isValidXMove(int d_value) const;
  bool isValidYMove(int d_value) const;
  void onReturnPress();
  void onBackPress();
  void onReturnCreate(wxWindow* parent);
};

#pragma once

#include "UIPanels/LeftUPB/HexagonalGrid.h"
#include "UITools/UIControllers/HexGridManager.h"

#include <wx/wx.h>

class StationMapPanel : public wxPanel {
  HexagonalGridPanel* hex_panel = new HexagonalGridPanel(this);
  wxBoxSizer* station_map_sizer = new wxBoxSizer(wxVERTICAL);
  HexGridManager hex_manager;
  
  bool lock_dir_keys {false};
public:
  explicit StationMapPanel(wxWindow* parent);
  void onKeyPressSelection(wxKeyEvent& event);
  void propagateCharEvent(int key_code);
  void propagateNavigateEvent();
};

#include "UIPanels/LeftUPB/StationMapPanel.h"

#include "UITools/UIHelpers/CustomEvent.h"

#include <iostream>

StationMapPanel::StationMapPanel(wxWindow* parent) : wxPanel(parent), hex_manager(hex_panel->getHexArray()) {
  station_map_sizer->Add(hex_panel);
  SetBackgroundColour(wxColour(80,80,80)); // make consts
  SetSizer(station_map_sizer);
  Bind(wxEVT_CHAR_HOOK, &StationMapPanel::onKeyPressSelection, this);
}

void StationMapPanel::onKeyPressSelection(wxKeyEvent& event) {
  int key_code = event.GetKeyCode();
  switch (key_code) {
    case WXK_RETURN:
      if (!lock_dir_keys) {
        hex_manager.onReturnPress();
        lock_dir_keys = !lock_dir_keys;
        propagateCharEvent(key_code);
      } else {
        hex_manager.onReturnCreate(this);
      }
      break;
    case WXK_UP:
    case WXK_DOWN:
    case WXK_LEFT:
    case WXK_RIGHT:
      if (!lock_dir_keys) {
        propagateCharEvent(key_code);
      }
      break;
    case WXK_BACK:
      if (lock_dir_keys) {
        hex_manager.onBackPress();
        propagateCharEvent(key_code);
        lock_dir_keys = !lock_dir_keys;
      }
      break;
    case 'W':
    case 'A':
    case 'S':
    case 'D':
      hex_manager.onKeyPressSelection(key_code);
      Refresh();
      break;
    case WXK_ESCAPE:
      propagateNavigateEvent();
      break;
    default:
      break;
  }
}

void StationMapPanel::propagateCharEvent(const int key_code) {
  wxCommandEvent new_evt(EVT_PROPAGATE_CHAR, GetId());
  new_evt.SetEventObject(this);
  new_evt.SetInt(key_code);
  ProcessEvent(new_evt);
}

void StationMapPanel::propagateNavigateEvent() {
  wxCommandEvent new_evt(EVT_NAVIGATE_TOP);
  ProcessEvent(new_evt);
}
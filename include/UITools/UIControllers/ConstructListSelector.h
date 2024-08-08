#pragma once

#include <wx/wx.h>
#include <vector>
#include <memory>

class ConstructListSelector {
  std::unique_ptr<std::vector<wxPanel*>> build_panels_ptr {};
  std::vector<wxPanel*>& build_ref;
  int index {};
  bool is_selected {false};
public:
  explicit ConstructListSelector(std::unique_ptr<std::vector<wxPanel*>> panel_arr);
  ConstructListSelector();
  void updatePanelVec(std::unique_ptr<std::vector<wxPanel*>> panel_arr);
  void onKeyPress(wxKeyEvent& event);
  void updateIndex(int d_index);
  void resetPanel();
  void updatePanel();
  void onReturnPress();
  void onBackPress();
};

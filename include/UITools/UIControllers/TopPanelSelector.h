#pragma once

#include <wx/wx.h>

class Selector {
private:
  wxStaticText** selections {};
  int selection_focus {0};
  int selections_max {4};
  
public:
  explicit Selector(wxStaticText** selections_init);
  void onDirectionKeyPress(int key_code);
  void moveCursorLeft();
  void moveCursorRight();
  void resetPreviousSelection();
  void updateCurrentSelection();
  void changePage(wxWindow* parent);
};

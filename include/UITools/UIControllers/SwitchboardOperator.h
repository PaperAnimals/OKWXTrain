#pragma once

#include <wx/wx.h>
#include <wx/simplebook.h>
#include <optional>

class MainScreen;

class SwitchboardOperator {
  enum class ActiveFocus {TOP, LEFT_MAP};
  ActiveFocus current_pan {ActiveFocus::TOP};
  
public:
  SwitchboardOperator();
  std::optional<wxKeyEvent> handleKeyPropagation(wxCommandEvent& event);
  void updateActiveFocus();

  static void navigateTopSelector(wxWindow* window);
  void changePage(int key_code, wxSimplebook* left_book, wxSimplebook* right_book);
};

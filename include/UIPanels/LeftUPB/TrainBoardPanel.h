#pragma once

#include <wx/wx.h>
#include <array>
#include <optional>

class TrainBoardPanel : public wxPanel {
  wxGridSizer* train_board = new wxGridSizer(10, 4, 5, 5);
  const wxString board_headers[4] = {"LINE", "LOC", "DES", "TIME"};

public:
  explicit TrainBoardPanel(wxWindow* parent);
  std::vector<std::array<wxStaticText*, 4>> grid_items {};
  
  void createHeaders();
  std::optional<std::reference_wrapper<std::array<wxStaticText*, 4>>> getGridRow(int index);
  void propagateNavigation(wxKeyEvent& event);
};

#pragma once

#include <wx/wx.h>

class BoardDataPanel : public wxPanel { // Convert to simplebook to be pageable scroll
  wxFlexGridSizer* data_grid = new wxFlexGridSizer(10, 2, 5, 5); // change to flexgrid
public:
  explicit BoardDataPanel(wxWindow* parent);
  void createGridItems();
};


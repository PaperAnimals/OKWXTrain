#pragma once

#include "UIPanels/RightISB/InfoSecondBook.h"
#include <wx/wx.h>

class RightPanel : public wxPanel {
  wxBoxSizer* right_sizer = new wxBoxSizer(wxVERTICAL);
  InfoSecondBook* info_sec_book = new InfoSecondBook(this);
public:
  explicit RightPanel(wxWindow* parent);
  InfoSecondBook* getInfoBook();
};
 


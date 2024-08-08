#pragma once

#include "UIPanels/LeftUPB/UserPrimaryBook.h"
#include "UITools/UIHelpers/UIConstants.h"

#include <wx/wx.h>

class LeftPanel : public wxPanel {
public:
  explicit LeftPanel(wxWindow* parent);
  UserPrimaryBook* getUserPrimBook();
private:
  wxBoxSizer* left_sizer = new wxBoxSizer(wxVERTICAL);
  UserPrimaryBook* user_prim_book = new UserPrimaryBook(this);
};

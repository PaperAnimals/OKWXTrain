#pragma once

#include "UIPanels/LeftUPB/TrainBoardPanel.h"
#include "UIPanels/LeftUPB/StationMapPanel.h"

#include <wx/wx.h>
#include <wx/simplebook.h>

class UserPrimaryBook : public wxSimplebook {
public:
  explicit UserPrimaryBook(wxWindow* parent);
};

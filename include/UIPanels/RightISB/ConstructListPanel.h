#pragma once

#include "Actors/ActorHelpers/ActorConsts.h"
#include "UITools/UIControllers/ConstructListSelector.h"

#include <wx/wx.h>
#include <vector>
#include <memory>

class ConstructListPanel : public wxPanel {
  wxGridSizer* construct_sizer = new wxGridSizer(5, 2, 5, 5);
  const ACTORCONSTS::Build::BuildItem* build_item {ACTORCONSTS::Build::BuildItems::BUILDINGS};
  wxPanel* panel_arr[4] {};
  std::unique_ptr<ConstructListSelector> constr_lis_sel {};
  void createBuildingItems();
  void onKeyPress(wxKeyEvent& event);
public:
  explicit ConstructListPanel(wxWindow* parent);
  std::unique_ptr<std::vector<wxPanel*>> getBuildPanels();
};

#include "UIPanels/LeftUPB/UserPrimaryBook.h"

UserPrimaryBook::UserPrimaryBook(wxWindow* parent) : wxSimplebook(parent) {
  AddPage(new TrainBoardPanel(this), "Train Board");
  AddPage(new StationMapPanel(this), "Station Map");
}

#include "UIPanels/Dialogs/CreationDialog.h"

#include <UITools/UIHelpers/UIConstants.h>

CreationDialog::CreationDialog(wxString &title, wxWindow *parent, wxWindowID win_id)
  : wxDialog(parent, win_id, title) {
  SetSize(CONSTS::SizingConsts::Sizes::FRAME_WIDTH/2, CONSTS::SizingConsts::Sizes::FRAME_HEIGHT/4);
  Centre();
  setLabels();
  auto* top_ctrl_label = new wxStaticText(this, wxID_ANY, "TOP");
  auto* bot_ctrl_label = new wxStaticText(this, wxID_ANY, "BOT");
  auto* top_ctrl = new wxTextCtrl(this, wxID_ANY);
  auto* bot_ctrl = new wxTextCtrl(this, wxID_ANY);
  top_ctrl_sizer->Add(top_ctrl_label, 0, wxALIGN_LEFT | wxRIGHT, 10);
  top_ctrl_sizer->Add(top_ctrl, 0, wxALIGN_CENTRE, 10);
  bot_ctrl_sizer->Add(bot_ctrl_label, 0, wxALIGN_LEFT | wxRIGHT, 5);
  bot_ctrl_sizer->Add(bot_ctrl, 0, wxALIGN_CENTRE, 5);
  dialog_sizer->Add(top_ctrl_sizer, 0, wxALIGN_CENTRE, 5);
  dialog_sizer->Add(bot_ctrl_sizer, 0, wxALIGN_CENTRE, 5);
  auto* close_but = new wxButton(this, wxID_CLOSE, "CLOSE");
  dialog_sizer->Add(close_but, 0, wxALIGN_CENTRE, 5);
  SetSizer(dialog_sizer);
}

void CreationDialog::setLabels() {
  if (GetLabel()==wxString("Station")) {
    top_label = "Station name: ";
    bot_label = "Platform count: ";
  }
}


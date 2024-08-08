#pragma once

#include <wx/wx.h>
#include <vector>

class CreationDialog : public wxDialog {
  wxBoxSizer* dialog_sizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* top_ctrl_sizer = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* bot_ctrl_sizer = new wxBoxSizer(wxHORIZONTAL);
  wxString top_label {};
  wxString bot_label {};

  void setLabels();
public:
  explicit CreationDialog(wxString& title, wxWindow* parent=nullptr, wxWindowID win_id=-1);
};
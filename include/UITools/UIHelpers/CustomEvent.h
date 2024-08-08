#pragma once

#include <wx/wx.h>

wxDECLARE_EVENT(EVT_PROPAGATE_CHAR, wxCommandEvent);
wxDECLARE_EVENT(EVT_NAVIGATE_TOP, wxCommandEvent);
wxDECLARE_EVENT(EVT_CHANGE_PAGE, wxCommandEvent);
wxDECLARE_EVENT(EVT_DATA_REQUEST, wxCommandEvent);
wxDECLARE_EVENT(EVT_DATA_RESPONSE, wxCommandEvent);
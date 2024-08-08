#pragma once

#include <wx/wx.h>
#include <cmath>
#include <vector>
#include <memory>

class HexagonalCell : public wxWindow {
  void OnPaint(wxPaintEvent& event);
  const wxBrush* brush_col;
public:
  HexagonalCell(const wxBrush* brush_col, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
  void setBrushColour(const wxBrush* new_brush_col);
};

class HexagonalPair {
  HexagonalCell* hex_border;
  HexagonalCell* hex_cell;
  wxSize size;
public:
  HexagonalPair(wxWindow* parent, const wxPoint& pos);
  HexagonalCell* getHexCell();
  HexagonalCell* getHexBorder();
};

class HexagonalGridPanel : public wxPanel {
  std::vector<std::vector<HexagonalPair*>> hex_vec;
public:
  HexagonalGridPanel(wxWindow* parent);
  std::unique_ptr<std::vector<std::vector<HexagonalPair*>>> getHexArray();
};

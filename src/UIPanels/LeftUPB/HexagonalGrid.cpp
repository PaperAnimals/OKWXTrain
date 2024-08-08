#include "UIPanels/LeftUPB/HexagonalGrid.h"
#include "UITools/UIHelpers/UIConstants.h"

namespace CSSH = CONSTS::SizingConsts::Sizes::HexGrid;

HexagonalCell::HexagonalCell(const wxBrush* brush_col, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size), brush_col(brush_col) {
      Bind(wxEVT_PAINT, &HexagonalCell::OnPaint, this);
    }

void HexagonalCell::OnPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
  wxSize cell_size {GetSize()};
  int hex_radius = std::min(cell_size.GetWidth(), cell_size.GetHeight() / 2);

  // Draw the hexagon
  wxPoint hex_points[6];
  double hex_angle = 0.0;
  double hex_increment = M_PI / 3.0;
  wxPoint hex_center = wxPoint(cell_size.GetWidth() / 2, cell_size.GetHeight() / 2);

  for (int i = 0; i < 6; i++) {
    hex_points[i].x = hex_center.x + static_cast<int>(hex_radius * cos(hex_angle));
    hex_points[i].y = hex_center.y + static_cast<int>(hex_radius * sin(hex_angle));
    hex_angle += hex_increment;
  }

  dc.SetBrush(*brush_col);
  dc.SetPen(*wxTRANSPARENT_PEN);
  dc.DrawPolygon(6, hex_points);
}

void HexagonalCell::setBrushColour(const wxBrush* new_brush_col) {
  brush_col = new_brush_col;
  Refresh();
}

HexagonalPair::HexagonalPair(wxWindow* parent, const wxPoint& pos) : size(CSSH::CELL_SIZE, CSSH::CELL_SIZE) {
  wxPoint border_point = pos - (size*0.15);
  hex_border = new HexagonalCell(wxTRANSPARENT_BRUSH, parent, wxID_ANY, border_point, size*1.3);
  hex_cell = new HexagonalCell(wxBLACK_BRUSH, parent, wxID_ANY, pos, size);
}

HexagonalCell* HexagonalPair::getHexBorder() {
  return hex_border;
}

HexagonalCell* HexagonalPair::getHexCell() {
  return hex_cell;
}


HexagonalGridPanel::HexagonalGridPanel(wxWindow* parent) : wxPanel(parent) {
  SetSize(wxSize(CONSTS::SizingConsts::Sizes::LEFT_PANEL_WIDTH, CONSTS::SizingConsts::Sizes::MAIN_PANEL_HEIGHT));

  for (int row = 0; row < CSSH::NUM_ROWS; ++row) {
    auto* row_vec = new std::vector<HexagonalPair*>;
    for (int col = 0; col < CSSH::NUM_COLS; ++col) {
      int x_offset = (row % 2 == 0) ? 0 : CSSH::SPACING * 0.6;
      int x_pos = static_cast<int>(col * (CSSH::SPACING * 1.2) + x_offset + CSSH::CELL_SIZE * CSSH::X_OFFSET_FACTOR);
      int y_pos = static_cast<int>(row * (CSSH::SPACING * 0.35) + CSSH::CELL_SIZE * CSSH::Y_OFFSET_FACTOR);
      
      auto* pair = new HexagonalPair(this, wxPoint(x_pos, y_pos));
      row_vec->push_back(pair);
    }
    hex_vec.push_back(*row_vec);
    delete row_vec;
  }
}

std::unique_ptr<std::vector<std::vector<HexagonalPair*>>> HexagonalGridPanel::getHexArray() {
  return std::make_unique<std::vector<std::vector<HexagonalPair*>>>(hex_vec);
}


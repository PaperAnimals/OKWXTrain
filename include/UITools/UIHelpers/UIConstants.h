#pragma once

#include <wx/wx.h>
#include <numbers>

namespace CONSTS { // break down
namespace IDConsts {
  enum class PAGE_ID : wxWindowID {
    ID_LEFT_BOOK = 100001
  };
}
namespace SizingConsts {
  namespace Ratios {
    // Height ratios
    constexpr double TOP_PANEL_RATIO {0.1};
    constexpr double BOTTOM_PANEL_RATIO {0.2};
    constexpr double MAIN_PANEL_HEIGHT_RATIO {1-BOTTOM_PANEL_RATIO-TOP_PANEL_RATIO};
    // Width ratios
    constexpr double LEFT_PANEL_WIDTH_RATIO {0.7};
    constexpr double RIGHT_PANEL_WIDTH_RATIO {1-LEFT_PANEL_WIDTH_RATIO};
  }
  namespace Sizes {
    // Frame
    constexpr double FRAME_WIDTH_DOUBLE {1000.0};
    constexpr double FRAME_HEIGHT_DOUBLE {800.0};
    constexpr int FRAME_WIDTH {static_cast<int>(FRAME_WIDTH_DOUBLE)};
    constexpr int FRAME_HEIGHT {static_cast<int>(FRAME_HEIGHT_DOUBLE)};
    constexpr int BAR_WIDTH {static_cast<int>((FRAME_WIDTH*0.01)-2)};
    // Height calculations
    constexpr int TOP_PANEL_HEIGHT {static_cast<int>((FRAME_HEIGHT*Ratios::TOP_PANEL_RATIO)-(BAR_WIDTH*0.5))};
    constexpr int BOTTOM_PANEL_HEIGHT {static_cast<int>(FRAME_HEIGHT*Ratios::BOTTOM_PANEL_RATIO-(BAR_WIDTH*0.5))};
    constexpr int MAIN_PANEL_HEIGHT {static_cast<int>(FRAME_HEIGHT*Ratios::MAIN_PANEL_HEIGHT_RATIO-(BAR_WIDTH))};
    // Width calculations
    constexpr int LEFT_PANEL_WIDTH {static_cast<int>(FRAME_WIDTH*Ratios::LEFT_PANEL_WIDTH_RATIO-(BAR_WIDTH*0.5))};
    constexpr int RIGHT_PANEL_WIDTH {static_cast<int>(FRAME_WIDTH*Ratios::RIGHT_PANEL_WIDTH_RATIO-(BAR_WIDTH*0.5))};
    // Hexagon grid calculations
    namespace HexGrid {
      constexpr int NUM_ROWS {37};
      constexpr int NUM_COLS {14};
      constexpr int CELL_SIZE {28};
      constexpr double HEX_TRIG {std::numbers::sqrt3 / 2};
      constexpr int SPACING {static_cast<int>((CELL_SIZE / 2) * HEX_TRIG + CELL_SIZE)};
      constexpr double X_OFFSET_FACTOR {0.35};
      constexpr double Y_OFFSET_FACTOR {0.35};
    }
  }
}
namespace StyleConsts {
  namespace Colours {
    const wxColour TOP_PANEL_BLUE {0x90603a};
    const wxColour TOP_SEL_TEXT_RED {0x3c3cdc};
    const wxColour MENU_TEXT_GREY {0xf0f0f0};
    const wxColour LEFT_PANEL_BLACK {0x000001};
    const wxColour LEFT_TEXT_YELLOW {0x00d0ff};
    const wxColour RIGHT_PANEL_BLUE {0x8f4f1f};
    const wxColour BOTTOM_PANEL_GREY {0xb0a090};
    const wxColour BAR_COLOUR {0x2ca4cf};
    const wxColour CONSTR_SELECTION_RED {0x00006e};
    const wxColour CONSTR_HIGHLIGHT_YELLOW {0x00D0FF};
    const wxColour CONSTR_SEL_TEXT_YELLOW {0x80F0FF};
    const wxColour CONSTR_HIGH_TEXT_RED {0x000040};
    const wxBrush HEX_SELECTION_RED_BRUSH {CONSTR_SELECTION_RED};
    const wxBrush HEX_HIGHLIGHT_YELLOW_BRUSH {CONSTR_HIGHLIGHT_YELLOW};
  }
  namespace Text {
    constexpr int  MENU_TEXT_SIZE {30};
    const wxFont MENU_FONT = wxFont(MENU_TEXT_SIZE, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Monaco");
    constexpr int LEFT_TEXT_SIZE {20};
    const wxFont MAIN_HEAD_FONT = wxFont(LEFT_TEXT_SIZE, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Monaco");
  }
}
}

// 0x2020e0

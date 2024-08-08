#include "UIPanels/RightISB/InfoSecondBook.h"
#include "UIPanels/RightISB/BoardDataPanel.h"
#include "UIPanels/RightISB/ConstructListPanel.h"

InfoSecondBook::InfoSecondBook(wxWindow* parent) : wxSimplebook(parent) {
  AddPage(new BoardDataPanel(this), "Board Data");
  AddPage(new ConstructListPanel(this), "Construct Panel");
}

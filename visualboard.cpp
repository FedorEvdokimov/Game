#include "visualboard.h"

//visualboard.cpp
VisualBoard::VisualBoard() {
  this->playing_field.resize(3);
  for (int i = 0; i < 3; ++i) {
    playing_field[i].resize(3);
  }
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++ x) {
      this->playing_field[y][x] = new Cell(x, y);
    }
  }
}

void VisualBoard::clean_board() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      this->playing_field[i][j]->button->color(FL_WHITE);
      this->playing_field[i][j]->button->redraw();
    }
  }
}

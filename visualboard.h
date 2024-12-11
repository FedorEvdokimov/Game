#pragma once
#include <vector>
#include "cell.h"

//visualboard.h
struct VisualBoard{
  std::vector <std::vector <Cell*>> playing_field;
  VisualBoard();
  void clean_board();
};

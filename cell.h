#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

#include <vector>

//cell.h
struct Cell{
  std::pair <int, int> crd;
  Fl_Button *button;
  Cell();
  Cell(int X, int Y);
  Cell(const Cell & ) = delete;
  ~Cell();
};
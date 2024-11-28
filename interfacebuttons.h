#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>


//InterfaceButtons.h
struct InterfaceButtons {
  Fl_Button *menu_button;
  Fl_Button *play_again_button;
  Fl_Button *close_program_button;
  InterfaceButtons();
};

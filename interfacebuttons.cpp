#include <iostream>
#include "interfacebuttons.h"
#include "game.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>



void close_program_button_pushed(Fl_Widget *widget, void *data) {
  std::cout << "close_program_button_pushed\n";
  exit(0);
}

//InterfaceButtons.cpp
InterfaceButtons::InterfaceButtons() {
  this->menu_button = new Fl_Button(400, 50, 150, 50, "MENU");
  //this->play_again_button = new Fl_Button(400, 150, 150, 50, "PLAY AGAIN");
  this->close_program_button = new Fl_Button(400, 250, 150, 50, "EXIT");
  //this->button->callback(cell_pushed, (void*)&(this->crd));
  //this->play_again_button->callback(Game::play_again_button_pushed);
  this->close_program_button->callback(close_program_button_pushed);
}

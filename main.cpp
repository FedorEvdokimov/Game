#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using namespace Graph_lib; 

#include "cell.h"
#include "board.h"
#include "visualboard.h"
#include "interfacebuttons.h"
#include "game.h"

 
bool game_is_over;

int main () 
try
{
  int window_x_len = 600;
  int window_y_len = 400;
  Fl_Window *window = new Fl_Window(100, 400, window_x_len, window_y_len , "Window");
  InterfaceButtons our_interface_buttons;
  Game our_game;
  our_game.start_game_cycle();
  window->show();
  //return Fl::run();
}
catch (std::exception& e)
{
  std::cerr << e.what() << std::endl;
  return 1;
}
catch (...)
{
  std::cerr << "Oops, something went wrong..." << std::endl;
  return 2;
}

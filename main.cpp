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


Board our_board;
 







 
 
int window_x_len = 600;
int window_y_len = 400;



VisualBoard our_visual_board;

 
bool game_is_over;

void start_game_cycle();

int cross_win_id = 10;//and put
int zero_win_id = 20;//and put
int draw_id = -1;

//main.cpp
std::string message;

void game_over(int game_over_id) {
  std::cout << "game over with id " << game_over_id << "\n";
  Fl_Window *window = new Fl_Window(200, 500, 300, 300 , "Show winner");
  if (game_over_id == cross_win_id) {
    message = "RED WINS\n";
  } else if (game_over_id == zero_win_id) {
    message = "BLUE WINS\n";
  } else {
    message = "DRAW\n";
  }
  Fl_Button *show_winner_button;
  show_winner_button = new Fl_Button(10, 10, 50, 50, message.c_str());
  window->set_modal();
  window->show();
  while (window->shown()) Fl::wait();
}








//main.cpp
void start_game_cycle() {
  std::cout << "NEW GAME CYCLE STARTED\n";
  game_is_over = false;
  our_board.clean_board();
  std::cout << "check board\n";
  our_board.check_board();
  our_visual_board.clean_board();
}

void play_again_button_pushed(Fl_Widget *widget, void *data) {
  //after_game_over_button_pushed = true;
  //want_to_play = true;
  std::cout << "play_again_button_pushed\n";
  start_game_cycle();
}

void close_program_button_pushed(Fl_Widget *widget, void *data) {
  //after_game_over_button_pushed = true;
  //want_to_play = false;
  std::cout << "close_program_button_pushed\n";
  exit(0);
}


 
//InterfaceButtons.cpp
InterfaceButtons::InterfaceButtons() {
  this->menu_button = new Fl_Button(400, 50, 150, 50, "MENU");
  this->play_again_button = new Fl_Button(400, 150, 150, 50, "PLAY AGAIN");
  this->close_program_button = new Fl_Button(400, 250, 150, 50, "EXIT");
  //this->button->callback(cell_pushed, (void*)&(this->crd));
  this->play_again_button->callback(play_again_button_pushed);
  this->close_program_button->callback(close_program_button_pushed);
}

int main () 
try
{
  std::cout << "EVERYTHINS HAS FALLEN\n";
  Fl_Window *window = new Fl_Window(100, 400, window_x_len, window_y_len , "Window");
  InterfaceButtons our_interface_buttons;
  our_board = *new Board();
  our_visual_board = *new VisualBoard();
  start_game_cycle();
  // window->end();
  window->show();
  /*Fl_Window *window = new Fl_Window(100, 400, window_x_len, window_y_len , "Window");
  InterfaceButtons our_interface_buttons;
  our_board = *new Board();
  our_visual_board = *new VisualBoard();
  window->end();
  window->show();*/
  return Fl::run();
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
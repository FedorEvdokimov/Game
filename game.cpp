#include "game.h";
#include <string>
#include <iostream>

//game.cpp
std::string message;

void Game::game_over(int game_over_id) {
  std::cout << "game over with id " << game_over_id << "\n";
  Fl_Window *window = new Fl_Window(200, 500, 300, 300 , "Show winner");
  if (game_over_id == this->cross_win_id) {
    message = "RED WINS\n";
  } else if (game_over_id == this->zero_win_id) {
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

void Game::start_game_cycle() {
  std::cout << "NEW GAME CYCLE STARTED\n";
  this->game_is_over = false;
  this->our_board.clean_board();
  this->our_visual_board.clean_board();
}

/*
    VisualBoard our_visual_board;*/
Game::Game() {
    this->our_board;
    this->our_visual_board;
}

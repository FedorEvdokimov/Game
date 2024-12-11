#include <iostream>

#include "cell.h"
#include "board.h"
#include "visualboard.h"
#include "game.h"

//cell.cpp
Cell::Cell() {
  this->crd.first = 0;
  this->crd.second = 0;
  this->button = new Fl_Button(0, 0, 0, 0, "");
  this->button->color(FL_WHITE);
}

void cell_pushed(Fl_Widget *widget, void *data);

int step_from_edge = 50;
int button_size = 100;


Cell::~Cell() {
  delete this->button;
}

//cell.cpp
int cell_occupied_id = 0;
int put_cross_id = 1;
int put_zero_id = 2;
int cross_win_id = 10;//and put
int zero_win_id = 20;//and put
int draw_id = -1;

void Game::cell_pushed(Fl_Widget *widget, void *data) {

    std::pair <int, int> *xy = (std::pair <int, int>*)data;
    std::cout << "Pushed: " << (*xy).first << ' ' << (*xy).second << "\n";
    int check_pos_id = this->our_board.check_pos((*xy).first, (*xy).second);
    if (check_pos_id == cell_occupied_id) {
      std::cout << "cell occupied\n";
      return;
    } 
    if (game_is_over) {
      std::cout << "game_is_over\n";
      return;
    }
    if (check_pos_id == put_cross_id) {
      this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_RED);
      std::cout<<"put cross\n";
      return;
    } else if (check_pos_id == put_zero_id) {
      this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_BLUE);
      std::cout<<"put zero\n";
      return;
    }
    //game is over
    int game_over_id = check_pos_id;
    std::cout << "CASE GAME IS OVER\n";
    std::cout << "game_over_id: " << game_over_id << "\n"; 
    
    if (game_over_id == draw_id) {
      if (our_board.moved - 1 == 1) {
        this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_RED);
      } else{
        this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_BLUE);
      }
    }
    //cout << "game_o"
    if (game_over_id == cross_win_id) {
      this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_RED);
    } else if (game_over_id == zero_win_id) {
      this->our_visual_board.playing_field[(*xy).second][(*xy).first]->button->color(FL_BLUE);
    }
    game_is_over = true;
    game_over(game_over_id);
}

Cell::Cell (int X, int Y) {
  this->crd.first = X;
  this->crd.second = Y;
  this->button = new Fl_Button(step_from_edge + button_size * X, step_from_edge + button_size * Y, button_size, button_size, "");
  this->button->color(FL_WHITE);
  this->button->callback(cell_pushed, (void*)&(this->crd));
}

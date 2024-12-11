#include "board.h"
#include "visualboard.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

struct Game{
    bool game_is_over = false;
    Board our_board;
    VisualBoard our_visual_board;
    Fl_Button *play_again_button;
    int cross_win_id = 10;//and put
    int zero_win_id = 20;//and put
    int draw_id = -1;
    Game();
    void game_over(int game_over_id);
    void start_game_cycle();
    void cell_pushed(Fl_Widget *widget, void *data);
    void play_again_button_pushed(Fl_Widget *widget, void *data);
};

#include "board.h"
#include "visualboard.h"
#include "interfacebuttons.h"

struct Game{
    bool game_is_over = false;
    Board our_board;
    VisualBoard our_visual_board;
    int cross_win_id = 10;//and put
    int zero_win_id = 20;//and put
    int draw_id = -1;
    Game();
    void game_over(int game_over_id);
    void start_game_cycle();
};

#pragma once
#include <vector>

//Board.h
struct Board{
    std::vector <std::vector <int>> board;
    int moved;
    int moves;
    Board();
    int check_win();
    int check_pos(int x, int y);
    void check_board();
    void clean_board();
};

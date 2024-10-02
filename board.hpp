#pragma once
#include <vector>
#include "player.hpp"
#include <stdbool.h>
class Board
{
private:
     static constexpr int c_boardHeight = 7;
     static constexpr int c_boardWidth = 10;
     // c_top is the height on a particular [i] column on which a block can be placed;
     std::vector<int> c_top; 
     std::vector<std::vector<char>> c_board;
public:
    Board(); // testat
    ~Board();
    void printBoard(); // testat
    void dropPiece(Player&,int);
};

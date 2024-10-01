#pragma once
#include <vector>
#include <stdbool.h>
class Board
{
private:
     static constexpr int boardHeight = 7;
     static constexpr int boardWidth = 10;
     std::vector<std::vector<char>> board;
public:
    Board();
    ~Board();
};

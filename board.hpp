#pragma once
#include <vector>
#include "player.hpp"

class Board
{
private:
     static constexpr int c_boardHeight = 7;
     static constexpr int c_boardWidth = 10;
     // c_top is the height on a particular [i] column on which a block can be placed;
     std::vector<std::vector<char>> c_board;
     std::vector<int> c_top; 
public:
    
    Board(); // testat
    ~Board(); // neimplementat
    void printBoard(); // testat
    void dropPiece(Player&,int); // testat
    bool canDropPiece(int);
    void hasWon(Player&); //testat
    bool winning(Player&);
    void playerTurn(Player&); // testat
    void aiTurn(Ai&,Player&);
    void undoDrop(int); // testat
    int evaluatePosition(Ai&, Player&);
    int evaluatePiece(Player&,int,int);
    int minMax(Ai&,Player&,int,bool);
};

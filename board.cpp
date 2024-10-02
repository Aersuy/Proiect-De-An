#pragma once
#include "board.hpp"
#include "iostream"
#include "game.hpp"

Board::Board() { 
      c_board = std::vector<std::vector<char>>(c_boardHeight, std::vector<char>(c_boardWidth, '.'));
    
      c_top = std::vector<int>(c_boardWidth, c_boardHeight - 1);
   
}
Board::~Board()
{
    //no use for now but needs to exist to compile
}
void Board::printBoard()
{       for (int iterator = 0; iterator < c_boardWidth; iterator++)
     {
    std::cout << "--";
     }
     std::cout << '\n';


    for (int iterator = 0; iterator < c_boardHeight; iterator++)
    {
        for (int iterator2 = 0; iterator2 < c_boardWidth; iterator2++)
        {
            std::cout << c_board[iterator][iterator2] << ' ';
        }
        std::cout << '\n';
    }
    
     for (int iterator = 0; iterator < c_boardWidth; iterator++)
     {
    std::cout << "--";
     }
     std::cout << '\n \n';
}

void Board::dropPiece(Player& player,int col)
{   
    c_board[c_top[col]][col] = player.getSym();
    c_top[col]--; 
}
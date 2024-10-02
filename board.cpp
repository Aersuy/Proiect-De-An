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
{       for (int iterator = 0; iterator < c_boardWidth + 1; iterator++)
     {
    std::cout << "--";
     }

     std::cout << '\n';


    for (int iterator = 0; iterator < c_boardHeight; iterator++)
    {  std::cout << "|";
        for (int iterator2 = 0; iterator2 < c_boardWidth; iterator2++)
        {
            std::cout << c_board[iterator][iterator2] << ' ';
        }
        std::cout <<  "|\n";
    }
    
     for (int iterator = 0; iterator < c_boardWidth + 1; iterator++)
     {
    std::cout << "--";
     }
     std::cout << "\n \n";
}

void Board::dropPiece(Player& player,int col)
{  
    c_board[c_top[col]][col] = player.getSym();
    c_top[col]--; 
}
void Board::hasWon(Player& Player)
{
  

      for (int row = 0; row < Board::c_boardHeight; ++row) {
        for (int col = 0; col < Board::c_boardWidth; ++col) {
            if (c_board[row][col] == Player.getSym()) {
              
                if (col + 3 < Board::c_boardWidth &&
                    c_board[row][col + 1] == Player.getSym() &&
                    c_board[row][col + 2] == Player.getSym() &&
                    c_board[row][col + 3] == Player.getSym()) {
                   Player.setWinStatus(true);
                }

              
                if (row + 3 < Board::c_boardHeight &&
                   c_board[row + 1][col] == Player.getSym() &&
                    c_board[row + 2][col] == Player.getSym() &&
                    c_board[row + 3][col] == Player.getSym()) {
                    Player.setWinStatus(true);
                }

             
                if (row + 3 < Board::c_boardHeight && col + 3 < Board::c_boardWidth &&
                    c_board[row + 1][col + 1] == Player.getSym() &&
                    c_board[row + 2][col + 2] == Player.getSym() &&
                    c_board[row + 3][col + 3] == Player.getSym()) {
                     Player.setWinStatus(true);
                }

            
                if (row + 3 < Board::c_boardHeight && col - 3 >= 0 &&
                    c_board[row + 1][col - 1] == Player.getSym() &&
                    c_board[row + 2][col - 2] == Player.getSym() &&
                    c_board[row + 3][col - 3] == Player.getSym()) {
                    Player.setWinStatus(true);
                }
            }
        }
    }


}
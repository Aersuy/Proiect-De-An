#pragma once
#include "board.hpp"
#include <iostream>
#include "game.hpp"
#include <limits>


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
{   col--;
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

void Board::playerTurn(Player& play)
{
  
 int col;
   while (true)
    {
        std::cout << "Da coloana \n";
        std::cin >> col;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Not an integer \n";
            continue;
        }

        if (col < 0 || col > 10)
        {   std::cout << "Not in the column range \n";
            continue;
        }
        
        if (c_top[col - 1] < 0)
        {    std::cout << "Column full \n";
            continue;
        }
        
        break;
    }
    this->dropPiece(play,col);
    this->hasWon(play);

}
bool Board::canDropPiece(int col)
{
   if(c_top[col - 1] < 0) 
 { return false;}

   return true;
}

void Board::undoDrop(int col)
{    col--;
      c_top[col]++; 
     c_board[c_top[col]][col]  = '.';
   
}
int Board::evaluatePosition(Ai& ai,Player& player)
{  this->hasWon(ai);
   this->hasWon(player);
    if (ai.getWinStat())
    {
        return 1000;
    }
    if (player.getWinStat())
    {
        return -1000;
    } 
    int score;
     for (int row = 0; row < c_boardHeight; ++row) {
        for (int col = 0; col < c_boardWidth; ++col) {
            char current = c_board[row][col];

            // Check for AI pieces
            if (current == ai.getSym()) {
                score += evaluatePiece(ai,row,col);
            }
            // Check for Player pieces
            else if (current == player.getSym()) {
                score -= evaluatePiece(player,row,col);
            }
        }
    }

    return score; 
}
    
    

// Evaluate a piece at a specific row and column for the given player
int Board::evaluatePiece(Player& player, int row, int col) {
    char symbol = player.getSym();
    int value = 0;

    // Check horizontal (left and right)
    int horizontalCount = 1; // Start with the current piece
    for (int i = 1; i < 4; ++i) { // Check to the right
        if (col + i < c_boardWidth && c_board[row][col + i] == symbol) {
            horizontalCount++;
        } else {
            break;
        }
    }
    for (int i = 1; i < 4; ++i) { // Check to the left
        if (col - i >= 0 && c_board[row][col - i] == symbol) {
            horizontalCount++;
        } else {
            break;
        }
    }
    if (horizontalCount >= 4) value += 100; // Winning move
    else if (horizontalCount == 3) value += 10; // Potential win
    else if (horizontalCount == 2) value += 1; // Threat

    // Check vertical (downwards)
    int verticalCount = 1; // Start with the current piece
    for (int i = 1; i < 4; ++i) { // Check down
        if (row + i < c_boardHeight && c_board[row + i][col] == symbol) {
            verticalCount++;
        } else {
            break;
        }
    }
    if (verticalCount >= 4) value += 100; // Winning move
    else if (verticalCount == 3) value += 10; // Potential win
    else if (verticalCount == 2) value += 1; // Threat

    // Check diagonal (bottom-right and top-left)
    int diagonalCount1 = 1; // Start with the current piece
    for (int i = 1; i < 4; ++i) { // Check bottom-right
        if (row + i < c_boardHeight && col + i < c_boardWidth && c_board[row + i][col + i] == symbol) {
            diagonalCount1++;
        } else {
            break;
        }
    }
    for (int i = 1; i < 4; ++i) { // Check top-left
        if (row - i >= 0 && col - i >= 0 && c_board[row - i][col - i] == symbol) {
            diagonalCount1++;
        } else {
            break;
        }
    }
    if (diagonalCount1 >= 4) value += 100; // Winning move
    else if (diagonalCount1 == 3) value += 10; // Potential win
    else if (diagonalCount1 == 2) value += 1; // Threat

    // Check diagonal (bottom-left and top-right)
    int diagonalCount2 = 1; // Start with the current piece
    for (int i = 1; i < 4; ++i) { // Check bottom-left
        if (row + i < c_boardHeight && col - i >= 0 && c_board[row + i][col - i] == symbol) {
            diagonalCount2++;
        } else {
            break;
        }
    }
    for (int i = 1; i < 4; ++i) { // Check top-right
        if (row - i >= 0 && col + i < c_boardWidth && c_board[row - i][col + i] == symbol) {
            diagonalCount2++;
        } else {
            break;
        }
    }
    if (diagonalCount2 >= 4) value += 100; // Winning move
    else if (diagonalCount2 == 3) value += 10; // Potential win
    else if (diagonalCount2 == 2) value += 1; // Threat

    return value; // Return the evaluation score for this piece
}

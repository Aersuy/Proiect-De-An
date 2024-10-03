#pragma once
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"
#include <conio.h> 
Game::Game()
{
//unfinished
}
Game::~Game()
{
// no use for now, but needs to exist to compile
}

void Game::run()
{    Player me;
     Player you;
     Board board;
    while (true)
    {
        board.playerTurn(me);
         system("cls");
        board.printBoard();
         if (me.getWinStat())
          break;
        board.playerTurn(you);
        system("cls");
        board.printBoard();
         if (you.getWinStat())
          break;
    }
    if (me.getWinStat() == true)
    {
        std::cout << "I won \n";
    }
     if (you.getWinStat() == true)
    {
        std::cout << "You won \n";
    }
    
}

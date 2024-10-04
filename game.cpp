#pragma once
#include "game.hpp"
#include "player.hpp"
#include "board.hpp"
#include <conio.h> 
#include <stdlib.h>
Game::Game()
{
//unfinished
}
Game::~Game()
{
// no use for now, but needs to exist to compile
}

void Game::run()
{    Ai yes;
     int in;
     Player me;
     yes.setDepth(6);
     Board board;
    while (true)
    {
        board.playerTurn(me);
         system("cls");
        board.printBoard();
         if (me.getWinStat())
          break;

        board.aiTurn(yes,me);
        system("cls");
        board.printBoard();
         if (yes.getWinStat())
          break;
    }
    if (me.getWinStat() == true)
    {
        std::cout << "I won \n";
    }
     if (yes.getWinStat() == true)
    {
        std::cout << "You won \n";
    }
    
}

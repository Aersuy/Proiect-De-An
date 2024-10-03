#pragma once
#include "player.hpp"
#include "board.cpp"
#include <limits>
Player::Player()
{      char inputChar{};
          while (true) {
        std::cout << "Enter character: ";
        std::cin >> inputChar;

       
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid character.\n";
        } 
        if (inputChar == 'A')
        {
            std::cout << "Invalid input. 'A' is taken. \n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            break;
        }
        
    }
       c_symbol = inputChar;
       this->setWinStatus(false);
       std::cout << "Da username-ul \n";
       std::cin >> c_userName;
}
Player::Player(char inputChar)
{    
    c_symbol = inputChar;
    c_hasWon = false;
    if(inputChar == 'A')
    c_userName = "Ai";
}
Player::~Player()
{
    // empty but needs to exist to compile
}

Ai::~Ai()
{
     // empty but needs to exist to compile
}
void Player::setWinStatus(bool input)
{
   c_hasWon = input;
}
void Ai::setDepth(int depth)
{
    c_depth = depth;
}
char Player::getSym()
{
    return c_symbol;
}

bool Player::getWinStat()
{
    return c_hasWon;
}

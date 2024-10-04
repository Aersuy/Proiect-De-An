#pragma once
#include "player.hpp"
#include "board.cpp"
#include <limits>
std::set<char> Player::c_usedCharacters;
Player::Player()
{      char inputChar{};
          while (true) {
        std::cout << "Enter character: ";
        std::cin >> inputChar;

       
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid character.\n";
            continue;
        } 
        if (c_usedCharacters.find(inputChar) != c_usedCharacters.end())
        {
            std::cout << "Invalid input(Character is taken) \n";
            continue;
        }
        else
        {
            break;
        }
        
    }

       c_symbol = inputChar;
       c_usedCharacters.insert(inputChar);
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
    c_usedCharacters.insert(inputChar);
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
int Ai::getDepth()
{
    return c_depth;
}
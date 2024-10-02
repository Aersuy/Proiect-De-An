#pragma once
#include "player.hpp"
#include <iostream>
Player::Player()
{      char inputChar{};
       std::cout << "Da caracterul pe care vrei sa il folosesti in joc(. si A exclus) \n";
       std::cin >> inputChar;
       c_symbol = inputChar;
       this->setWinStatus(false);
}
Player::Player(char inputChar)
{
    c_symbol = inputChar;
}
Player::~Player()
{
    // empty but needs to exist to compile
}
/*Ai::Ai()
{   this->setWinStatus(false);
    c_symbol = 'A';
}*/
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
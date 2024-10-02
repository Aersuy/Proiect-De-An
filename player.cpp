#pragma once
#include "player.hpp"
#include "board.hpp"
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
    c_hasWon = false;
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

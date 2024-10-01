#include "player.hpp"
#include <iostream>
Player::Player()
{      char inputChar{};
       std::cout << "Da caracterul pe care vrei sa il folosesti in joc(. si A exclus) \n";
       std::cin >> inputChar;
       this->SetSymbol(inputChar);
}
Ai::Ai()
{
    this->SetSymbol('A');
}
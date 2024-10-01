#pragma once
#include <stdbool.h>
class Player
{
private:
      char c_symbol;
      bool c_hasWon;
public:
     Player();
     ~Player();
     void SetSymbol(char);
};

class Ai: public Player
{
private:
     
public:
     Ai();
     ~Ai(); 
};



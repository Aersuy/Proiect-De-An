#pragma once
#include <stdbool.h>
#include "board.hpp"
class Player
{
private:
      bool c_hasWon;
protected: 
      char c_symbol;
public:
     Player(); // testat
     Player(char); // testat
    virtual ~Player();
    void setWinStatus(bool); // testat
    bool getWinStat(); // testat
    char getSym(); // testat
    void playerTurn(); // neimplementat
  
};

class Ai: public Player
{
private: 
 // the max depth that the ai will go to
     int c_depth{}; 
public:
     Ai() : Player('A'){}; // netestat
     ~Ai(); 
     void aiTurn(); // neimplementat
     void setDepth(int); // netestat
};



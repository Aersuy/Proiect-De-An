#pragma once
#include <stdbool.h>
class Player
{
private:
      bool c_hasWon;
protected: 
      char c_symbol;
public:
     Player(); // netestat
     Player(char); // netestat
    virtual ~Player();

    void setWinStatus(bool); // netestat
};

class Ai: public Player
{
private: 
 // the max depth that the ai will go to
     int c_depth{}; 
public:
     Ai(); // netestat
     ~Ai(); 
     void setDepth(int); // netestat
};



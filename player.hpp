#pragma once
#include "board.hpp"
#include "board.cpp"
#include "game.hpp"
#include <string>
#include <set>
class Player
{
private:
      bool c_hasWon;
      std::string c_userName{};
      static std::set<char> c_usedCharacters;
protected: 
      char c_symbol;
public:
     Player(); // testat
     Player(char); // testat
    virtual ~Player();  // neimplementat
    void setWinStatus(bool); // testat
    bool getWinStat(); // testat
    char getSym(); // testat
   
  
};

class Ai: public Player
{
private: 
 // the max depth that the ai will go to
     int c_depth{}; 
public:
     Ai() : Player('A'){}; // netestat
     ~Ai();    // neimplementat
     void aiTurn(); // neimplementat
     void setDepth(int); // netestat
     int getDepth();

};



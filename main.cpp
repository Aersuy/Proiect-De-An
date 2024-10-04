#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    Player p;
     b.playerTurn(p);
    b.printBoard();
    b.undoDrop(3);
    b.printBoard();


    
    
    return 0;
}
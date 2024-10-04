#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    Player p;
    Ai ai;
      b.dropPiece(ai,3);
      b.dropPiece(ai,3);
      b.dropPiece(ai,3);
      b.dropPiece(ai,4);
      b.dropPiece(ai,5);
      
      
      
      int value = b.evaluatePosition(ai,p);

     std::cout << value << '\n';
    b.printBoard();


    
    
    return 0;
}
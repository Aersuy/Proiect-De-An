#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    Player p;
    Ai ai;
    
      b.dropPiece(p,2);
      b.dropPiece(p,2);
      b.dropPiece(p,2);
      b.dropPiece(p,1);
      b.dropPiece(ai,3);
      b.dropPiece(ai,3);
      b.dropPiece(ai,3);
      int value = b.evaluatePosition(ai,p);

     std::cout << value << '\n';
    b.printBoard();


    
    
    return 0;
}
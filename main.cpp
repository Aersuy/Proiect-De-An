#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    b.printBoard();
    Ai pl;
    b.dropPiece(pl,2);
    b.dropPiece(pl,2);
    b.dropPiece(pl,3);
    b.printBoard();
    return 0;
}
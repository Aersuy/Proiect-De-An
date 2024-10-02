#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    b.printBoard();
    Ai pl;
    Player p;
    b.dropPiece(pl,2);
    b.dropPiece(pl,2);
    b.dropPiece(pl,2);
    b.dropPiece(p,3);
    b.dropPiece(p,4);
    b.dropPiece(p,5);
    b.dropPiece(pl,3);
    b.dropPiece(pl,4);
    b.dropPiece(pl,5);
   
    b.printBoard();
    b.hasWon(pl);
    if (pl.getWinStat())
    {
        std::cout << "Bine \n";
    }
    
    
    return 0;
}
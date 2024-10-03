#include "board.cpp"
#include "player.cpp"
#include "game.cpp"
int main()
{    
    Board b;
    b.printBoard();
    Player p;
    Player p2;
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.playerTurn(p);
    b.printBoard();
    if (p.getWinStat())
    {
        std::cout << "Merge \n";
    }
    


    
    
    return 0;
}


#include "engine/board.hpp"

using namespace std;

int main(int argc, char **argv) {
    Board gameBoard;

    gameBoard.AddPieceToCol('#', 3);
    gameBoard.AddPieceToCol('#', 3);
    gameBoard.AddPieceToCol('#', 3);

    gameBoard.TakePieceFromCol(3);

    gameBoard.AddPieceToCol('@', 2);
    
    gameBoard.PrintBoard(cout);

    return 0;
}

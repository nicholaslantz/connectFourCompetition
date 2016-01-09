/* board.cpp
 *
 *
 */

#include "board.hpp"

using namespace std;

Board::Board() {
    gameBoard = Grid<char>(NROWS, NCOLS);
    numEmptyTilesInCols = Vector<int>(NCOLS, gameBoard.numRows());
    bool safeMode = true;

    for (int i = 0; i < gameBoard.numRows(); i++) {
        for (int j = 0; j < gameBoard.numCols(); j++) {
            gameBoard[i][j] = '.';
        }
    }
}

int Board::AddPieceToCol(char piece, int col) {

    if (col < 0 || col > gameBoard.numCols() - 1) {
        cerr << "Error: Out of Bounds" << endl;
        cerr << "Make sure col modified is between 0 and 6 inclusive" << endl;
    }

    int row = numEmptyTilesInCols[col] - 1;
    numEmptyTilesInCols[col]--;

    gameBoard[row][col] = piece;


    if (safeMode) {
        // Floating Piece check

        int heighestRow;
        bool foundHighest = false;

        for (int i = gameBoard.numRows() - 1; i >= 0; i--) {
            if (gameBoard[i][col] == '.') {
                foundHighest = true;
            }
            if (foundHighest && gameBoard[i][col] != '.') {
                cerr << "Error: floating piece" << endl;
            }
        }
    }

    return row;
}

int Board::TakePieceFromCol(int col) {

    cout << numEmptyTilesInCols << endl;

    if (col < 0 || col > gameBoard.numCols() - 1) {
        cerr << "Error: Out of Bounds" << endl;
        cerr << "Make sure col modified is between 0 and 6 inclusive" << endl;
    }

    if (numEmptyTilesInCols[col] == gameBoard.numCols()) {
        cerr << "Error: Take away from Empty Column" << endl;
        cerr << "Make sure the col being removed from has >= 1 tile in it"
             << endl;
    }

    int row = numEmptyTilesInCols[col];
    numEmptyTilesInCols[col]++;

    gameBoard[row][col] = '.';

    if (safeMode) {
        // Floating Piece check

        int heighestRow;
        bool foundHighest = false;

        for (int i = gameBoard.numRows() - 1; i >= 0; i--) {
            if (gameBoard[i][col] == '.') {
                foundHighest = true;
            }
            if (foundHighest && gameBoard[i][col] != '.') {
                cerr << "Error: floating piece" << endl;
            }
        }
    }

    return row;
}

void Board::PrintBoard(ostream &out) const {
    for (int i = 0; i < gameBoard.numRows(); i++) {
        for (int j = 0; j < gameBoard.numCols(); j++) {
            cout << gameBoard.get(i, j) << ' ';
        }
        cout << endl;
    }
}

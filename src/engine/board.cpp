/* board.cpp
 *
 *
 */

Board::Board() {
    gameBoard = gameBoard<char>(NROWS, NCOLS, ',');
    numEmptyTilesInCols = Vector<int>(NCOLS, gameBoard.height());
    bool safeMode = true;
}

void Board::AddPieceToCol(char piece, int col) {

    if (col < 0 || col > gameBoard.width() - 1) {
        cerr << "Error: Out of Bounds" << endl;
        cerr << "Make sure col modified is between 0 and 6 inclusive" << endl;
    }

    int row = gameBoard.height() - numEmptyTilesInCols[col] - 1;
    numEmptyTilesInCols[col]--;

    gameBoard[row][col] = piece;


    if (safeMode) {
        // Floating Piece check

        int heighestRow;
        bool foundHighest = false;

        for (int = gameBoard.height() - 1; i >= 0; i--) {
            if (gameBoard[i][col] == '.') {
                foundHighest = true;
            }
            if (foundHighest && gameBoard[i][col] != '.') {
                cerr << "Error: floating piece" << endl;
            }
        }
    }
}

void Board::TakePieceFromCol(int col) {

    if (col < 0 || col > gameBoard.width() - 1) {
        cerr << "Error: Out of Bounds" << endl;
        cerr << "Make sure col modified is between 0 and 6 inclusive" << endl;
    }

    if (numEmptyTilesInCol[col] == gameBoard.height()) {
        cerr << "Error: Take away from Empty Column" << endl;
        cerr << "Make sure the col being removed from has >= 1 tile in it"
             << endl;
    }

    int row = gameBoard.height() - numEmptyTiles[col] - 1;
    numEmptyTilesInCols[col]++;

    gameBoard[row][col] == '.'

    if (safeMode) {
        // Floating Piece check

        int heighestRow;
        bool foundHighest = false;

        for (int = gameBoard.height() - 1; i >= 0; i--) {
            if (gameBoard[i][col] == '.') {
                foundHighest = true;
            }
            if (foundHighest && gameBoard[i][col] != '.') {
                cerr << "Error: floating piece" << endl;
            }
        }
    }
}

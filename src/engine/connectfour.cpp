/* connectFour.cpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-08>
 */

char checkVector(Vector<char> &vec);

ConnectFour::ConnectFour() {
    connectFourBoard = Board();
    gameState = UNDECIDED;
    whitePlayer = DEFAULT_PLAYER_WHITE;
    blackPlayer = DEFAULT_PLAYER_BLACK;
    playerTurn = whitePlayer;
}

ConnectFour::ConnectFour(char newWhitePlayer, char newBlackPlayer) {
    connectFourBoard = Board();
    gameState = UNDECIDED;
    whitePlayer = newWhitePlayer;
    blackPlayer = newBlackPlayer;
    playerTurn = whitePlayer;
}

int ConnectFour::TakeTurn(char player, int col) {
    /* Play a piece, and update the gameState
     */
    if (player != playerTurn) {
        cerr << "Warning: it is not " << player << "'s turn to play" << endl;
    }

    int colModified = col;
    int rowModified = connectFourBoard.AddPieceToCol(col)

    updateGameState(row, col);

    return gameState;
}

void ConnectFour::updateGameState(int row, int col) {
    bool victory = false;
    victory = checkCols(player, row, col);
    //victory = checkRows(player, row, col);
    //victory = checkDiags(player, row, col);

    if (victory) {
        gameState = player;
    }
}

void ConnectFour::updateGameState(char player) {
    bool victory = false;
    victory = checkCols(player);
    victory = checkRows(player);
    victory = checkDiags(player);
}

char ConnectFour::checkCols(int row, int col) const {
    Vector<char> column = connectFourBoard.GetCol(col);
    return checkVector(col);
}

char ConnectFour::checkCols() {
    return 'N';
}

char ConnectFour::checkRows(int row, int col) const {
    return 'N'
}
char ConnectFour::checkRows() const {
    return 'N'
}

char ConnectFour::checkDiags(int row, int col) const {
    return 'N'
}

char ConnectFour::checkDiags() const {
    return 'N'
}

char checkVector(Vector<char> &vec) {
    int length = 0; char oldToken = column[0];
    for (int i = 1; i < column.size(); i++) {
        newToken = column[i]
        if (newToken == '.') {
            return 'U';
        }
        if (newToken == oldToken) {
            length++;
            if (length == 4) {
                return newToken;
            }
        }
        else {
            length = 1;
        }
    }
    return 'U';
}

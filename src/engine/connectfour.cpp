/* connectFour.cpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-08>
 */

#include "connectfour.hpp"

using namespace std;

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
    int rowModified = connectFourBoard.AddPieceToCol(player, col);

    updateGameState(rowModified, colModified);
    if (playerTurn == WHITE) {
        playerTurn = BLACK;
    }
    else {
        playerTurn = WHITE;
    }

    return gameState;
}

void ConnectFour::updateGameState(int row, int col) {
    char state = checkCols(row, col);
    //victory = checkRows(player, row, col);
    //victory = checkDiags(player, row, col);

    gameState = state;
}

void ConnectFour::updateGameState() {
    bool victory = false;
    victory = checkCols();
    victory = checkRows();
    victory = checkDiags();
}

char ConnectFour::checkCols(int row, int col) const {
    Vector<char> column = connectFourBoard.GetCol(col);
    return checkVector(column);
}

char ConnectFour::checkCols() const {
    return 'N';
}

char ConnectFour::checkRows(int row, int col) const {
    return 'N';
}
char ConnectFour::checkRows() const {
    return 'N';
}

char ConnectFour::checkDiags(int row, int col) const {
    return 'N';
}

char ConnectFour::checkDiags() const {
    return 'N';
}

char ConnectFour::checkVector(const Vector<char> &vec) const {
    cout << vec << endl;
    cout << "NEW" << endl;
    int length = 1; char oldToken = vec[vec.size()-1];
    for (int i = vec.size()-2; i >= 0; i--) {
        cout << length << ", ";
        char newToken = vec[i];
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
    cout << endl;
    return 'U';
}

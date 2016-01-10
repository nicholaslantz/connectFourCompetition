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

char ConnectFour::TakeTurn(int col) {
    int colModified = col;
    int rowModified = connectFourBoard.AddPieceToCol(playerTurn, col);

    updateGameState(rowModified, colModified);
    updatePlayerTurn();

    return gameState;
}

char ConnectFour::TakeTurn(char player, int col) {
    /* Play a piece, and update the gameState
     */
    if (player != playerTurn) {
        cerr << "Warning: it is not " << player << "'s turn to play" << endl;
    }

    int colModified = col;
    int rowModified = connectFourBoard.AddPieceToCol(player, col);

    updateGameState(rowModified, colModified);
    updatePlayerTurn();

    return gameState;
}

void ConnectFour::updateGameState(int row, int col) {
    char state1 = checkCols(row, col);
    char state2 = checkRows(row, col);
    char state3 = checkDiags(row, col);

    // there has to be a better way to do this than the following...
    if (state1 != UNDECIDED) {
        gameState = state1;
    }
    else if (state2 != UNDECIDED) {
        gameState = state2;
    }
    else {
        gameState = state3;
    }
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
    Vector<char> rowData = connectFourBoard.GetRow(row);
    return checkVector(rowData);
}
char ConnectFour::checkRows() const {
    return 'N';
}

char ConnectFour::checkDiags(int row, int col) const {
    Vector<char> diag1 = connectFourBoard.GetDiagPos(row, col);
    Vector<char> diag2 = connectFourBoard.GetDiagNeg(row, col);
    char res1 = checkVector(diag1);
    char res2 = checkVector(diag2);

    if (res1 != UNDECIDED) {
        return res1;
    }
    else {
        return res2;
    }
         
    return 'N';
}

char ConnectFour::checkDiags() const {
    return 'N';
}

char ConnectFour::checkVector(const Vector<char> &vec) const {
    int length = 1; char oldToken = vec[vec.size()-1];
        // start at bottom, those are more likely to contain 4 in a row

    for (int i = vec.size()-2; i >= 0; i--) {
        // the following could be improved by breaking the loop once the
        // halfway mark is reached. It adds more condition checking, so it
        // will slow the loop iterations down, so it may increase time. Someone
        // can test later if desired.

        char newToken = vec[i];
        if (newToken == oldToken) {
            length++;
            if (length == 4) {
                // there's a weird error where it's returning '.' as winning,
                // I'm going to add a check and have the loop break if it comes
                // up with ',' as having length of 4
                if (newToken != DEFAULT_SPACE) {
                    return newToken;
                }
                else {
                    break;
                }
            }
        }
        else {
            length = 0;
        }
    }
    
    return UNDECIDED;

    /* The following only works for checking columns, it assumes that if a
     * empty space is found, there are no more tiles above it, which is not
     * necessarily true for diagonals and rows
     *
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
    */
}

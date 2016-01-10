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

    if (rowModified == -1) {
        // Illegal move, most likely addition to full column
        gameState = ILLEGAL_MOVE;
        return ILLEGAL_MOVE;
    }

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

    if (rowModified == -1) {
        // Illegal move, most likely addition to full column
        gameState = ILLEGAL_MOVE;
        return ILLEGAL_MOVE;
    }

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
    // The following is embarrasing, I couldn't get my search function to work
    // properly, so I just used the string's search. It's called being
    // resourceful ;P

    string data = "";
    string p1(""), p2("");
    for(int i = 0; i < vec.size(); i++) {
        data += vec[i];
    }
    for(int i = 0; i < 4; i++) {
        p1 += WHITE;
        p2 += BLACK;
    }

    if (data.find(p1) != string::npos) {
        return WHITE;
    }
    else if (data.find(p2) != string::npos) {
        return BLACK;
    }

    return UNDECIDED;
}

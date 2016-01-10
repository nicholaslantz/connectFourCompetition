/* connectFour.hpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-08>
 *
 * Provides the definition and functions for interacting with the Connect Four
 * game. This class will keep track of the gamestate, and notify the caller if
 * a player has won the game.
 */

#pragma once
#include "board.hpp"

using namespace std;

class ConnectFour {
public:
    static const char UNDECIDED = 'U';
    static const char WHITE = '@';
    static const char BLACK = '#';

    static const char DEFAULT_PLAYER_WHITE = '@';
    static const char DEFAULT_PLAYER_BLACK = '#';
    static const char DEFAULT_SPACE = '.';


    ConnectFour();
    ConnectFour(char newWhitePlayer, char newBlackPlayer);

    char TakeTurn(int col); // uses the player stored in "playerTurn"
        // Defaults to switching between black and white after each turn
    char TakeTurn(char player, int col);
    char GetGameState() const {
        return gameState;
    }

    void PrintBoard(ostream &out) const {
        connectFourBoard.PrintBoard(out);
    }
    Board GetBoard() const {
        return connectFourBoard;
    }
private:
    Board connectFourBoard;

    char gameState;
    char whitePlayer, blackPlayer;
    char playerTurn;

    // Helper functions
    void updatePlayerTurn() {
        if (playerTurn == WHITE) {
            playerTurn = BLACK;
        }
        else {
            playerTurn = WHITE;
        }
    }

    void updateGameState(int row, int col);
        // only checks pieces around the tile in parameters
    void updateGameState();
        // checks the entire board
    char checkCols(int row, int col) const;
    char checkCols() const;
    char checkRows(int row, int col) const;
    char checkRows() const;
    char checkDiags(int row, int col) const;
    char checkDiags() const;

    char checkVector(const Vector<char> &vec) const;
};

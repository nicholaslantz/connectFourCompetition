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

class ConnectFour {
public:
    static const int UNDECIDED = 0;
    static const int WHITE = 1;
    static const int BLACK = 2;

    static const int DEFAULT_PLAYER_WHITE = '@';
    static const int DEFAULT_PLAYER_BLACK = '#';

    ConnectFour();
    connectFour(char newWhitePlayer, char newBlackPlayer);

    int TakeTurn(char player, int col);
    int GetGameState() const {
        return gameState;
    }
private:
    Board connectFourBoard;

    int gameState;
    char whitePlayer, blackPlayer;

    // Helper functions
    void updateGameState(); // modifies int gameState
    int checkCols();
    int checkRows();
    int checkDiags();
};

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
    static const char UNDECIDED = 'U';
    static const char WHITE = '@';
    static const char BLACK = '#';

    static const char DEFAULT_PLAYER_WHITE = '@';
    static const char DEFAULT_PLAYER_BLACK = '#';

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
    char playerTurn;

    // Helper functions
    void updateGameState(int row, int col);
        // only checks pieces around the tile in parameters
    void updateGameState()
        // checks the entire board
    char checkCols(int row, int col) const;
    char checkCols() const;
    char checkRows(int row, int col) const;
    char checkRows() const;
    char checkDiags(int row, int col) const;
    char checkDiags() const;
};

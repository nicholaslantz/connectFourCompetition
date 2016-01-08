/* board.hpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-07>
 *
 * Provides the definition and functions for reading/manipulating the board
 * It will also make sure the board remains valid, and outputs error messages
 * if something strange happens to the board when it is modified.
 *
 * This board class is written for the game of Connect Four, so it is designed
 * to manage that game. It will be checking to make sure the board remains valid
 */
#pragma once

#include <iostream>
#include <vector.h>
#include <grid.h>

using namespace std;

class Board {
public:
    static const int NROWS = 6;
    static const int NCOLS = 7;

    Board();

    char GetTile(int row, int col) const {
        return gameBoard.get(row, col);
    }
    char GetTile(pair<int, int> tile) const {
        return gameBoard.get(tile.first, tile.second);
    }

    Vector<char> GetCol(int col) const {
        // avoid use of this function if it can be avoided, it's inefficient
        Vector<char> response;

        for (int i = 0; i < gameBoard.numRows(); i++) {
            response.add(gameBoard.get(i, col));
        }

        return response;
    }

    Vector<char> GetRow(int row) const {
        Vector<char> response;

        for (int i = 0; i < gameBoard.numCols(); i++) {
            response.add(gameBoard.get(row, i));
        }

        return response;
    }

    Grid<char> GetBoard() const {
        // useful if one wants to operate on the Grid directly instead of going
        // through this class
        return gameBoard;
    }

    void ToggleSafeMode() {
        safeMode = !safeMode;
    }

    void SetSafeMode(bool mode) {
        safeMode = mode;
    }

    void AddPieceToCol(char piece, int col);
        // the best way to interact with the board, it will "drop" the piece
        // into the specified column. This is the safe way to modify the board
        // and prevent errors from occurring

    void TakePieceFromCol(int col);
        // best way to remove a piece from the board. This is the safe way
        // to modify the board and prevent errors from occurring

    // TODO add insecure ways to modify the board

    void PrintBoard(ostream &out) const;
private:
    Grid<char> gameBoard;
    Vector<int> numEmptyTilesInCols;
        // Keeping this data avoids a for loop in the addPieceToCol(int col) 
        // function
    bool safeMode; // should be turned on, turn off to improve performance
        // trivial checks are included by default, ones that require loops
        // or other nontrivial procedures need safeMode = true to run
};

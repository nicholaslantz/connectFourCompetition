

#include <iostream>
#include "engine/connectfour.hpp"

using namespace std;

int main(int argc, char **argv) {
    ConnectFour game;

    int gameState;

    gameState = game.TakeTurn('@', 3);
    gameState = game.TakeTurn('#', 2);
    gameState = game.TakeTurn('@', 3);
    gameState = game.TakeTurn('#', 2);
    gameState = game.TakeTurn('@', 3);
    gameState = game.TakeTurn('#', 2);
    gameState = game.TakeTurn('@', 3);
    gameState = game.TakeTurn('#', 2);
    
    game.PrintBoard(cout);
    cout << (char)gameState << endl;
}

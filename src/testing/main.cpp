

#include <iostream>
#include "engine/connectfour.hpp"

using namespace std;

char test(ConnectFour &game, char player, int col);
char test(ConnectFour &game, int col);

int main(int argc, char **argv) {
    ConnectFour game;

    char gameState;
    
    test (game, 3);
    test (game, 3);
    test (game, 4);
    test (game, 4);
    test (game, 5);
    test (game, 2);
    test (game, 6);
    /* Test vertical
    test (game, 3);
    test (game, 2);
    test (game, 3);
    test (game, 2);
    test (game, 3);
    test (game, 2);
    test (game, 3);
    */
    /* test negative Diagonal
    test (game, 3);
    test (game, 2);
    test (game, 2);
    test (game, 1);
    test (game, 0);
    test (game, 1);
    test (game, 1);
    test (game, 0);
    test (game, 0);
    test (game, 1);
    test (game, 0);
    */
    /* Test positive diagonal
    test(game, 3);
    test(game, 4);
    test(game, 4);
    test(game, 5);
    test(game, 6);
    test(game, 5);
    test(game, 6);
    test(game, 6);
    test(game, 6);
    test(game, 4);
    test(game, 5);
     */

    return 0;
}

char test(ConnectFour &game, char player, int col) {
    char state = game.TakeTurn(player, col);
    game.PrintBoard(cout);
    cout << endl;
    cout << state << endl;

    return state;
}

char test(ConnectFour &game, int col) {
    char state = game.TakeTurn(col);
    game.PrintBoard(cout);
    cout << endl;
    cout << state << endl;

    return state;
}

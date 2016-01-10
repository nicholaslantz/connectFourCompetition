/* gamemanager.hpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-09>
 *
 * The Game Manager class will store 1 Connect Four game and 2 Interfaces. It
 * will call the game and interfaces when appropriate, and allow the interfaces
 * to communicate through the game. It will also have a main menu screen that
 * will show up when the program starts.
 *
 * At the moment, I do not intend to create this so that it can be run
 * non-interactively, however that would be a great improvement for future
 * versions of the game.
 */

#include "connectfour.hpp"
#include "../interfaces/userinterface/userinterface.hpp"
#include "../interfaces/randomai/randomai.hpp"

class GameManager {
public:
    static const int NUM_INTERFACES = 1;

    static const int USER_INTERFACE = 1;
    static const int NLANTZ_AI = 2;
    static const int LUCKCOW_AI = 3;
    static const int RANDOM_AI = 4;


    GameManager(int interface1, int interface2);

    char PlayGame(); // plays an entire game
    char PlayRound(); // plays a single round


private:
    ConnectFour game;
    Interface *player1;
    Interface *player2;
};

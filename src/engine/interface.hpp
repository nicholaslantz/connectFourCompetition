/* interface.hpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-09>
 *
 * The Interface class provides a standard way of communicating with the
 * Connect Four class for different kinds of players. This class contains
 * the essential functions and virtual ones that should be defined in child
 * classes
 *
 * player = user/AI
 */

#pragma once
#include "connectfour.hpp"

class Interface {
public:
    Interface(ConnectFour *connectFourGame) {
        game = connectFourGame;
    }

    virtual void TakeTurn() = 0;
        // this method will allow the player to take their turn, it should
        // use the TakeTurn method in ConnectFour, the designer can use
        // whatever means they want to determine their move.

private:

protected:
    ConnectFour *game;
};

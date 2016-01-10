

#include <iostream>
#include "engine/gamemanager.hpp"

using namespace std;

int main(int argc, char **argv) {
    GameManager game(GameManager::USER_INTERFACE, GameManager::USER_INTERFACE);

    game.PlayGame();

    return 0;
}

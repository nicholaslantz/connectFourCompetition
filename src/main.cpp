

#include <iostream>
#include "engine/gamemanager.hpp"

using namespace std;

int main(int argc, char **argv) {
    srand(time(NULL));

    GameManager game(1, GameManager::RANDOM_AI);

    game.PlayGame();

    return 0;
}

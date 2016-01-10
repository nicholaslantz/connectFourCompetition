/* gamemanager.cpp
 */

#include "gamemanager.hpp"

GameManager::GameManager(int interface1, int interface2) {
    game = ConnectFour();

    // the below code is duplicated because I've had bad luck with calling
    // functions in constructors in the past
    switch (interface1) {
        case USER_INTERFACE:
            player1 = new UserInterface(&game);
            cout << "USER" << endl;
            break;
        case NLANTZ_AI:
            //player1 = new NlantzAI(&game);
            //break;
        case LUCKCOW_AI:
            //player1 = new LuckcowAI(&game);
            //break;
        case RANDOM_AI:
            cout << "RANDOM" << endl;
            player1 = new RandomAI(&game);
            break;
        default:
            cerr << "Error: Interface code not implemented" << endl;
    }

    switch (interface2) {
        case USER_INTERFACE:
            player2 = new UserInterface(&game);
            break;
        case NLANTZ_AI:
            //player2 = new NlantzAI(&game);
            //break;
        case LUCKCOW_AI:
            //player2 = new LuckcowAI(&game);
            //break;
        case RANDOM_AI:
            player1 = new RandomAI(&game);
            break;
        default:
            cerr << "Error: Interface code not implemented" << endl;
    }
}

char GameManager::PlayGame() {
    char gameState = ConnectFour::UNDECIDED;

    cout << ConnectFour::WHITE;
    cout << ConnectFour::BLACK;

    while (gameState == ConnectFour::UNDECIDED) {
        gameState = PlayRound();
    }

    return gameState;
}

char GameManager::PlayRound() {

    char gameState = '\t';
    do {
        player1->TakeTurn();
        char gameState = game.GetGameState();
        cout << gameState << endl;
    } while (gameState == ConnectFour::ILLEGAL_MOVE);

    if (gameState == ConnectFour::WHITE ||
        gameState == ConnectFour::BLACK) {
        return gameState;
    }
    
    do {
        player2->TakeTurn();
        gameState = game.GetGameState();
        cout << gameState << endl;
    } while (gameState == ConnectFour::ILLEGAL_MOVE);

    return gameState;
}

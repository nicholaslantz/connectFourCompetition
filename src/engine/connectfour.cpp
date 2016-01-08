/* connectFour.cpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-08>
 */

ConnectFour::ConnectFour() {
    connectFourBoard = Board();
    gameState = UNDECIDED;
    whitePlayer = DEFAULT_PLAYER_WHITE;
    blackPlayer = DEFAULT_PLAYER_BLACK;
}

ConnectFour::ConnectFour(char newWhitePlayer, char newBlackPlayer) {
    connectFourBoard = Board();
    gameState = UNDECIDED;
    whitePlayer = newWhitePlayer;
    blackPlayer = newBlackPlayer;
}



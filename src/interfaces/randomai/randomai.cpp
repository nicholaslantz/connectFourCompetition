/* randomai.cpp
 */

#include "randomai.hpp"

void RandomAI::TakeTurn() {
    int col = rand() % 7;
    cout << "weird..?" << endl;
    game->TakeTurn(col);
}

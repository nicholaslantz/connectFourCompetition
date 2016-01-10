

#include "userinterface.hpp"

using namespace std;

void UserInterface::TakeTurn() {
    game->PrintBoard(cout);

    // Refactor to another function at some point
    int column = 0;
    bool accepted = false;
    do {
        cout << "(ConnectFour) ";
        
        string buffer;
        getline(cin, buffer);

        if (buffer.length() > 1) {
            cout << "All commands in this menu are 1 character" << endl;
            cout << "Enter \"h\" for a help menu" << endl;
        }

        char userInput = buffer[0];

        // I intend to add more commands here eventually
        switch (userInput) {
            case 'h':
                printHelp();
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                accepted = true;
                column = (int)userInput - (int)'1'; // See ASCII
                break;
            case '0':
            case '8':
            case '9':
                cout << "Sorry, those aren't valid column numbers" << endl;
                cout << "Please enter an integer between 1 and 7" << endl;
                break;
            default:
                cout << "Sorry, I don't recognize that command" << endl;
        }

    } while (!accepted);

    game->TakeTurn(column);
}

void UserInterface::printHelp() {
    cout << "This will be helpful at some point" << endl;
}

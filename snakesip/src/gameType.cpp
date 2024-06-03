#include "gameType.h"

void ManualGame::play() {
    std::cout << "Playing manual game..." << std::endl;
    // Implementation for manual game play
    char choice;

    // Ask for user input.
    std::cout << "Press C to continue next turn, or E to end the game: ";
    do {
        std::cin >> choice;
        std::cout << std::endl; // Simulate pressing enter.
        if (choice != 'C' && choice != 'E') {
            std::cout << "Invalid option, please press C to continue next turn or E to end te game: ";
        }
    } while (choice != 'C' && choice != 'E');

    // Main game loop.
    while (choice == 'C') {
        turn++;
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        int currentPlayer = currentPlayerIndex + 1;
        int currentPosition = players[currentPlayerIndex].getPosition();
        int diceResult = dice.roll();
        int newPosition = currentPosition + diceResult;
        board[newPosition - 1]->landOn(newPosition);

        std::cout << "Turn\tPlayer\tPosition\tDiceResult\tNewPosition" << std::endl;
        std::cout << turn << "\t" << currentPlayer << "\t" << currentPosition + 1 << "\t\t" << diceResult << "\t\t";// << squareType << "\t\t";

        players[currentPlayerIndex].setPosition(newPosition);

        std::cout << std::min(newPosition + 1, 30) << std::endl << std::endl;
        // Check if the game is over.
        if (players[currentPlayerIndex].getPosition() >= 29) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        if (turn >= turns) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "The maximum number of turns has been reached..." << std::endl;
            break;
        }
        // Ask for user input.
        std::cout << "Press C to continue next turn, or E to end the game: ";
        do {
            std::cin >> choice;
            std::cout << std::endl; // Simulate pressing enter.
            if (choice != 'C' && choice != 'E') {
                std::cout << "Invalid option, please press C to continue next turn or E to end te game: ";
            }
        } while (choice != 'C' && choice != 'E');
    }
    if (choice == 'E') {
        std::cout << "Thanks for playing" << std::endl;
    }
}

void AutomaticGame::play() {
    std::cout << "Playing automatic game..." << std::endl;
    // Implementation for automatic game play
    while (turn < turns) {
        // Play a turn.
        turn++;
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        int currentPlayer = currentPlayerIndex + 1;
        int currentPosition = players[currentPlayerIndex].getPosition();
        int diceResult = dice.roll();
        int newPosition = currentPosition + diceResult;
        board[newPosition - 1]->landOn(newPosition);

        std::cout << "Turn\tPlayer\tPosition\tDiceResult\tNewPosition" << std::endl;
        std::cout << turn << "\t" << currentPlayer << "\t" << currentPosition + 1 << "\t\t" << diceResult << "\t\t";// << squareType << "\t\t";

        players[currentPlayerIndex].setPosition(newPosition);

        std::cout << std::min(newPosition + 1, 30) << std::endl << std::endl;

        if (players[currentPlayerIndex].getPosition() >= 29) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        if (turn >= turns) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "The maximum number of turns has been reached..." << std::endl;
            break;
        }
    }

}
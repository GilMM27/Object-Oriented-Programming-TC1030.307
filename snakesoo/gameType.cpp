#include "gameType.h"

void ManualGame::play() {
    std::cout << "Playing manual game..." << std::endl;
    char choice;

    std::cout << "Press C to continue next turn, or E to end the game: ";
    do {
        std::cin >> choice;
        if (choice != 'C' && choice != 'E') {
            std::cout << "Invalid option, please press C to continue next turn or E to end the game: ";
        }
    } while (choice != 'C' && choice != 'E');

    while (choice == 'C') {
        // Play a turn.
        turn++;
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        int currentPlayer = currentPlayerIndex + 1;
        int currentPosition = players[currentPlayerIndex].getPosition();
        int diceResult = dice.roll();
        int newPosition = currentPosition + diceResult;
        // If the new position is greater than the number of tiles, the player is declared as the winner instantly.
        if (newPosition > tiles) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        newPosition = *board[newPosition - 1] + newPosition;
        // Print the current turn information.
        Turn currentTurn(turn, currentPlayer, currentPosition, diceResult, std::min(newPosition + 1, turns));
        std::cout << currentTurn;

        players[currentPlayerIndex].setPosition(newPosition);
        // Check for the game over conditions.
        if (players[currentPlayerIndex].getPosition() >= tiles - 1) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        if (turn >= turns) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "The maximum number of turns has been reached..." << std::endl;
            break;
        }

        std::cout << "Press C to continue next turn, or E to end the game: ";
        do {
            std::cin >> choice;
            if (choice != 'C' && choice != 'E') {
                std::cout << "Invalid option, please press C to continue next turn or E to end the game: ";
            }
        } while (choice != 'C' && choice != 'E');
    }

    if (choice == 'E') {
        std::cout << "Thanks for playing" << std::endl;
    }
}

void AutomaticGame::play() {
    std::cout << "Playing automatic game..." << std::endl;
    while (turn < turns) {
        // Play a turn.
        turn++;
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        int currentPlayer = currentPlayerIndex + 1;
        int currentPosition = players[currentPlayerIndex].getPosition();
        int diceResult = dice.roll();
        int newPosition = currentPosition + diceResult;
        // If the new position is greater than the number of tiles, the player is declared as the winner instantly.
        if (newPosition >= tiles - 1) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        newPosition = *board[newPosition - 1] + newPosition;
        // Print the current turn information.
        Turn currentTurn(turn, currentPlayer, currentPosition, diceResult, std::min(newPosition + 1, tiles));
        std::cout << currentTurn;

        players[currentPlayerIndex].setPosition(newPosition);
        // Check for the game over conditions.
        if (players[currentPlayerIndex].getPosition() >= tiles - 1) {
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

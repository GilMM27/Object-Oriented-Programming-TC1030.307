#include "mygame.h"
#include <iostream>

MyGame::MyGame() {
    currentPlayerIndex = -1;
    turn = 0;
}

void MyGame::start() {
    char choice;

    // Ask for user input.
    std::cout << "Press C to continue next turn, or E to end the game: ";
    do {
        std::cin >> choice;
        if (choice != 'C' && choice != 'E') {
            std::cout << "Invalid option, please press C to continue next turn or E to end te game: ";
        }
    } while (choice != 'C' && choice != 'E');

    // Main game loop.
    while (choice == 'C') {
        playTurn();
        // Check if the game is over.
        if (players[currentPlayerIndex].getPosition() >= 29) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "Player " << currentPlayerIndex + 1 << " is the winner!!!" << std::endl;
            break;
        }
        if (turn >= kMaxTurns) {
            std::cout << "--GAME OVER--" << std::endl;
            std::cout << "The maximum number of turns has been reached..." << std::endl;
            break;
        }
        // Ask for user input.
        std::cout << "Press C to continue next turn, or E to end the game: ";
        do {
            std::cin >> choice;
            if (choice != 'C' && choice != 'E') {
                std::cout << "Invalid option, please press C to continue next turn or E to end te game: ";
            }
        } while (choice != 'C' && choice != 'E');
    }
    if (choice == 'E') {
        std::cout << "Thanks for playing" << std::endl;
    }
}

void MyGame::playTurn() {
    turn++;
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    int currentPlayer = currentPlayerIndex + 1;
    int currentPosition = players[currentPlayerIndex].getPosition();
    int diceResult = dice.roll();
    char squareType = board.getSquareType(currentPosition + diceResult - 1);
    int newPosition;

    std::cout << "Index\tPlayer\tPosition\tDiceResult\tSquareType\tNewPosition" << std::endl;
    std::cout << currentPlayerIndex << "\t" << currentPlayer << "\t" << currentPosition + 1 << "\t\t" << diceResult << "\t\t" << squareType << "\t\t";

    newPosition = currentPosition + diceResult;
    if (squareType == 'S') {
        newPosition -= 3;
    } else if (squareType == 'L') {
        newPosition += 3;
    }

    if (newPosition < 0) {
        newPosition = 0; 
    }

    players[currentPlayerIndex].setPosition(newPosition);

    std::cout << std::min(newPosition + 1, 30) << std::endl << std::endl;
}

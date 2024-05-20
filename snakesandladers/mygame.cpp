#include "mygame.h"
#include <iostream>

MyGame::MyGame() : currentPlayerIndex(0) {}

void MyGame::start() {
    char choice;

    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl;
    std::cin >> choice;

    while (choice == 'C') {
        playTurn();
        std::cout << "Press C to continue next turn, or E to end the game:" << std::endl;
        std::cin >> choice;
    }

    std::cout << "Thanks for playing" << std::endl;
}

void MyGame::playTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    int currentPlayer = currentPlayerIndex + 1;
    int currentPosition = players[currentPlayerIndex].getPosition();
    int diceResult = dice.roll();
    char squareType = board.getSquareType(currentPosition + diceResult - 1);
    int newPosition;

    std::cout << (currentPlayerIndex + 1) << " " << currentPlayer << " " << currentPosition + 1 << " " << diceResult << " " << squareType << " ";

    if (squareType == 'N') {
        newPosition = currentPosition + diceResult;
    } else if (squareType == 'S') {
        newPosition = currentPosition - 3;
    } else if (squareType == 'L') {
        newPosition = currentPosition + 3;
    }

    if (newPosition < 0) {
        newPosition = 0; 
    }

    players[currentPlayerIndex].setPosition(newPosition);

    std::cout << newPosition + 1 << std::endl;
}

#ifndef TURN_H
#define TURN_H

#include <iostream>

class Turn {
public:
    int turnNumber;
    int currentPlayer;
    int currentPosition;
    int diceResult;
    int newPosition;

    Turn(int turnNumber, int currentPlayer, int currentPosition, int diceResult, int newPosition);
    friend std::ostream& operator<<(std::ostream& os, const Turn& turn);
};

#endif // TURN_H
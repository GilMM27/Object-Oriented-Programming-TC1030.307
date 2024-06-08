#include "Turn.h"

Turn::Turn(int turnNumber, int currentPlayer, int currentPosition, int diceResult, int newPosition)
    : turnNumber(turnNumber), currentPlayer(currentPlayer), currentPosition(currentPosition), diceResult(diceResult), newPosition(newPosition) {}

std::ostream& operator<<(std::ostream& os, const Turn& turn) {
    os << "Turn\tPlayer\tPosition\tDiceResult\tNewPosition" << std::endl;
    os << turn.turnNumber << "\t" << turn.currentPlayer << "\t" << turn.currentPosition + 1 << "\t\t" << turn.diceResult << "\t\t" << turn.newPosition << std::endl;
    return os;
}

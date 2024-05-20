#include "board.h"
#include <cstdlib>

Board::Board() {
  
    for (int i = 0; i < 30; ++i) {
        squares[i] = 'N';
    }

    for (int i = 0; i < 3; ++i) {
        int snakePos = rand() % 30;
        squares[snakePos] = 'S';
    }

    for (int i = 0; i < 3; ++i) {
        int ladderPos = rand() % 30;
        squares[ladderPos] = 'L';
    }
}

char Board::getSquareType(int position) {
    return squares[position];
}

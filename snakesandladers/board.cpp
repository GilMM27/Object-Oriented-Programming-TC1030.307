#include "board.h"
#include <cstdlib>

Board::Board() {
  
    for (int i = 0; i < 30; ++i) {
        squares[i] = 'N';
    }

    for (int i = 0; i < 3; ++i) {
        // Get a position where there is no snake or ladder
        do {
            int snakePos = rand() % 30;
            if (squares[snakePos] == 'N') {
                squares[snakePos] = 'S';
                break;
            }
        } while (true);
    }

    for (int i = 0; i < 3; ++i) {
        // Get a position where there is no snake or ladder
        do {
            int ladderPos = rand() % 30;
            if (squares[ladderPos] == 'N') {
                squares[ladderPos] = 'L';
                break;
            }
        } while (true);
    }
}

char Board::getSquareType(int position) {
    return squares[position];
}

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char squares[30]; 
public:
    Board();
    char getSquareType(int position);
};

#endif



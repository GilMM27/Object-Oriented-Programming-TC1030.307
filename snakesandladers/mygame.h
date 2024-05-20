#ifndef MYGAME_H
#define MYGAME_H

#include "dice.h"
#include "board.h"
#include "player.h"

class MyGame {
private:
    Dice dice;
    Board board;
    Player players[2];
    int currentPlayerIndex;
public:
    MyGame();
    void start();
    void playTurn();
};

#endif


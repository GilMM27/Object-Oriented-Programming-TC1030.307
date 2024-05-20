#ifndef MYGAME_H
#define MYGAME_H

#include "dice.h"
#include "board.h"
#include "player.h"

const int kMaxTurns = 100;

class MyGame {
private:
    Dice dice;
    Board board;
    Player players[2];
    int currentPlayerIndex;
    int turn;
public:
    MyGame();
    void start();
    void playTurn();
};

#endif


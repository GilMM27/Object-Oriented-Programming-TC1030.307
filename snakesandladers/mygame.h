#ifndef MYGAME_H
#define MYGAME_H

#include "dice.cpp"
#include "board.cpp"
#include "player.cpp"

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


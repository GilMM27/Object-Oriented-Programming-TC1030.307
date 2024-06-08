#ifndef MYGAME_H
#define MYGAME_H

#include <vector>
#include <string>
#include "player.h"
#include "dice.h"
#include "Turn.h"

class Square {
public:
    virtual ~Square() {}
    virtual int operator+(int position) = 0;
};

class NormalSquare : public Square {
public:
    int operator+(int position) override;
};

class SnakeSquare : public Square {
private:
    int penalty;
public:
    SnakeSquare(int penalty);
    int operator+(int position) override;
};

class LadderSquare : public Square {
private:
    int reward;
public:
    LadderSquare(int reward);
    int operator+(int position) override;
};

class MyGame {
protected:
    int tiles;
    int snakes;
    int ladders;
    int penalty;
    int reward;
    int playersNum;
    int turns;
    int turn;
    int currentPlayerIndex;
    Dice dice;
    std::vector<Player> players;
    std::vector<Square*> board;
public:
    MyGame(int tiles, int snakes, int ladders, int penalty, int reward, int playersNum, int turns);
    ~MyGame();
    void initializeBoard();
    virtual void play();
};

#endif // MYGAME_H

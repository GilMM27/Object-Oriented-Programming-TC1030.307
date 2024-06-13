#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <iostream>
#include "mygame.h"

// class GameType : public MyGame {
// public:
//     virtual ~GameType() {}
//     virtual void play() = 0;
// };

class ManualGame : public MyGame {
public:
    ManualGame(int tiles, int snakes, int ladders, int penalty, int reward, int playersNum, int turns) : MyGame(tiles, snakes, ladders, penalty, reward, playersNum, turns) {};
    void play() override;
};

class AutomaticGame : public MyGame {
public:
    AutomaticGame(int tiles, int snakes, int ladders, int penalty, int reward, int playersNum, int turns) : MyGame(tiles, snakes, ladders, penalty, reward, playersNum, turns) {};
    void play() override;
};

#endif // GAMETYPE_H
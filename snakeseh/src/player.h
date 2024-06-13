#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int position;
public:
    Player();
    void setPosition(int newPosition);
    int getPosition();
};

#endif
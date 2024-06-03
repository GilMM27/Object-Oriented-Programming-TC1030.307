#include "player.h"

Player::Player() : position(0) {}

void Player::setPosition(int newPosition) {
    position = newPosition;
}

int Player::getPosition() {
    return position;
}

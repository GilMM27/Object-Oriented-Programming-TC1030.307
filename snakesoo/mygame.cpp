#include "mygame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int NormalSquare::operator+(int position) {
    return position;
}

SnakeSquare::SnakeSquare(int penalty) : penalty(penalty) {}

int SnakeSquare::operator+(int position) {
    std::cout << "You stepped on a snake! You move back " << penalty << " steps." << std::endl;
    return std::max(position - penalty, 0);
}

LadderSquare::LadderSquare(int reward) : reward(reward) {}

int LadderSquare::operator+(int position) {
    std::cout << "You found a ladder! You move forward " << reward << " steps." << std::endl;
    return position + reward;
}

MyGame::MyGame(int tiles, int snakes, int ladders, int penalty, int reward, int playersNum, int turns)
    : tiles(tiles), snakes(snakes), ladders(ladders), penalty(penalty), reward(reward), players(playersNum), turns(turns) {
    currentPlayerIndex = -1;
    turn = 0;
    initializeBoard();
}

MyGame::~MyGame() {
    for (Square* square : board) {
        delete square;
    }
}

void MyGame::initializeBoard() {
    srand(time(0));
    for (int i = 0; i < tiles; ++i) {
        board.push_back(new NormalSquare());
    }
    for (int i = 0; snakes > 0; ++i) {
        int position = rand() % tiles;
        if (dynamic_cast<NormalSquare*>(board[position])) {
            delete board[position];
            board[position] = new SnakeSquare(penalty);
            --snakes;
        }
    }
    for (int i = 0; ladders > 0; ++i) {
        int position = rand() % tiles;
        if (dynamic_cast<NormalSquare*>(board[position])) {
            delete board[position];
            board[position] = new LadderSquare(reward);
            --ladders;
        }
    }
}

void MyGame::play() {
    std::cout << "No game type selected..." << std::endl;
}

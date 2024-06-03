#include "mygame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void NormalSquare::landOn(int& position) {
    // Normal square, no action needed
}

SnakeSquare::SnakeSquare(int penalty) : penalty(penalty) {}

void SnakeSquare::landOn(int& position) {
    position -= penalty;
    position = std::max(position, 0);
    std::cout << "Landed on a snake! Go back " << penalty << " squares." << std::endl;
}

LadderSquare::LadderSquare(int reward) : reward(reward) {}

void LadderSquare::landOn(int& position) {
    position += reward;
    std::cout << "Landed on a ladder! Move forward " << reward << " squares." << std::endl;
}

MyGame::MyGame(int tiles, int snakes, int ladders, int penalty, int reward, int playersNum, int turns) 
    : tiles(tiles), snakes(snakes), ladders(ladders), penalty(penalty), reward(reward), players(playersNum), turns(turns) {
    currentPlayerIndex = -1;
    turn = 0;
    initializeBoard();
}

MyGame::~MyGame() {
    // delete gameType;
    for (Square* square : board) {
        delete square;
    }
}

void MyGame::initializeBoard() {
    srand(time(0));
    for (int i = 0; i < tiles; ++i) {
        board.push_back(new NormalSquare());
    }
    for (int i = 0; i < snakes; ++i) {
        int position = rand() % tiles;
        delete board[position];
        board[position] = new SnakeSquare(penalty);
    }
    for (int i = 0; i < ladders; ++i) {
        int position = rand() % tiles;
        delete board[position];
        board[position] = new LadderSquare(reward);
    }
}

void MyGame::play() {
    std::cout << "No game type selected..." << std::endl;
}
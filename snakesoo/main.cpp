#include "gameType.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 9) {
        std::cerr << "Usage: " << argv[0] << " <tiles> <snakes> <ladders> <penalty> <reward> <players> <turns> <gameType>" << std::endl;
        return 1;
    }

    int tiles = std::stoi(argv[1]);
    int snakes = std::stoi(argv[2]);
    int ladders = std::stoi(argv[3]);
    int penalty = std::stoi(argv[4]);
    int reward = std::stoi(argv[5]);
    int players = std::stoi(argv[6]);
    int turns = std::stoi(argv[7]);
    char gameType = argv[8][0];

    if (gameType == 'A') {
        AutomaticGame game(tiles, snakes, ladders, penalty, reward, players, turns);
        game.play();
    } else if (gameType == 'M') {
        ManualGame game(tiles, snakes, ladders, penalty, reward, players, turns);
        game.play();
    }

    return 0;
}

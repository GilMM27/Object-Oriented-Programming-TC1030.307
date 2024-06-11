#include "gameType.h"
#include "exceptions.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    try {
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

        if (tiles <= 0 || snakes < 0 || ladders < 0 || penalty < 0 || reward < 0 || players <= 0 || turns <= 0) {
            throw InvalidConfigurationException("parameter", -1);
        }

        if (gameType == 'A') {
            AutomaticGame game(tiles, snakes, ladders, penalty, reward, players, turns);
            game.play();
        } else if (gameType == 'M') {
            ManualGame game(tiles, snakes, ladders, penalty, reward, players, turns);
            game.play();
        } else {
            throw InvalidConfigurationException("gameType", gameType);
        }

    } catch (const InvalidConfigurationException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

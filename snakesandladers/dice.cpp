#include "dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    srand(time(0)); 
}

int Dice::roll() {
    return rand() % 6 + 1; 
}

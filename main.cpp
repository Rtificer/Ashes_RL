#include <random>
#include "./Game/effects.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    ChangeTwoDiceInYourActivePoolToASideOfYourChoice test;
    Game<2> game;
    test.resolve(game);
}
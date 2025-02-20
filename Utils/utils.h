#include <cstdint>
#include <random>

uint8_t RollDie(std::mt19937 & gen) {
    //1 = Basic
    static std::uniform_int_distribution<uint8_t> distribution(1,6);
    uint8_t Roll = distribution(gen);

    switch (Roll){
        case 1:
        case 2:
            //Basic Symbol
            return 1;
        case 3:
        case 4:
        case 5:
            //Class Symbol
            return 2;
        case 6:
            //Power Symbol
            return 3;
    }
}
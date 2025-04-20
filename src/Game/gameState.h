#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>
#include <array>
#include <memory>

#include "effectStepRepresentation.h"

struct gameStateConfig {
    uint8_t player1MaxCards;
    uint8_t player2MaxCards;
};

template <uint8_t player1MaxCards, uint8_t player2MaxCards>
class gameState {
    public:
        uint8_t currentTurn;
        //bits 1-3 = currentSubphase (Roll Dice, Discard Cards, Draw Cards, Player Turns, Recover, Remove Exhaustion, Exhaust Dice, End of Round)
        //bit 4 = firstPlayerID
        //bit 5 = activePlayerID
        //bit 6-8 (unused)
        uint8_t additionalGameStateData;
        std::array<effectStepRepresentation, 64> effectStepStack;

        std::array<std::shared_ptr<cardRepresentation>, player1MaxCards + player2MaxCards> cards;

        std::array<uint8_t, 10> player1ActivePool;
        std::array<uint8_t, 10> player2ActivePool;
        std::array<uint8_t, 10> player1ExhaustedPool;
        std::array<uint8_t, 10> player2ExhaustedPool;
};

#endif
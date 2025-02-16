#include <array>
#include <cstdint>
#include <vector>

#include "cardrepresentation.h"

template <uint8_t MaxConjurationPileSize, uint8_t MaxSpellBoardSize, uint8_t MaxBattlefieldSize>
class Player {
    public:

        CardRepresentation PhoenixBorn;

        //Array of Card ID's
        std::array<uint8_t, 30> Hand;
        std::array<uint8_t, 30> DiscardPile;
        std::array<uint8_t, MaxConjurationPileSize> ConjurationPile;


        std::array<CardRepresentation, MaxSpellBoardSize> SpellBoard;
        std::array<CardRepresentation, MaxBattlefieldSize> Battlefield;

        std::array<uint8_t, 10> ActiveDiePool;
        std::array<uint8_t, 10> ExhaustedDiePool;

};
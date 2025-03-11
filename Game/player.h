#include <array>
#include <cstdint>
#include <variant>

#include "cardrepresentation.h"
#include <stdexcept>


class Player {
    public:

        CardRepresentation PhoenixBorn;

        //Array of Card ID's
        std::array<uint8_t, 30> Hand;
        std::array<uint8_t, 30> DiscardPile;
        std::array<uint8_t, 64> ConjurationPile;


        std::array<CardRepresentation, 5> SpellBoard;
        std::array<CardRepresentation, 11> Battlefield;

        uint8_t TotalActiveDice;
        std::array<uint8_t, 10> ActiveDiePool;
        std::array<uint8_t, 10> ExhaustedDiePool;

        using CardZone = std::variant<
            std::array<uint8_t, 30>*,
            std::array<uint8_t, 64>*,
            std::array<CardRepresentation, 5>*,
            std::array<CardRepresentation, 11>*
        >;

        CardZone GetLocation(uint8_t locationindex) {
            switch(locationindex) {
                case 0:
                    return &Hand;
                case 1:
                    return &DiscardPile;
                case 2:
                    return &ConjurationPile;
                case 3:
                    return &SpellBoard;
                case 4:
                    return &Battlefield;
                default:
                    throw std::out_of_range("Invalid location");
            }
        }
};

using CardZone = std::variant<
    std::array<uint8_t, 30>*,
    std::array<uint8_t, 64>*,
    std::array<CardRepresentation, 5>*,
    std::array<CardRepresentation, 11>*
>;

uint8_t GetLocationType(Player::CardZone cardzone) {
    //Lambda function to determine the type of the variant
    std::visit([](auto &&arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::array<uint8_t, 30>>) {
            return 0;
        } else if constexpr (std::is_same_v<T, std::array<uint8_t, 64>>) {
            return 1;
        } else if constexpr (std::is_same_v<T, std::array<CardRepresentation, 5>>) {
            return 2;
        } else if constexpr (std::is_same_v<T, std::array<CardRepresentation, 11>>) {
            return 3;
        }
    }, cardzone);
};
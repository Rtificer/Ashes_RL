#include "../../Game/card.h"

const class Activate_Dice_Power : public Effect<2, 2> {
    public:
        constexpr Activate_Dice_Power() : Effect<2, 2>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {1, 11},
            /*Effect Step(s):*/ {SearchDiscardForAlly(), DealOneDamageToYourPhoenixborn()}
        ) {}
    };

const class Ceremonial_Reference : public Card<0, 1> {
    public:
        static Ceremonial_Reference& getInstance() {
            static Ceremonial_Reference instance;
            return instance;
        }

    private:
        constexpr Ceremonial_Reference() : Card<0, 1>(
            /*CardID:*/ 1,
            /*Type:*/ 1,
            /*Placement:*/ 0,
            /*Play Cost:*/ {1, 16},
            /*Effect(s):*/ {Activate_Dice_Power()}
        ) {}

        // Delete copy constructor and assignment operator
        Ceremonial_Reference(const Ceremonial_Reference&) = delete;
        Ceremonial_Reference& operator=(const Ceremonial_Reference&) = delete;
};
#include "../../Game/card.h"

const class ActivateShiftingMist : public Effect<1, 2> {
    public:
        constexpr ActivateShiftingMist() : Effect<1, 2>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {1, 3},
            /*Effect Step(s):*/ {ChangeTwoDiceInYourActivePoolToASideOfYourChoice()}
        ) {}
};

const class Shifting_Mist : public Card<1, 2> {
    public:
        constexpr Shifting_Mist() : Card<1, 2> (
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Effect(s):*/ {ActivateShiftingMist()},
            /*Play Cost:*/ {0, 12}
        ) {}
}; 
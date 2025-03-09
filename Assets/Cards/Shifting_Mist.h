#include "../../Game/card.h"

const class ActivateShiftingMist : public Effect<2, 1> {
    public:
        constexpr ActivateShiftingMist() : Effect<2, 1>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {1, 3},
            /*Effect Step(s):*/ {ChangeTwoDiceInYourActivePoolToASideOfYourChoice()}
        ) {}
};

const class Shifting_Mist : public Card<2, 1> {
    public:
        static Shifting_Mist& getInstance() {
            static Shifting_Mist instance;
            return instance;
        }

    private:
        constexpr Shifting_Mist() : Card<2, 1> (
            /*CardID:*/ 2,
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Play Cost:*/ {0, 12},
            /*Effect(s):*/ {ActivateShiftingMist()}
        ) {}

        // Delete copy constructor and assignment operator
        Shifting_Mist(const Shifting_Mist&) = delete;
        Shifting_Mist& operator=(const Shifting_Mist&) = delete;
};
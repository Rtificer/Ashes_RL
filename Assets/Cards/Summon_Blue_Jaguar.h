#include "../../Game/card.h"

class ActivateSummon_Blue_Jaguar : public Effect<1, 4> {
    public:
        constexpr ActivateSummon_Blue_Jaguar() : Effect<1, 4>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {0, 3, 5, 5},
            /*Effect Step(s):*/ {PlaceBlue_JaguarOntoYourBattlefield()}
        ) {}
};

class Summon_Blue_Jaguar : public Card<1, 1> {
    public:
        constexpr Summon_Blue_Jaguar() : Card<1, 1> (
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Effect(s):*/ {ActivateSummon_Blue_Jaguar()},
            /*Play Cost:*/ {0}
        ) {}
};
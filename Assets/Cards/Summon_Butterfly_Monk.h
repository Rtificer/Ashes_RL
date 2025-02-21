#include "../../Game/card.h"

const class ActivateSummon_Butterfly_Monk : public Effect<1, 3> {
    public:
        constexpr ActivateSummon_Butterfly_Monk() : Effect<1, 3>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {0, 3, 7},
            /*Effect Step(s):*/ {PlaceButterfly_MonkOntoYourBattlefield()}
        ) {}
};

const class Summon_Butterfly_Monk : public Card<1, 1> {
    public:
        constexpr Summon_Butterfly_Monk() : Card<1, 1> (
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Effect(s):*/ {ActivateSummon_Butterfly_Monk()},
            /*Play Cost:*/ {0}
        ) {}
};
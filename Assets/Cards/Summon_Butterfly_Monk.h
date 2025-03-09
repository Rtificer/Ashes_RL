#include "../../Game/card.h"

const class ActivateSummon_Butterfly_Monk : public Effect<3, 1> {
    public:
        constexpr ActivateSummon_Butterfly_Monk() : Effect<3, 1>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {0, 3, 7},
            /*Effect Step(s):*/ {PlaceButterfly_MonkOntoYourBattlefield()}
        ) {}
};

const class Summon_Butterfly_Monk : public Card<1, 1> {
    public:
        static Summon_Butterfly_Monk& getInstance() {
            static Summon_Butterfly_Monk instance;
            return instance;
        }

    private:
        constexpr Summon_Butterfly_Monk() : Card<1, 1> (
            /*CardID:*/ 4,
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Play Cost:*/ {0},
            /*Effect(s):*/ {ActivateSummon_Butterfly_Monk()}
        ) {}

        // Delete copy constructor and assignment operator
        Summon_Butterfly_Monk(const Summon_Butterfly_Monk&) = delete;
        Summon_Butterfly_Monk& operator=(const Summon_Butterfly_Monk&) = delete;
};
#include "../../Game/card.h"

const class ActivateSummon_Blue_Jaguar : public Effect<4, 1> {
    public:
        constexpr ActivateSummon_Blue_Jaguar() : Effect<4, 1>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {0, 3, 5, 5},
            /*Effect Step(s):*/ {PlaceBlue_JaguarOntoYourBattlefield()}
        ) {}
};

const class Summon_Blue_Jaguar : public Card<1, 1> {
    public:
        static Summon_Blue_Jaguar& getInstance() {
            static Summon_Blue_Jaguar instance;
            return instance;
        }
    
    private:
        constexpr Summon_Blue_Jaguar() : Card<1, 1> (
            /*CardID:*/ 3,
            /*Type:*/ 0,
            /*Placement:*/ 2,
            /*Play Cost:*/ {0},
            /*Effect(s):*/ {ActivateSummon_Blue_Jaguar()}
        ) {}

        // Delete copy constructor and assignment operator
        Summon_Blue_Jaguar(const Summon_Blue_Jaguar&) = delete;
        Summon_Blue_Jaguar& operator=(const Summon_Blue_Jaguar&) = delete;
};
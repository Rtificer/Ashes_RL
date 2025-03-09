#include "../../Game/card.h"

const class PlayHeal : public Effect<0, 2> {
    public:
        constexpr PlayHeal() : Effect<0, 2>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {},
            /*Effect Step(s):*/ {RemoveAllWoundTokensFromTargetUnit(), RemoveTwoWoundTokensFromTargetPhoenixborn()}
        ) {}
    };

const class Heal : public Card<2, 1> {
    public:
        static Heal& getInstance() {
            static Heal instance;
            return instance;
        }

    private:
        constexpr Heal() : Card<2, 1>(
            /*CardID:*/ 1,
            /*Type:*/ 1,
            /*Placement:*/ 0,
            /*Play Cost:*/ {1, 16},
            /*Effect(s):*/ {PlayHeal()}
        ) {}

        // Delete copy constructor and assignment operator
        Heal(const Heal&) = delete;
        Heal& operator=(const Heal&) = delete;
};
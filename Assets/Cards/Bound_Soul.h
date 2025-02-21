#include "../../Game/card.h"

const class PlayBoundSoul : public Effect<1, 0> {
    public:
        constexpr PlayBoundSoul() : Effect<1, 0>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {},
            /*Effect Step(s):*/ {SearchDiscardForAlly()}
        ) {}
};

const class Bound_Soul : public Card<1, 2> {
    public:
        constexpr Bound_Soul() : Card<1, 2> (
            /*Type:*/ 1,
            /*Placement:*/ 0,
            /*Effect(s):*/ {PlayBoundSoul()},
            /*Play Cost:*/ {0, 10}
        ) {}
};
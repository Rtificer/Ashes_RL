#include "../../Game/card.h"

class PlayHeal : public Effect<2, 0> {
    public:
        constexpr PlayHeal() : Effect<2, 0>(
            //EffectSteps
            {RemoveAllWoundTokensFromTargetUnit(), RemoveTwoWoundTokensFromTargetPhoenixborn()}, 
            //IsAbility?
            false
        ) {}
    };

class Heal : public Card<1, 2> {
    public:
        constexpr Heal() : Card<1, 2>(
            /*Type:*/ 1,
            /*Placement:*/ 0,
            /*Effect(s):*/ {PlayHeal()},
            /*Play Cost:*/ {1, 15}
        ) {}
};
        
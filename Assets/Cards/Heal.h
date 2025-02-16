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

class Heal : public ActionSpell<1, 2> {
    public:
        constexpr Heal() : ActionSpell<1, 2>(
            //Cost Vector
            {1, 15},
            //Effects
            {PlayHeal()}
        ) {}
};
        
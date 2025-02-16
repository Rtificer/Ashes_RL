#include "../../Game/card.h"

class PlayBoundSoul : public Effect<1, 0> {
    public:
        constexpr PlayBoundSoul() : Effect<1, 0>(
            //EffectSteps
            {SearchDiscardForAlly()}, 
            //IsAbility?
            false
        ) {}
};

class Bound_Soul : public ActionSpell<1, 2> {
    public:
        Bound_Soul() {
            PlayCost = {0, 9};
            Effects[0] = std::make_unique<PlayBoundSoul>();
        }
};
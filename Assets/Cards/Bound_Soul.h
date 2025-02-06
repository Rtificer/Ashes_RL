#include "../../Game/card.h"

class PlayBoundSoul : public Effect<2, 0> {
    public:
        PlayBoundSoul() {
            isAbility = false;
            Steps[0] = std::make_unique<SearchDiscardForAlly>();
        }
};

class Bound_Soul : public ActionSpell<1, 1> {
    public:
        Bound_Soul() {
            PlayCost = {9};
            Effects[0] = std::make_unique<PlayBoundSoul>();
        }
};
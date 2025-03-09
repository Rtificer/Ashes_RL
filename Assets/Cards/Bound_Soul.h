#include "../../Game/card.h"

const class PlayBoundSoul : public Effect<0, 1> {
    public:
        constexpr PlayBoundSoul() : Effect<0, 1>(
            /*Is Ability:*/ false,
            /*Play Cost:*/ {},
            /*Effect Step(s):*/ {SearchDiscardForAlly()}
        ) {}
};

const class Bound_Soul : public Card<2, 1> {
    public:
        static Bound_Soul& getInstance() {
            static Bound_Soul instance;
            return instance;
        }

    private:
        constexpr Bound_Soul() : Card<2, 1> (
            /*CardID:*/ 0,
            /*Type:*/ 1,
            /*Placement:*/ 0,
            /*Play Cost:*/ {0, 10},
            /*Effect(s):*/ {PlayBoundSoul()}
        ) {}

        // Delete copy constructor and assignment operator
        Bound_Soul(const Bound_Soul&) = delete;
        Bound_Soul& operator=(const Bound_Soul&) = delete;
};
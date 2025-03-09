#include "../../Game/card.h"

const class Gaze : public Effect<0, 2> {
    public:
        constexpr Gaze() : Effect<0, 2>(
            /*Is Ability:*/ true,
            /*Play Cost:*/ {},
            /*Effect Step(s):*/ {PlaceButterfly_MonkOntoYourBattlefield()}
        ) {}
};

const class Blue_Jaguar : public Card<0, 1> {
    public:
        static Blue_Jaguar& getInstance() {
            static Blue_Jaguar instance;
            return instance;
        }

    private:
        constexpr Blue_Jaguar() : Card<0, 1> (
            /*CardID:*/ 5,
            /*Type:*/ 5,
            /*Placement:*/ 1,
            /*Play Cost:*/ {},
            /*Effect(s):*/ {Gaze()},
            /*Starting Attack Value:*/ 1,
            /*Starting Life Value:*/ 2,
            /*Starting Recover Value:*/ 0,
            /*Conjuration Limit:*/ 2
        ) {}

        // Delete copy constructor and assignment operator
        Blue_Jaguar(const Blue_Jaguar&) = delete;
        Blue_Jaguar& operator=(const Blue_Jaguar&) = delete;
};
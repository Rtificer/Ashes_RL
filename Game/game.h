#include <cstdint>
#include <array>
#include <stack>
#include "player.h"

struct CardLocation {
    uint8_t PlayerIndex;
    //Discard = 0, Spellboard = 1, Battlefield = 2, 3 = Dice Power, 4 = Removed from the game, 5 = Limbo
    //PlayerIndex will be ignored in the case of 3-5
    uint8_t Zone;
    uint8_t CardIndex;
    uint8_t EffectIndex;
    uint8_t EffectStepIndex;
};

struct ResolvingEffectStep {

    uint8_t DependentEffectStepIndex; //Optional, = 255 if not dependent, specifies the index of the effectstep in the stack triggering this effectstep.

    CardLocation OriginCard;
    std::array<CardLocation, 10> TargetCards;
};

template<uint8_t PlayerCount>
struct GameState {
    public:
        uint8_t CurrentTurn;
        uint8_t CurrentPhase;

        uint8_t FirstPlayerIndex;
        uint8_t ActivePlayerIndex;
        uint8_t CurrentAction;

        uint8_t TotalResolvingEffects;
        std::array<ResolvingEffectStep, 16> ResolvingEffectsStack;

        std::array<Player, PlayerCount> Players;
};

template <uint8_t PlayerCount>
class Game {
    public:
        GameState<PlayerCount> gamestate;

        GameState<PlayerCount> CaptureState() {
            return gamestate;
        }

        void AdvanceTurn() {

            if (gamestate.FirstPlayerIndex == gamestate.PlayerCount) {
                gamestate.FirstPlayerIndex = 0;
            }
            else {
                gamestate.FirstPlayerIndex++;
            }

            gamestate.CurrentTurn++;
        }

        void AdvancePhase() {
            //TODO: Replace 6 with whatever the last phase number is.
            if (gamestate.CurrentPhase = 6) {
                gamestate.CurrentPhase = 0;
            }
            else {
                gamestate.CurrentPhase++;
            }
        }

        bool DealDamage(CardRepresentation card) {
            //Step 1
                //Effects that trigger "after damage is dealt" may now be used. Most effects will prevent one or more damage from being received in step 2.
            //Step 2
            if(card.t)
        }

};
#include <cstdint>
#include <array>
#include <stack>
#include "player.h"
#include "../Utils/CardRegistry.h"

struct CardLocation {
    uint8_t PlayerIndex;
    //0 = Hand, 1 = DiscardPile, 2 = ConjurationPile, 3 = SpellBoard, 4 = Battlefield, 5 = Dice Power, 6 = Limbo
    //PlayerIndex will be ignored in the case of 3-5
    uint8_t Zone;
    uint8_t CardIndex;
    uint8_t EffectIndex;
    uint8_t EffectStepIndex;
};

struct EffectStepRepresentation {

    uint8_t DependentEffectStepIndex; //Optional, = 255 if not dependent, specifies the index of the effectstep in the stack triggering this effectstep.

    CardLocation OriginCard;
    std::array<CardLocation, 10> TargetCards;
    uint8_t Duration; // 0 = Immediate, 1 = End of Turn, 2 = End of Round
    uint8_t RemainingDuration; //X turns/rounds remaining
    
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
        uint8_t EndOfTurnEffectCount;
        std::array<ResolvingEffectStep, 16> EndOfTurnEffects;
        uint8_t EndOfRoundEffectCount;
        std::array<ResolvingEffectStep, 16> EndOfRoundEffects;

        std::array<Player, PlayerCount> Players;

        uint8_t LimboCardCount;
        std::array<CardRepresentation, 60> Limbo;
};

template <uint8_t PlayerCount>
class Game {
    public:
        GameState<PlayerCount> gamestate;

        GameState<PlayerCount> CaptureState() {
            return gamestate;
        }

        auto GetCardFromLocation(CardLocation location) {
            switch(location.Zone) {
                case 5:
                    switch(location.CardIndex){
                        case 0:
                            return 
                    }
                case 6:
                    if (CardIndex >= gamestate.LimboCardCount) {
                        return nullptr;
                    }
                    return gamestate.Limbo[location.CardIndex];
            }
            else {
                if (location.PlayerIndex >= PlayerCount) {
                    return nullptr;
                }
            }
            return gamestate.Players[location.PlayerIndex].GetLocation(location.Zone)[location.CardIndex];
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

        bool DealDamage(CardLocation location, uint8_t damage) {
            //Step 1
                //Effects that trigger "after damage is dealt" may now be used. Most effects will prevent one or more damage from being received in step 2.
            //Step 2
            cardrepresentation.woundTokenCount += damage;
            if(cardrepresentation.woundTokenCount >= cardrepresentation.currentLifeValue) {
                card = CardRegistry::getInstance().getCard(cardID);
                
                if (card != nullptr && card->getType() == 6) {
                    //End the game.
                    return true;
                }

                //Effects that trigger “after 1 or more wound tokens are placed” may now be used.
                cardrepresentation.controllingplayerID = 255;

            }
        }

};
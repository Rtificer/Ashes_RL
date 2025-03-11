#include <cstdint>
#include <array>
#include <variant>
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

struct GameState {
    public:
        uint8_t CurrentTurn;
        uint8_t CurrentPhase;

        uint8_t FirstPlayerIndex;
        uint8_t ActivePlayerIndex;
        uint8_t CurrentAction;

        std::array<Player, 2> Players;

        uint8_t LimboCardCount;
        std::array<CardRepresentation, 60> Limbo;
};

class Game {
    public:
        GameState gamestate;

        GameState CaptureState() {
            return gamestate;
        }

        CardBase* GetCardFromLocation(CardLocation location) {
            if (location.Zone < 7) {
                switch(location.Zone) {
                    case 5:
                        if (location.CardIndex < 8) {
                            return CardRegistry::getInstance().getCard(location.CardIndex);
                        } 
                        return nullptr;
                    case 6:
                        if (location.CardIndex < gamestate.LimboCardCount) {
                            return CardRegistry::getInstance().getCard(gamestate.Limbo[location.CardIndex].cardID);
                        }
                        return nullptr;
                }
                if (location.PlayerIndex < 3) {
                    auto cardzone = gamestate.Players[location.PlayerIndex].GetLocation(location.Zone);
                    //Lambda function to determine the type of the variant
                    return std::visit([&location](auto &&arg) -> CardBase* {
                        using T = std::decay_t<decltype(arg)>;
                        if constexpr (std::is_same_v<T, std::array<uint8_t, 30>>) {
                            if (location.CardIndex < 30) {
                                return CardRegistry::getInstance().getCard(arg[location.CardIndex]);
                            }
                        } else if constexpr (std::is_same_v<T, std::array<uint8_t, 64>>) {
                            if (location.CardIndex < 64) {
                                return CardRegistry::getInstance().getCard(arg[location.CardIndex]);
                            }
                        } else if constexpr (std::is_same_v<T, std::array<CardRepresentation, 5>>) {
                            if (location.CardIndex < 5) {
                                return CardRegistry::getInstance().getCard(arg[location.CardIndex].cardID);
                            }
                        } else if constexpr (std::is_same_v<T, std::array<CardRepresentation, 11>>) {
                            if (location.CardIndex < 11) {
                                return CardRegistry::getInstance().getCard(arg[location.CardIndex].cardID);
                            }
                        }
                        return nullptr;
                    }, cardzone);
                }   
            }
            return nullptr;
        }
        void AdvanceTurn() {

            if (gamestate.FirstPlayerIndex == 2) {
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
};
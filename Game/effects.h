#include <cstdint>
#include <array>
#include <memory>
#include <iostream>
#include "game.h"

class EffectStep {
    public:
        template<uint8_t PlayerCount>
        constexpr bool resolve(Game<PlayerCount> game) {
            return false;
            //Resolve Effect Step
        }
};

class EffectBase { 
    public: 
        virtual ~EffectBase() = default;
};

template <uint8_t StepQuantity, uint8_t TotalCostSymbols>
class Effect : public EffectBase {
    public:
        const bool IsAbility;
        const std::array<uint8_t, TotalCostSymbols> Cost;
        const std::array<EffectStep, StepQuantity> Steps;  

        constexpr Effect(
            bool isability = false, 
            std::array<uint8_t, TotalCostSymbols> cost,
            std::array<EffectStep, StepQuantity> steps
        ) : 
        IsAbility(isability), Cost(cost), Steps(steps) {}

        template<uint8_t PlayerCount>
        constexpr bool Resolve(Game<PlayerCount> game) {
            for (EffectStep& step : Steps) {
                step.resolve(game);
            }
            return false;
        }
};



class SearchDiscardForAlly : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            return true;
            //Search Discard for ally.
        }
};

class RemoveAllWoundTokensFromTargetUnit : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            return true;
            //Search Remove all wound tokens from target unit.
        }
};

class RemoveTwoWoundTokensFromTargetPhoenixborn : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            return true;
            //Search Remove two wound tokens from target phoenixborn.
        }
};

class ChangeTwoDiceInYourActivePoolToASideOfYourChoice : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            std::cout << "Select two dice from you active die pool of your choice." << std::endl;
            std::cout << "Your active die pool is as following: ";
            for (uint8_t Die : game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool) {
                if (Die = 0) {
                    break;
                }
                else {
                    std::cout << Die << " ";
                }
            }
            std::cout << std::endl;

            switch(game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].TotalActiveDice ) {
                case 0:
                    return false;
                case 1:
                    std::cout << "Enter desired side for the only die in your active pool (0-2): ";
                    std::cin >> Input;
                    game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool[0] = static_cast<uint8_t>(Input);
                    std::cout << std::endl;
                    return true;
                case 2:
                    std::cout << "Enter desired side for the first of two dice in your active pool (0-2): ";
                    std::cin >> Input;
                    game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool[0] = static_cast<uint8_t>(Input);
                    std::cout << std::endl;
                    std::cout << "Enter desired side for the second of two dice in your active pool (0-2): ";
                    std::cin >> Input;
                    game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool[1] = static_cast<uint8_t>(Input);
                    std::cout << std::endl;
                    return true;
                default:
                    std::array<uint8_t, 2> SelectedDieIndices;

                    std::string Input;
                    std::cout << std::endl;
                    std::cout << "Enter the index of the first die you would like to change: ";
                    std::cin >> Input;
                    SelectedDieIndices[0] = static_cast<uint8_t>(Input);
                    std::cout << std::endl;
                    std::cout << "Enter the index of the second die you would like to change: ";
                    std::cin >> Input;
                    SelectedDieIndices[1] = static_cast<uint8_t>(Input);
                    std::cout << std::endl;

                    std::cout << "Enter desired side for die one (0-2): ";
                    std::cin >> Input;
                    game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool[SelectedDieIndices[0]] = static_cast<uint8_t>(Input);
                    std::cout << "Enter desired side for die two (0-2): ";
                    std::cin >> Input;
                    game.gamestate.Players[game.gamestate.ResolvingEffectsStack[game.gamestate.TotalResolvingEffects - 1].OriginCard.PlayerIndex].ActiveDiePool[SelectedDieIndices[1]] = static_cast<uint8_t>(Input);
                    return true;
            }
        }
};

class PlaceBlue_JaguarOntoYourBattlefield : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            //Do as named
            return true;
        }
};

class PlaceButterfly_MonkOntoYourBattlefield : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> game) {
            //Do as named
            return true;
        }
};
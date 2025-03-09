#ifndef EFFECTS_H
#define EFFECTS_H

#include <cstdint>
#include <array>
#include <memory>
#include "game.h"

class EffectStep {
    public:
        virtual bool resolve() const = 0;
};

template <uint8_t TotalCostSymbols, uint8_t StepQuantity>
class Effect {
    public:
        const bool IsAbility;
        const std::array<uint8_t, TotalCostSymbols> Cost;
        const std::array<EffectStep, StepQuantity> Steps;  

        constexpr Effect(
            bool isability,  
            const std::array<uint8_t, TotalCostSymbols> & cost,
            const std::array<EffectStep, StepQuantity> & steps
        ) : 
        IsAbility(isability), Cost(cost), Steps(steps) {}

        virtual uint8_t Resolve() const = 0;
};



class SearchDiscardForAlly : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            return true;
            //Search Discard for ally.
        }
};

class RemoveAllWoundTokensFromTargetUnit : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            return true;
            //Search Remove all wound tokens from target unit.
        }
};

class RemoveTwoWoundTokensFromTargetPhoenixborn : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            return true;
            //Search Remove two wound tokens from target phoenixborn.
        }
};

class ChangeTwoDiceInYourActivePoolToASideOfYourChoice : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            
            return true;
        }
};

class PlaceBlue_JaguarOntoYourBattlefield : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            //Do as named
            return true;
        }
};

class PlaceButterfly_MonkOntoYourBattlefield : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            //Do as named
            return true;
        }
};

class DealOneDamageToYourPhoenixborn : public EffectStep {
    public:
        template<uint8_t PlayerCount>
        bool resolve(Game<PlayerCount> & game) {
            //Do as named
            return true;
        }
};

#endif
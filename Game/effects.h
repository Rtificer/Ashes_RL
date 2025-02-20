#include <cstdint>
#include <array>
#include <memory>
#include "gamestate.h"

class EffectStep {
    public:
        virtual ~EffectStep() = default;
        bool resolve() {
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
        isAbility(is_ability), Cost(cost), Steps(steps) {}

        bool Resolve() {
            for (EffectStep& step : Steps) {
                step.resolve();
            }
        }
};



class SearchDiscardForAlly : public EffectStep {
    public:
        bool resolve() {
            return true;
            //Search Discard for ally.
        }
};

class RemoveAllWoundTokensFromTargetUnit : public EffectStep {
    public:
        bool resolve() {
            return true;
            //Search Remove all wound tokens from target unit.
        }
};

class RemoveTwoWoundTokensFromTargetPhoenixborn : public EffectStep {
    public:
        bool resolve() {
            return true;
            //Search Remove two wound tokens from target phoenixborn.
        }
};

class ChangeTwoDiceInYourActivePoolToASideOfYourChoice : public EffectStep {
    public:
        bool resolve() {
            return true;
        }
};

class PlaceBlue_JaguarOntoYourBattlefield : public EffectStep {
    public:
        bool resolve() {
            //Do as named
            return true;
        }
};

class PlaceButterfly_MonkOntoYourBattlefield : public EffectStep {
    public:
        bool resolve() {
            //Do as named
            return true;
        }
};
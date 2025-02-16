#include <cstdint>
#include <array>
#include <memory>

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

        constexpr Effect(std::array<EffectStep, StepQuantity> steps, bool isability = false)
            : Steps(steps), isAbility(is_ability) {}

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
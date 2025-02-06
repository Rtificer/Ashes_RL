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
        virtual ~Effect() = default;
        bool isAbility;

        std::array<uint8_t, TotalCostSymbols> Cost;

        std::array<std::unique_ptr<EffectStep>, StepQuantity> Steps = {};
        bool Resolve() {

            //TODO: resolve costs
            for (std::unique_ptr<EffectStep> EffectStep : Steps) {
                EffectStep->resolve();
            }
        }
};



class SearchDiscardForAlly : public EffectStep {
    public:
        bool resolve() {
            return false;
            //Search Discard for ally.
        }
};
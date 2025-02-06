#include <cstdint>
#include <array>
#include <memory>
#include <vector>
#include "effects.h"

class CardBase {
    public:
        virtual ~CardBase() = default;
};


template <uint8_t EffectQuantity>
class Card : public CardBase {
    public:
        //0 = Discard
        //1 = Battlefield
        //2 = Spellboard
        //3 = Unit
        //4 = Phoenixborn
        uint8_t Placement;
        uint8_t OwnerID;
        bool isFacedown;
        std::array<std::unique_ptr<EffectBase>, EffectQuantity> Effects; 
};




template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class Spell : public Card<EffectQuantity> {
    public:
        std::array<uint8_t, TotalPlayCostSymbols> PlayCost;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class ReadySpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
    public:
        Placement = 2;
        uint8_t exhaustionTokenCount;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class ActionSpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
    public:
        Placement = 0;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class AlterationSpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
    public:
        Placement = 3;
};




template <uint8_t EffectQuantity>
class Unit : public Card<EffectQuantity> {
    public:
        Placement = 1;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class Ally : public Unit<EffectQuantity> {
    public:
         std::array<uint8_t, TotalPlayCostSymbols> PlayCost;
};

template <uint8_t EffectQuantity>
class Conjuration : public Unit<EffectQuantity> {
    public:
        uint8_t conjurationLimit;
};



template <uint8_t EffectQuantity>
class Phoenixborn : public Card<EffectQuantity> {
    public:

        Placement = 4;

        uint8_t StartingLifeValue;
        uint8_t BattleFieldLimit;
        uint8_t SpellBoardLimit;
};
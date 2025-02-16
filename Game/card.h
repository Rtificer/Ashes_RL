#include <cstdint>
#include <array>
#include "effects.h"

class CardBase {
public:
    virtual ~CardBase() = default;
};

template <uint8_t EffectQuantity>
class Card : public CardBase {
public:
    // 0 = Discard, 1 = Battlefield, 2 = Spellboard, 3 = Unit, 4 = Phoenixborn, 5 = Not Assigned Error
    uint8_t Placement;
    std::array<EffectBase, EffectQuantity> Effects;

    constexpr Card(std::array<EffectBase, EffectQuantity> effects, uint8_t placement = 5)
        : Effects(effects), Placement(placement) {}
};



template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class Spell : public Card<EffectQuantity> {
public:
    std::array<uint8_t, TotalPlayCostSymbols> PlayCost;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class ReadySpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
public:
    constexpr ReadySpell() : Card<EffectQuantity> {
        //Placement
        2
    }
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class ActionSpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
public:
    constexpr ActionSpell() : Card<EffectQuantity> {
        //Placement
        0
    }
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class AlterationSpell : public Spell<EffectQuantity, TotalPlayCostSymbols> {
public:
    constexpr AlterationSpell() : Card<EffectQuantity> {
        //Placement
        3
    }
};



template <uint8_t EffectQuantity>
class Unit : public Card<EffectQuantity> {
public:
    constexpr Unit() : Card<EffectQuantity>{ 
        //Placement
        1
    }

    uint8_t startingAttackValue;
    uint8_t startingLifeValue;
    uint8_t startingRecoverValue;
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
    constexpr Phoenixborn() : Card<EffectQuantity> {
        4; 
    }

    uint8_t StartingLifeValue;
    uint8_t BattleFieldLimit;
    uint8_t SpellBoardLimit;
};

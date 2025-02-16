#include <cstdint>
#include <array>
#include "effects.h"

class CardBase {
public:
    virtual ~CardBase() = default;
};

template <uint8_t EffectQuantity, uint8_t TotalPlayCostSymbols>
class Card : public CardBase {
public:
    //0 = Ready Spell, 1 = Action Spell, 2 = Alteration Spell, 3 = Conjured Alteration Spell, 4 = Ally, 5 = Conjuration(unit), 255 = Not Assigned Error
    const uint8_t Type;
    //0 = Discard, 1 = Battlefield, 2 = Spellboard, 3 = Unit, 4 = Phoenixborn, 255 = Not Assigned Error
    const uint8_t Placement;
    const std::array<EffectBase, EffectQuantity> Effects;

    const std::array<uint8_t, TotalPlayCostSymbols> PlayCost;

    // --- Unit Specific ---
    const uint8_t StartingAttackValue;
    const uint8_t StartingLifeValue;
    const uint8_t StartingRecoverValue;

    // --- Conjuration Specific ---
    const uint8_t ConjurationLimit;

    // --- Phoenixborn Specific ---
    const uint8_t BattleFieldLimit;
    const uint8_t SpellBoardLimit;

    constexpr Card(
        //0 = Ready Spell, 1 = Action Spell, 2 = Alteration Spell, 3 = Conjured Alteration Spell, 4 = Ally, 5 = Conjuration(unit), 255 = Not Assigned Error
        uint8_t type = 255,
        //0 = Discard, 1 = Battlefield, 2 = Spellboard, 3 = Unit, 4 = Phoenixborn, 255 = Not Assigned Error
        uint8_t placement = 255,
        std::array<EffectBase, EffectQuantity> effects, 

        std::array<uint8_t, TotalPlayCostSymbols> playcost;

        //254 = Not applicable
        // --- Unit (and sort of Phoenixborn) Specific ---
        uint8_t startingattackvalue = 254;
        uint8_t startinglifevalue = 254;
        uint8_t startingrecovervalue = 254;

        // --- Conjuration Specific ---
        uint8_t conjurationlimit = 254;

        // --- Phoenixborn Specific ---
        uint8_t battlefieldlimit = 254;
        uint8_t spellboardlimit = 254;

    ) : 
    Type(type), Placement(placement), Effects(effects),
    PlayCost(playcost)
    StartingAttackValue(startingattackvalue), 
    StartingLifeValue(startinglifevalue), 
    StartingRecoverValue(startingrecovervalue),
    ConjurationLimit(conjurationlimit),
    BattleFieldLimit(battlefieldlimit),
    SpellBoardLimit(spellboardlimit)
    {}
};
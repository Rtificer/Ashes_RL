#include <cstdint>
#include <array>
#include "effects.h"

class CardBase {
public:
    virtual ~CardBase() = default;

    virtual uint8_t getType() const = 0;
    virtual uint8_t getPlacement() const = 0;
    virtual uint8_t getPlayCost() const = 0;
    virtual uint8_t getEffects() const = 0;

    virtual uint8_t getStartingAttackValue() const = 0;
    virtual uint8_t getStartingLifeValue() const = 0;
    virtual uint8_t getStartingRecoverValue() const = 0;

    virtual uint8_t getConjurationLimit() const = 0;

    virtual uint8_t getBattleFieldLimit() const = 0;
    virtual uint8_t getSpellBoardLimit() const = 0;
};

template <uint8_t TotalPlayCostSymbols, uint8_t EffectQuantity>
class Card : public CardBase {
public:
    const uint16_t CardID;
    //0 = Ready Spell, 1 = Action Spell, 2 = Alteration Spell, 3 = Conjured Alteration Spell, 4 = Ally, 5 = Conjuration(unit), 6 = Phoenixborn, 255 = Not Assigned Error
    const uint8_t Type;
    //0 = Discard, 1 = Battlefield, 2 = Spellboard, 3 = Unit, 4 = Phoenixborn, 255 = Not Assigned Error
    const uint8_t Placement;
    const std::array<uint8_t, TotalPlayCostSymbols> PlayCost;
    const std::array<EffectBase, EffectQuantity> Effects;

    // --- Unit Specific ---
    const uint8_t StartingAttackValue;
    const uint8_t StartingLifeValue;
    const uint8_t StartingRecoverValue;

    // --- Conjuration Specific ---
    const uint8_t ConjurationLimit;

    // --- Phoenixborn Specific ---
    const uint8_t BattleFieldLimit;
    const uint8_t SpellBoardLimit;

    static Card& getInstance() {
        static Card instance;
        return instance;
    }

    uint8_t getType() const override {
        return Type;
    }
    uint8_t getPlacement() const override {
        return Placement;
    }
    uint8_t getPlayCost() const override {
        return PlayCost;
    }
    uint8_t getEffects() const override {
        return Effects;
    }

    uint8_t getStartingAttackValue() const override {
        return StartingAttackValue;
    }
    uint8_t getStartingLifeValue() const override {
        return StartingLifeValue;
    }
    uint8_t getStartingRecoverValue() const override {
        return StartingRecoverValue;
    }

    uint8_t getConjurationLimit() const override {
        return ConjurationLimit;
    }

    uint8_t getBattleFieldLimit() const override {
        return BattleFieldLimit;
    }
    uint8_t getSpellBoardLimit() const override {
        return SpellBoardLimit;
    }

    constexpr Card(
        uint16_t cardid = 65535,

        uint8_t type = 255,
        uint8_t placement = 255,
        std::array<uint8_t, TotalPlayCostSymbols> playcost = {},
        std::array<EffectBase, EffectQuantity> effects = {}, 

        // Default to 254 to indicate not applicable
        uint8_t startingattackvalue = 254,
        uint8_t startinglifevalue = 254,
        uint8_t startingrecovervalue = 254,

        uint8_t conjurationlimit = 254,
        uint8_t battlefieldlimit = 254,
        uint8_t spellboardlimit = 254
    ) : 
    CardID(cardid), Type(type), Placement(placement), 
    PlayCost(playcost), Effects(effects),
    StartingAttackValue(startingattackvalue), 
    StartingLifeValue(startinglifevalue), 
    StartingRecoverValue(startingrecovervalue),
    ConjurationLimit(conjurationlimit),
    BattleFieldLimit(battlefieldlimit),
    SpellBoardLimit(spellboardlimit)
    {}

    // Delete copy constructor and assignment operator
    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;
};
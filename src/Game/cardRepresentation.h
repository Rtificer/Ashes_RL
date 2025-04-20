#ifndef CARD_REPRESENTATION_H
#define CARD_REPRESENTATION_H

#include <cstdint>
#include <array>
#include <memory>

struct cardRepresentation {
    public:
        uint16_t cardID;

        // --- General ---
            //bits 1-3 = cardType (0 = Ready Spell, 1 = Action Spell, 2 = Alteration Spell, 3 = Conjured Alteration Spell, 4 = Ally, 5 = Conjuration(Unit), 6 = Phoenixborn, 7 = Dice Power Card)
        // --- Non-Dice Power Specific ---
            //bit 4 = ownerID (0, 1)
            //bits 5-6 = controllingPlayerID (0, 1, 2 = none)
            //Location
                //bit 7 = posessingPlayerID (0, 1)
                //bits 6-8 = zone (0 = Hand, 1 = Discard Pile, 3 = Spellboard, 4 = Battlefield, 5 = Limbo)
        // --- Ready Spell Specific ---
            //bits 9-11 = focusCount (0-7)
        // --- Unit & Phoenixborn Specific ---
            //bits 9-14 = exhaustionTokenCount (0-63)
            //bits 15-20 = statusTokenCount (0-63)
            //bits 21-26 = woundTokenCount (0-63)
            //bit 27 = sign of currentLifeValue (0 = positive, 1 = negative)
            //bits 28-33 = currentLifeValue (0-63)
            //bit 34 = isGuardAvailable? (0 = false, 1 = true)
        // --- Unit Specific ---
            //bit 35 = sign of currentAttackValue (0 = positive, 1 = negative)
            //bits 36-41 = currentAttackValue (0-63)
            //bit 42 = sign of currentRecoverValue (0 = positive, 1 = negative)
            //bits 43-48 = currentRecoverValue (0-63)

        uint32_t additionalCardData1;
        uint16_t additionalCardData2;

        std::array<std::shared_ptr<cardRepresentation>, 16> attachedCardRepresentations;
};

#endif
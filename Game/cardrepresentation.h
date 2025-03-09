#include <cstdint>
#include <array>

class CardRepresentation {
public:
    uint16_t cardID;

    //255 = no controlling player
    uint8_t controllingPlayerID;

    uint8_t exhaustionTokenCount;
    uint8_t statusTokenCount;
    uint8_t woundTokenCount;  // Used for Battlefield and Phoenixborn

    uint8_t currentAttackValue;  // Used for Battlefield
    uint8_t currentLifeValue;    // Used for Battlefield and Phoenixborn
    uint8_t currentRecoverValue; // Used for Battlefield

    uint8_t focusCount; // Used for Spellboard

    bool isGuardAvailable;

    std::array<uint16_t, 60> attachedCardIDs; // Used for Battlefield

    //Miscellaneous for the rest of the cards ever.
    bool canBlock;
    bool canGuard;
};

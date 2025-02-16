#include <cstdint>
#include <stack>
#include <array>

#include "player.h"

const enum OriginEffectZone : uint8_t {
    BATTLEFIELD,
    SPELLBOARD,
    HAND,
    DISCARD_PILE,
    CONJURATION_PILE,
    PHOENIXBORN
};

struct ResolvingEffectStep {


    //TODO: Revise to reference the effectstep class it is, and the location of the origin card. 
        //Perhaps keep a map of the location of every card by ID, and then generate unique ID's for every instance of every card, instead of every card itself
    uint8_t DependentEffectStepIndex; //Optional, = 255 if not dependent, specifies the index of the effectstep in the stack triggering this effectstep.

    uint8_t OriginDicePowerPlayerID;
    //0 = Not from a dice power. If > 0 and the effectstep is one pertaining to a dice on a card, then OriginPlayerID, OriginZone, and OriginIndex, will specify the card the dice is on.
    uint8_t DicePowerIndex;

    uint8_t OriginPlayerID;
    OriginEffectZone OriginZone;
    uint8_t OriginIndex;
    uint8_t EffectIndex;
    uint8_t EffectStepIndex;

};

template<uint8_t PlayerCount>
struct GameState {
    public:
        uint8_t CurrentTurn;
        uint8_t CurrentPhase;
        
        uint8_t ActivePlayerID;
        uint8_t CurrentAction;

        std::array<Player, PlayerCount> Players;
};
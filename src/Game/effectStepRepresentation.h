#ifndef EFFECT_STEP_REPRESENTATION_H
#define EFFECT_STEP_REPRESENTATION_H

#include <cstdint>
#include <memory>
#include <array>

#include "cardRepresentation.h"

struct effectStepRepresentation {
    //bits 1-2 = durationType (0 = Immediate, 1 = End of Turn, 2 = End of Round)
    //bit 3-8 = duration (0-63 turns/rounds)
    uint8_t duration;
    
    std::shared_ptr<cardRepresentation> originCard;

    std::array<std::shared_ptr<cardRepresentation>, 32> targetCards;
};

#endif
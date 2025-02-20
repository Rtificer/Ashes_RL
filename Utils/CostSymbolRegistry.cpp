#include <cstdint>
#include <unordered_map>
#include <string>

const std::unordered_map<std::string, uint8_t> CostStringToInt {

    {"Action", 0}, {"SideAction", 1}, {"ActionOrSideAction", 2},

    {"Exhaustion", 3},
    {"Discard", 4},

    {"Basic", 5}, 
    {"NaturalClass", 6}, {"NaturalPower", 7}, 
    {"CharmClass", 8}, {"CharmPower", 9}, 
    {"CeremonialClass", 10}, {"CeremonialPower", 11},
    {"IllusionClass", 12}, {"IllusionPower", 13},
    {"SympathyClass", 14}, {"SympathyPower", 15},
    {"DivineClass", 16}, {"DivinePower", 17},
    {"TimeClass", 18}, {"TimePower", 19},

    {"NaturalOrCharmClass", 20}, {"CharmOrNaturalClass", 20},
    {"NaturalOrCeremonialClass", 21}, {"CeremonialOrNaturalClass", 21},
    {"NaturalOrIllusionClass", 22}, {"IllusionOrNaturalClass", 22},
    {"NaturalOrSympathyClass", 23}, {"SympathyOrNaturalClass", 23},
    {"NaturalOrDivineClass", 24}, {"DivineOrNaturalClass", 24},
    {"NaturalOrTimeClass", 25}, {"TimeOrNaturalClass", 25},

    {"CharmOrCeremonialClass", 26}, {"CeremonialOrCharmClass", 26},
    {"CharmOrIllusionClass", 27}, {"IllusionOrCharmClass", 27},
    {"CharmOrSympathyClass", 28}, {"SympathyOrCharmClass", 28},
    {"CharmOrDivineClass", 29}, {"DivineOrCharmClass", 29},
    {"CharmOrTimeClass", 30}, {"TimeOrCharmClass", 30},

    {"CeremonialOrIllusionClass", 31}, {"IllusionOrCeremonialClass", 31},
    {"CeremonialOrSympathyClass", 32}, {"SympathyOrCeremonialClass", 32},
    {"CeremonialOrDivineClass", 33}, {"DivineOrCeremonialClass", 33},
    {"CeremonialOrTimeClass", 34}, {"TimeOrCeremonialClass", 34},

    {"IllusionOrSympathyClass", 35}, {"SympathyOrIllusionClass", 35},
    {"IllusionOrDivineClass", 36}, {"DivineOrIllusionClass", 36},
    {"IllusionOrTimeClass", 37}, {"TimeOrIllusionClass", 37},

    {"SympathyOrDivineClass", 38}, {"DivineOrSympathyClass", 38},
    {"SympathyOrTimeClass", 39}, {"TimeOrSympathyClass", 39},

    {"DivineOrTimeClass", 40}, {"TimeOrDivineClass", 40},

    {"NaturalOrCharmPower", 41}, {"CharmOrNaturalPower", 41},
    {"NaturalOrCeremonialPower", 42}, {"CeremonialOrNaturalPower", 42},
    {"NaturalOrIllusionPower", 43}, {"IllusionOrNaturalPower", 43},
    {"NaturalOrSympathyPower", 44}, {"SympathyOrNaturalPower", 44},
    {"NaturalOrDivinePower", 45}, {"DivineOrNaturalPower", 45},
    {"NaturalOrTimePower", 46}, {"TimeOrNaturalPower", 46},

    {"CharmOrCeremonialPower", 47}, {"CeremonialOrCharmPower", 47},
    {"CharmOrIllusionPower", 48}, {"IllusionOrCharmPower", 48},
    {"CharmOrSympathyPower", 49}, {"SympathyOrCharmPower", 49},
    {"CharmOrDivinePower", 50}, {"DivineOrCharmPower", 50},
    {"CharmOrTimePower", 51}, {"TimeOrCharmPower", 51},

    {"CeremonialOrIllusionPower", 52}, {"IllusionOrCeremonialPower", 52},
    {"CeremonialOrSympathyPower", 53}, {"SympathyOrCeremonialPower", 53},
    {"CeremonialOrDivinePower", 54}, {"DivineOrCeremonialPower", 54},
    {"CeremonialOrTimePower", 55}, {"TimeOrCeremonialPower", 55},

    {"IllusionOrSympathyPower", 56}, {"SympathyOrIllusionPower", 56},
    {"IllusionOrDivinePower", 57}, {"DivineOrIllusionPower", 57},
    {"IllusionOrTimePower", 58}, {"TimeOrIllusionPower", 58},

    {"SympathyOrDivinePower", 59}, {"DivineOrSympathyPower", 59},
    {"SympathyOrTimePower", 60}, {"TimeOrSympathyPower", 60},

    {"DivineOrTimePower", 61}, {"TimeOrDivinePower", 61}

};

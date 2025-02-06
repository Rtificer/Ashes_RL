#include <cstdint>
#include <unordered_map>
#include <string>

const std::unordered_map<std::string, uint8_t> CostStringToInt {

    {"Action", 0}, {"SideAction", 1}, {"ActionOrSideAction", 2},

    {"Discard", 3},

    {"Basic", 4}, 
    {"NaturalClass", 5}, {"NaturalPower", 6}, 
    {"CharmClass", 7}, {"CharmPower", 8}, 
    {"CeremonialClass", 9}, {"CeremonialPower", 10},
    {"IllusionClass", 11}, {"IllusionPower", 12},
    {"SympathyClass", 13}, {"SympathyPower", 14},
    {"DivineClass", 15}, {"DivinePower", 16},
    {"TimeClass", 17}, {"TimePower", 18},

    {"NaturalOrCharmClass", 19}, {"CharmOrNaturalClass", 19},
    {"NaturalOrCeremonialClass", 20}, {"CeremonialOrNaturalClass", 20},
    {"NaturalOrIllusionClass", 21}, {"IllusionOrNaturalClass", 21},
    {"NaturalOrSympathyClass", 22}, {"SympathyOrNaturalClass", 22},
    {"NaturalOrDivineClass", 23}, {"DivineOrNaturalClass", 23},
    {"NaturalOrTimeClass", 24}, {"TimeOrNaturalClass", 24},

    {"CharmOrCeremonialClass", 25}, {"CeremonialOrCharmClass", 25},
    {"CharmOrIllusionClass", 26}, {"IllusionOrCharmClass", 26},
    {"CharmOrSympathyClass", 27}, {"SympathyOrCharmClass", 27},
    {"CharmOrDivineClass", 28}, {"DivineOrCharmClass", 28},
    {"CharmOrTimeClass", 29}, {"TimeOrCharmClass", 29},

    {"CeremonialOrIllusionClass", 30}, {"IllusionOrCeremonialClass", 30},
    {"CeremonialOrSympathyClass", 31}, {"SympathyOrCeremonialClass", 31},
    {"CeremonialOrDivineClass", 32}, {"DivineOrCeremonialClass", 32},
    {"CeremonialOrTimeClass", 33}, {"TimeOrCeremonialClass", 33},

    {"IllusionOrSympathyClass", 34}, {"SympathyOrIllusionClass", 34},
    {"IllusionOrDivineClass", 35}, {"DivineOrIllusionClass", 35},
    {"IllusionOrTimeClass", 36}, {"TimeOrIllusionClass", 36},

    {"SympathyOrDivineClass", 37}, {"DivineOrSympathyClass", 37},
    {"SympathyOrTimeClass", 38}, {"TimeOrSympathyClass", 38},

    {"DivineOrTimeClass", 39}, {"TimeOrDivineClass", 39},

    {"NaturalOrCharmPower", 40}, {"CharmOrNaturalPower", 40},
    {"NaturalOrCeremonialPower", 41}, {"CeremonialOrNaturalPower", 41},
    {"NaturalOrIllusionPower", 42}, {"IllusionOrNaturalPower", 42},
    {"NaturalOrSympathyPower", 43}, {"SympathyOrNaturalPower", 43},
    {"NaturalOrDivinePower", 44}, {"DivineOrNaturalPower", 44},
    {"NaturalOrTimePower", 45}, {"TimeOrNaturalPower", 45},

    {"CharmOrCeremonialPower", 46}, {"CeremonialOrCharmPower", 46},
    {"CharmOrIllusionPower", 47}, {"IllusionOrCharmPower", 47},
    {"CharmOrSympathyPower", 48}, {"SympathyOrCharmPower", 48},
    {"CharmOrDivinePower", 49}, {"DivineOrCharmPower", 49},
    {"CharmOrTimePower", 50}, {"TimeOrCharmPower", 50},

    {"CeremonialOrIllusionPower", 51}, {"IllusionOrCeremonialPower", 51},
    {"CeremonialOrSympathyPower", 52}, {"SympathyOrCeremonialPower", 52},
    {"CeremonialOrDivinePower", 53}, {"DivineOrCeremonialPower", 53},
    {"CeremonialOrTimePower", 54}, {"TimeOrCeremonialPower", 54},

    {"IllusionOrSympathyPower", 55}, {"SympathyOrIllusionPower", 55},
    {"IllusionOrDivinePower", 56}, {"DivineOrIllusionPower", 56},
    {"IllusionOrTimePower", 57}, {"TimeOrIllusionPower", 57},

    {"SympathyOrDivinePower", 58}, {"DivineOrSympathyPower", 58},
    {"SympathyOrTimePower", 59}, {"TimeOrSympathyPower", 59},

    {"DivineOrTimePower", 60}, {"TimeOrDivinePower", 60}

};

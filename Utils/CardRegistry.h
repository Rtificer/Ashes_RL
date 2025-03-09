#include "../Assets/Cards/Bound_Soul.h"
#include "../Assets/Cards/Shifting_Mist.h"
#include "../Assets/Cards/Heal.h"
#include "../Assets/Cards/Summon_Blue_Jaguar.h"
#include "../Assets/Cards/Blue_Jaguar.h"
#include "../Assets/Cards/Summon_Butterfly_Monk.h"

#include <array>
#include <memory>
#include <cassert>

//Singleton Pattern
class CardRegistry {
public:
    static CardRegistry& getInstance() {
        static CardRegistry instance;
        return instance;
    }

    template <typename CardType>
    void registerCard(uint16_t cardID) {
        CardBase* cardBasePtr = reinterpret_cast<CardBase*>(&CardType::getInstance());
        //Dynamic cast is safe but reinterpret is not, so we do a dynamic cast to check if the cast is valid. Disable in final build.
        assert(dynamic_cast<CardBase*>(cardBasePtr) != nullptr && "Invalid cast to CardBase*");
        cardMap[cardID] = cardBasePtr;
    }

    CardBase* getCard(uint16_t cardID) const {
        if (cardID < 6) {
            return cardMap.at(cardID);
        } else {
            return nullptr;
        }
    }

private:
    CardRegistry() {
        registerCard<Bound_Soul>(0);
        registerCard<Shifting_Mist>(2);
        registerCard<Heal>(1);
        registerCard<Summon_Blue_Jaguar>(3);
        registerCard<Blue_Jaguar>(5);
        registerCard<Summon_Butterfly_Monk>(4);

    }
    std::array<CardBase*, 6> cardMap;
};

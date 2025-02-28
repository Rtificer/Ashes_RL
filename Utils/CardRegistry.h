#include "../Assets/Cards/Bound_Soul.h"
#include "../Assets/Cards/Heal.h"
#include "../Assets/Cards/Shifting_Mist.h"
#include "../Assets/Cards/Summon_Blue_Jaguar.h"
#include "../Assets/Cards/Summon_Butterfly_Monk.h"

#include "../Game/card.h"
#include <array>
#include <memory>


//Singleton Pattern
class CardRegistry {
public:
    static CardRegistry& Instance() {
        static CardRegistry instance;
        return instance;
    }
        
    std::array<std::unique_ptr<CardBase>, 5>& GetCardArray() {
        return cardIDToCard;
    }

    //Delete copy and move constructors
    CardRegistry(const CardRegistry&) = delete;
    CardRegistry& operator=(const CardRegistry&) = delete;
    CardRegistry(CardRegistry&&) = delete;
    CardRegistry& operator=(CardRegistry&&) = delete;

private:
    CardRegistry() {
        cardIDToCard[0] = std::make_unique<Bound_Soul>();
        cardIDToCard[1] = std::make_unique<Heal>();
        cardIDToCard[2] = std::make_unique<Shifting_Mist>();
        cardIDToCard[3] = std::make_unique<Summon_Blue_Jaguar>();
        cardIDToCard[4] = std::make_unique<Summon_Butterfly_Monk>();

    }
    
    std::array<std::unique_ptr<CardBase>, 5> cardIDToCard;
};

//Get the array by using auto& cardArray = CardRegistry::Instance().GetCardArray();

#include "../Assets/Cards/Bound_Soul.h"

#include <array>
#include <memory>

//Singleton Pattern
class CardRegistry {
public:
    static CardRegistry& Instance() {
        static CardRegistry instance;
        return instance;
    }
        
    std::array<std::unique_ptr<CardBase>, 1>& GetCardArray() {
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
    }
    
    std::array<std::unique_ptr<CardBase>, 1> cardIDToCard;
};

//Get the array by using auto& cardArray = CardRegistry::Instance().GetCardArray();

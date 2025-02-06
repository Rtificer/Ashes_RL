import os

def GenerateCardIncludeHeader():
    with open("Utils/CardRegistry.h", "w") as CardRegistry:
        path = os.path.join(os.getcwd(), "Assets", "Cards")
        CardFileList = [f[:-2] for f in os.listdir(path) if f.endswith(".h")]

        for card in CardFileList:
            CardRegistry.write(f"#include \"../Assets/Cards/{card}.h\"\n")

#Double Curly Brackets = Singular Curly Bracket
        CardRegistry.writelines(
f"""
#include <array>
#include <memory>

//Singleton Pattern
class CardRegistry {{
public:
    static CardRegistry& Instance() {{
        static CardRegistry instance;
        return instance;
    }}
        
    std::array<std::unique_ptr<CardBase>, {len(CardFileList)}>& GetCardArray() {{
        return cardIDToCard;
    }}

    //Delete copy and move constructors
    CardRegistry(const CardRegistry&) = delete;
    CardRegistry& operator=(const CardRegistry&) = delete;
    CardRegistry(CardRegistry&&) = delete;
    CardRegistry& operator=(CardRegistry&&) = delete;

private:
    CardRegistry() {{
"""
        )

        for index, card in enumerate(CardFileList):
            CardRegistry.write(f"        cardIDToCard[{index}] = std::make_unique<{card}>();")

        CardRegistry.writelines(
f"""
    }}
    
    std::array<std::unique_ptr<CardBase>, {len(CardFileList)}> cardIDToCard;
}};

//Get the array by using auto& cardArray = CardRegistry::Instance().GetCardArray();
"""
        )
        
GenerateCardIncludeHeader()
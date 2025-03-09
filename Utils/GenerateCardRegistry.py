import os

def GenerateCardRegistry():
    card_registry_path = os.path.join(os.getcwd(), "Utils", "CardRegistry.h")
    cards_path = os.path.join(os.getcwd(), "Assets", "Cards")
    card_files = [f for f in os.listdir(cards_path) if f.endswith(".h")]

    card_classes = []
    for card_file in card_files:
        with open(os.path.join(cards_path, card_file), 'r') as file:
            card_class = None
            card_id = None
            for line in file:
                if line.startswith("const class"):
                    card_class = line.split()[2]
                if "CardID:" in line:
                    card_id = int(line.split("/*CardID:*/")[1].split(",")[0].strip())
                if card_class and card_id is not None:
                    card_classes.append((card_class, card_id))
                    break

    max_card_id = max(card_id for _, card_id in card_classes)
    card_array_size = max_card_id + 1

    with open(card_registry_path, 'w') as CardRegistry:
        # Write includes
        for card_file in card_files:
            card_name = card_file[:-2]
            CardRegistry.write(f'#include "../Assets/Cards/{card_name}.h"\n')

        # Write CardRegistry class
        CardRegistry.writelines(
f"""
#include <array>
#include <memory>
#include <cassert>
#include "../Game/card.h"

//Singleton Pattern
class CardRegistry {{
public:
    static CardRegistry& getInstance() {{
        static CardRegistry instance;
        return instance;
    }}

    template <typename CardType>
    void registerCard(uint16_t cardID) {{
        CardBase* cardBasePtr = reinterpret_cast<CardBase*>(&CardType::getInstance());
        //Dynamic cast is safe but reinterpret is not, so we do a dynamic cast to check if the cast is valid. Disable in final build.
        assert(dynamic_cast<CardBase*>(cardBasePtr) != nullptr && "Invalid cast to CardBase*");
        cardMap[cardID] = cardBasePtr;
    }}

    CardBase* getCard(uint16_t cardID) const {{
        if (cardID < {card_array_size}) {{
            return cardMap.at(cardID);
        }} else {{
            return nullptr;
        }}
    }}

private:
    CardRegistry() {{
"""
        )

        for card_class, card_id in card_classes:
            CardRegistry.write(f"        registerCard<{card_class}>({card_id});\n")
        CardRegistry.writelines(
f"""
    }}
    std::array<CardBase*, {card_array_size}> cardMap;
}};

//Get the card by using CardBase* card = CardRegistry::getInstance().getCard(cardID);
"""
        )

if __name__ == "__main__":
    GenerateCardRegistry()
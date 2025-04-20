#include <iostream>
#include <string>

#include "gameState.h"
#include "../Utils/deckImporter.h"

class Game {
    public:
        Game() {
            std::string player1DeckLink;
            std::cout << "Input Player 1 Deck Link: ";
            std::cin >> player1DeckLink;

            std::string player2DeckLink;
            std::cout << "Input Player 2 Deck Link: ";
            std::cin >> player2DeckLink;

            nlohmann::json deck1Data;
            nlohmann::json deck2Data;
        
        
            if (!makeDeckGetRequest(player1DeckLink, deck1Data)) {
                std::cerr << "Error importing deck 1" << std::endl;
                return config;
            }
            if (!makeDeckGetRequest(player2DeckLink, deck2Data)) {
                std::cerr << "Error importing deck 2" << std::endl;
                return config;
            }
            
        }
};
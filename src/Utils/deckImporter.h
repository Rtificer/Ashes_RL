#ifndef DECK_IMPORTER_H
#define DECK_IMPORTER_H

#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <string>
#include <iostream>

#include "../Game/gameState.h"



bool makeDeckGetRequest(std::string deckLink, nlohmann::json& deckData) {
    std::string deckID = deckLink.substr(46, 36); //Extract the UUID

    // Make the HTTP GET request
    auto response = cpr::Get(cpr::Url{"https://api.ashes.live/v2/decks/shared"},
        cpr::Parameters {
            {"direct_share_uuid", deckID}
        }
    );

    if (response.status_code != 200) {
        std::cerr << "Error Importing Deck With ID: " << deckID << " Error Code: " << response.status_code << std::endl;
        return false;
    }

    deckData = nlohmann::json::parse(response.text);
    return true;
}


uint8_t findTotalCards(nlohmann::json& deckData) {
    uint8_t totalCards;

    for (auto card : deckData["cards"]) {
        totalCards += card["count"];
    }

    for(auto card : deckData["conjurations"]) {
        totalCards += card["count"];
    }

    return totalCards;
}


#endif
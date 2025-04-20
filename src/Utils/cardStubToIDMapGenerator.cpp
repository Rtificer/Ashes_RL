#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <filesystem>
#include <cstdint>

namespace fs = std::filesystem;

int main() {
    uint16_t totalCards = 0;
    uint16_t offset = 0;
    std::string arrayContents;

    while (true) {
        // Make the HTTP GET request
        auto response = cpr::Get(cpr::Url{"https://api.ashes.live/v2/cards"}, 
            cpr::Parameters {
                {"show_legacy", "false"},
                {"mode", "listing"},
                {"releases", "all"},
                {"sort", "release"},
                {"order", "asc"},
                {"limit", "100"},
                {"offset", std::to_string(offset)}
            }
        );

        std::cout << "Request received!" << std::endl;

        // Parse the JSON response
        auto data = nlohmann::json::parse(response.text);

        // Get the number of cards in the current request
        int totalCardsInRequest = data["results"].size();

        if (totalCardsInRequest == 0) {
            break;
        }

        // Append card stubs to the arrayContents
        for (int i = 0; i < totalCardsInRequest; ++i) {
            arrayContents += "    \"" + data["results"][i]["stub"].get<std::string>() + "\",\n";
        }

        totalCards += totalCardsInRequest;
        offset += 100;
    }

    // Remove the last newline and comma
    if (!arrayContents.empty()) {
        arrayContents.pop_back(); // Remove '\n'
        arrayContents.pop_back(); // Remove ','
    }

    // Define the output file path
    fs::path pathToCardStubToIDMap = fs::path(__FILE__).parent_path() / "cardStubToIDMap.h";

    // Remove the file if it already exists
    if (fs::exists(pathToCardStubToIDMap)) {
        fs::remove(pathToCardStubToIDMap);
    }

    // Write the contents to the header file
    std::ofstream cardStubToIDMap(pathToCardStubToIDMap);
    cardStubToIDMap << "#ifndef CARD_STUB_TO_ID_MAP\n";
    cardStubToIDMap << "#define CARD_STUB_TO_ID_MAP\n\n";
    cardStubToIDMap << "#include <array>\n\n";
    cardStubToIDMap << "//THIS FILE IS AUTO-GENERATED. MAKE MODIFCATIONS TO cardStubToIDMapGenerator.cpp INSTEAD.\n\n";
    cardStubToIDMap << "constexpr std::array<const char*, " << totalCards << "> cardStubToIDMap = {\n";
    cardStubToIDMap << arrayContents << "\n";
    cardStubToIDMap << "};\n\n";
    cardStubToIDMap << "#endif";

    cardStubToIDMap.close();

    std::cout << "Header file generated successfully!" << std::endl;

    return 0;
}
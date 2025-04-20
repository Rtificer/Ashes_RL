cmake_minimum_required(VERSION 3.10)

project(Ashes_RL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force static linking
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)

# Find the required packages
find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

# Create the first executable (cardStubToIDMapGenerator)
add_executable(cardStubToIDMapGenerator src/Utils/cardStubToIDMapGenerator.cpp)

# Link the required libraries for cardStubToIDMapGenerator
target_link_libraries(cardStubToIDMapGenerator PRIVATE cpr::cpr nlohmann_json::nlohmann_json)

# Create the second executable (game)
add_executable(game src/Game/game.cpp)

# No additional libraries are linked to the game executable

# Ensure static runtime on Windows (optional, if targeting Windows)
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()
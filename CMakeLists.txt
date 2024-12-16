cmake_minimum_required(VERSION 3.30)
project(Fisher)

set(CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}/HeaderFiles)

add_executable(Fisher main.cpp
        HeaderFiles/Fish/Fish.h
        HeaderFiles/Player/Player.h
        HeaderFiles/Game.h
        SourceFiles/Fish/Fish.cpp
        SourceFiles/Game.cpp
        SourceFiles/Player/Player.cpp
        HeaderFiles/Fish/FishType.h
        HeaderFiles/Player/PlayerXP.h
        SourceFiles/Player/PlayerXP.cpp
        SourceFiles/Text/TextFormatting.cpp
        HeaderFiles/Text/TextFormatting.h
        SourceFiles/Player/PlayerInventory.cpp
        HeaderFiles/Player/PlayerInventory.h
        SourceFiles/Player/PlayerCoins.cpp
        HeaderFiles/Player/PlayerCoins.h
        SourceFiles/Text/Menu.cpp
        HeaderFiles/Text/Menu.h
        SourceFiles/Text/Option.cpp
        HeaderFiles/Text/Option.h
        SourceFiles/Fishing.cpp
        HeaderFiles/Fishing.h
        SourceFiles/Shop/Shop.cpp
        HeaderFiles/Shop/Shop.h
        SourceFiles/Shop/Rod/Rod.cpp
        HeaderFiles/Shop/Rod/Rod.h
        HeaderFiles/Shop/Rod/RodType.h
)

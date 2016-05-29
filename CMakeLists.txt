cmake_minimum_required(VERSION 3.5)
project(hitmanrl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Action.cpp
    src/Action.h
    src/Actor.cpp
    src/Actor.hpp
    src/Body.cpp
    src/Body.hpp
    src/Console.cpp
    src/Console.hpp
    src/Entity.cpp
    src/Entity.hpp
    src/Game.cpp
    src/Game.hpp
    src/InventoryMenu.cpp
    src/InventoryMenu.hpp
    src/Item.cpp
    src/Item.h
    src/ItemHandler.cpp
    src/ItemHandler.h
    src/LightMap.cpp
    src/LightMap.h
    src/main.cpp
    src/mapEnums.hpp
    src/Menu.cpp
    src/Menu.h
    src/MusicPlayer.cpp
    src/MusicPlayer.hpp
    src/Names.cpp
    src/Names.hpp
    src/Npc.cpp
    src/Npc.hpp
    src/NpcHandler.cpp
    src/NpcHandler.h
    src/Player.cpp
    src/Player.hpp
    src/ResourceHandler.h
    src/ResourceHandler.inl
    src/ResourceIdentifier.hpp
    src/SoundPlayer.cpp
    src/SoundPlayer.hpp
    src/State.cpp
    src/State.hpp
    src/StateStack.cpp
    src/StateStack.hpp
    src/Stats.cpp
    src/Stats.hpp
    src/Textures.hpp
    src/Time.cpp
    src/Time.h
    src/Utils.cpp
    src/Utils.h
    src/VertexMap.cpp
    src/VertexMap.hpp
    src/World.cpp
    src/World.h)

add_executable(hitmanrl ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(hitmanrl ${SFML_LIBRARIES})
endif()
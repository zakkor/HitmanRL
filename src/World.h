//
// Created by Edward on 20-May-15.
//

#ifndef HITMANRL_WORLD_H
#define HITMANRL_WORLD_H


#include "Menu.h"
#include "ItemHandler.h"
#include "NpcHandler.h"
#include "VertexMap.hpp"
#include "ResourceHandler.h"
#include "Player.hpp"

class World
{
public:
    World();

    void draw(sf::RenderWindow &window);

    //returns the time it took for the player's action to complete
    int update(sf::Keyboard::Key key);

    bool isWalkable(int x, int y);

    ResourceHandler<sf::Texture, TileSets::ID> tileSets;
    ResourceHandler<sf::Font, Fonts::ID> fonts;

    VertexMap tileMap;
    Player player;
    NpcHandler npcHandler;
    ItemHandler itemHandler;
    Console console;

    std::vector<Menu> menus;

    sf::View gameView;
    sf::Vector2f tileSize;
};


#endif //HITMANRL_WORLD_H

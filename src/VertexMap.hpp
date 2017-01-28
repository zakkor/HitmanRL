#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED


#include <vector>
#include <iostream>
#include <string>
#include "ResourceIdentifier.hpp"
#include "ResourceHandler.h"

const int MAP_SIZE_X = 100;
const int MAP_SIZE_Y = 100;
const int TILE_SIZE_X = 64;
const int TILE_SIZE_Y = 64;

class VertexMap : public sf::Drawable, public sf::Transformable
{
public:
    VertexMap(ResourceHandler<sf::Texture, TileSets::ID> &tileSets);
    bool reload();
//    void draw(sf::RenderTarget& target, sf::RenderStates states, sf::Texture tileset) const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture tileSet_copy;
    std::vector< std::vector<TextureId> > tiles;
    sf::VertexArray vertexArray;
};

#endif // TILEMAP_HPP_INCLUDED
